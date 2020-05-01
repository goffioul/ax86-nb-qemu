/*
 * nb-qemu
 * 
 * Copyright (c) 2019 Michael Goffioul
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 */

#define LOG_TAG "libnb-qemu"
#define LOG_NDEBUG 0

#include <errno.h>
#include <string.h>
#include <log/log.h>
#include "JavaBridge.h"
#include "QemuAndroid.h"
#include "QemuCpu.h"
#include "QemuMemory.h"
#include "Trampoline.h"

static ffi_type *type_to_ffi(const char t)
{
  switch (t) {
    case 'c': return &ffi_type_sint8;
    case 'C': return &ffi_type_uint8;
    case 's': return &ffi_type_sint16;
    case 'S': return &ffi_type_uint16;
    case 'i': return &ffi_type_sint32;
    case 'I': return &ffi_type_uint32;
    case 'l': return &ffi_type_sint64;
    case 'L': return &ffi_type_uint64;
    case 'f': return &ffi_type_float;
    case 'd': return &ffi_type_double;
    case 'p': return &ffi_type_pointer;
    case 'v': return &ffi_type_void;
    default:
        ALOGE("Unsupported type: %c", t);
        return nullptr;
  }
}

static char jni_to_type(const char t)
{
  switch (t) {
    case 'Z': return 'C';
    case 'B': return 'c';
    case 'C': return 'S';
    case 'S': return 's';
    case 'I': return 'i';
    case 'J': return 'l';
    case 'F': return 'f';
    case 'D': return 'd';
    case 'L': return 'p';
    case 'V': return 'v';
    default:
        ALOGE("Unsupported JNI type: %c", t);
        return '?';
  }
}

static std::string shorty_to_signature(const std::string& shorty)
{
  std::string signature(shorty.length() + 2, ' ');

  signature[0] = jni_to_type(shorty[0]);
  signature[1] = signature[2] = 'p';
  for (int i = 1; i < shorty.length(); i++)
    signature[i+2] = jni_to_type(shorty[i]);

  return signature;
}

Trampoline::Trampoline(const std::string& name, uint32_t address, const std::string& signature)
     : name_(name),
       address_(address),
       signature_(signature),
       host_address_(0),
       closure_(nullptr),
       rtype_(nullptr),
       argtypes_(nullptr),
       nargs_(0),
       nstackargs_(0),
       stacksize_(0),
       stackoffsets_(nullptr)

{
  void *code_address = nullptr;

#define ALIGN_DWORD(x) ((x+7)&(~7))

  closure_ = reinterpret_cast<ffi_closure *>(ffi_closure_alloc(sizeof(ffi_closure), &code_address));
  if (closure_) {
      if (! signature.empty()) {
          nargs_ = signature.length() - 1;
          rtype_ = type_to_ffi(signature[0]);
          if (! rtype_)
            return;
          argtypes_ = reinterpret_cast<ffi_type **>(calloc(sizeof(ffi_type *), nargs_));
          for (int i = 0, nregs = 4; i < nargs_; i++) {
              argtypes_[i] = type_to_ffi(signature[i+1]);
              if (! argtypes_[i])
                return;
              // Check valid size and attempt to use register(s)
              switch (argtypes_[i]->size) {
                  case 1:
                  case 2:
                  case 4:
                    if (nregs) {
                        nregs--;
                        continue;
                    }
                    break;
                  case 8:
                    if (nregs >= 2) {
                        nregs = nregs == 3 ? 2 : nregs;
                        nregs -= 2;
                        continue;
                    }
                    nregs = 0;
                    break;
                  default:
                    ALOGE("Unsupported argument size: %d", argtypes_[i]->size);
                    return;
              }
              // Argument must be passed in the stack
              if (! stackoffsets_)
                stackoffsets_ = reinterpret_cast<int *>(calloc(sizeof(int), nargs_ - i));
              // Double-word sized arguments must be double-word aligned in the stack
              if (argtypes_[i]->size == 8)
                stacksize_ = ALIGN_DWORD(stacksize_);
              // Add argument to the stack
              stackoffsets_[nstackargs_] = stacksize_;
              nstackargs_++;
              stacksize_ += argtypes_[i]->size == 8 ? 8 : 4;
          }
          // The whole stack of arguments must be double-word aligned
          if (stacksize_) {
              stacksize_ = ALIGN_DWORD(stacksize_);
          }
      }
      else {
          ALOGE("Cannot create trampoline for unknown function: %s", name.c_str());
      }

      if (rtype_) {
          if (ffi_prep_cif(&cif_, FFI_DEFAULT_ABI, nargs_, rtype_, argtypes_) == FFI_OK) {
              if (ffi_prep_closure_loc(closure_, &cif_, Trampoline::call_trampoline, this, code_address) == FFI_OK) {
                  host_address_ = code_address;
              }
          }
      }
  }
}

Trampoline::~Trampoline()
{
  ffi_closure_free(closure_);
  free(argtypes_);
  free(stackoffsets_);
}

void *Trampoline::get_handle() const
{
  return reinterpret_cast<void *>(host_address_);
}

void Trampoline::call_trampoline(ffi_cif *cif, void *ret, void **args, void *self)
{
  reinterpret_cast<Trampoline *>(self)->call(ret, args);
}

void Trampoline::call(void *ret, void **args)
{
  ALOGV("Trampoline[%s] -- START", name_.c_str());

  uint32_t regs[4] = { 0, 0, 0, 0 };
  char *stack = nullptr;
  int rindex = 0;
  int nregargs = nargs_ - nstackargs_;

  if (stacksize_) {
      stack = reinterpret_cast<char *>(calloc(stacksize_, 1));
      for (int i = nregargs; i < nargs_; i++) {
          void *arg = get_call_argument(i, args[i]);
          if (argtypes_[i]->size <= 4)
            *(uint32_t*)(&stack[stackoffsets_[i - nregargs]]) = *(uint32_t *)arg;
          else
            *(uint64_t*)(&stack[stackoffsets_[i - nregargs]]) = *(uint64_t *)arg;
      }
  }

  for (int i = 0; i < nregargs; i++) {
      void *arg = get_call_argument(i, args[i]);
      if (argtypes_[i]->size <= 4)
        regs[rindex++] = *(uint32_t *)arg;
      else {
          rindex = rindex ? 2 : 0;
          *(uint64_t *)(&regs[rindex]) = *(uint64_t *)arg;
          rindex += 2;
      }
  }

  if (rtype_->size == 8) {
      uint64_t result = QemuCpu::get()->call64(address_, regs[0], regs[1], regs[2], regs[3], stack, stacksize_);

      ALOGV("Trampoline[%s] -- END => %016llx", name_.c_str(), result);
      *((uint64_t *)ret) = result;
  }
  else {
      uint32_t result = QemuCpu::get()->call(address_, regs[0], regs[1], regs[2], regs[3], stack, stacksize_);

      if (rtype_ == &ffi_type_void) {
          ALOGV("Trampoline[%s] -- END", name_.c_str());
      }
      else {
          ALOGV("Trampoline[%s] -- END => %08x [%d]", name_.c_str(), result, rtype_->size);
          switch (rtype_->size) {
            case 1:
              *((uint8_t *)ret) = result & 0xff;
              break;
            case 2:
              *((uint16_t *)ret) = result & 0xffff;
              break;
            default:
              *((uint32_t *)ret) = result;
              break;
          }
      }
  }

  free(stack);
}

void *Trampoline::get_call_argument(int index, void *arg)
{
  return arg;
}

JNITrampoline::JNITrampoline(const std::string& name, uint32_t address, const std::string& shorty)
     : Trampoline(name, address, shorty_to_signature(shorty)),
       shorty_(shorty)
{
}

void *JNITrampoline::get_call_argument(int index, void *arg)
{
  switch (index) {
    case 0:
      return &JavaBridge::wrap_jni_env(*(JNIEnv **)arg);
    default:
      return Trampoline::get_call_argument(index, arg);
  }
}

JNILoadTrampoline::JNILoadTrampoline(const std::string& name, uint32_t address)
     : Trampoline(name, address, name == "JNI_OnLoad" ? "ipp" : "vpp")
{
}

void *JNILoadTrampoline::get_call_argument(int index, void *arg)
{
  switch (index) {
    case 0:
      return &JavaBridge::wrap_java_vm(*(JavaVM **)arg);
    default:
      return Trampoline::get_call_argument(index, arg);
  }
}

#include <android/native_activity.h>

#define CALLBACK_ONSTART                        0
#define CALLBACK_ONRESUME                       1
#define CALLBACK_ONSAVEINSTANCESTATE            2
#define CALLBACK_ONPAUSE                        3
#define CALLBACK_ONSTOP                         4
#define CALLBACK_ONDESTROY                      5
#define CALLBACK_ONWINDOWFOCUSCHANGED           6
#define CALLBACK_ONNATIVEWINDOWCREATED          7
#define CALLBACK_ONNATIVEWINDOWRESIZED          8
#define CALLBACK_ONNATIVEWINDOWREDRAWNEEDED     9
#define CALLBACK_ONNATIVEWINDOWDESTROYED        10
#define CALLBACK_ONINPUTQUEUECREATED            11
#define CALLBACK_ONINPUTQUEUEDESTROYED          12
#define CALLBACK_ONCONTENTRECTCHANGED           13
#define CALLBACK_ONCONFIGURATIONCHANGED         14
#define CALLBACK_ONLOWMEMORY                    15

struct GuestNativeActivity : public ANativeActivity {
    ANativeActivity *native_;
    ANativeActivityCallbacks callbacks_;
};

static uint32_t GuestNativeActivity_getCallback(ANativeActivity *activity, int index)
{
  QemuMemory::Region<GuestNativeActivity> guest_activity((uint32_t) activity->instance);
  return (uint32_t) ((void **) guest_activity.get()->callbacks)[index];
}

#define GNA_CALLBACK(name, index) \
static void GuestNativeActivity_ ## name (ANativeActivity *activity) \
{ \
  uint32_t callback = GuestNativeActivity_getCallback(activity, index); \
  if (callback) { \
      ALOGI(#name); \
      QemuCpu::get()->call(callback, (uint32_t) activity->instance); \
  } \
}

#define GNA_CALLBACK_ARG(name, T, index) \
static void GuestNativeActivity_ ## name (ANativeActivity *activity, T arg) \
{ \
  uint32_t callback = GuestNativeActivity_getCallback(activity, index); \
  if (callback) { \
      ALOGI(#name); \
      QemuCpu::get()->call(callback, (uint32_t) activity->instance, (uint32_t) arg); \
  } \
}

GNA_CALLBACK(onStart, CALLBACK_ONSTART)
GNA_CALLBACK(onResume, CALLBACK_ONRESUME)
GNA_CALLBACK(onPause, CALLBACK_ONPAUSE)
GNA_CALLBACK(onStop, CALLBACK_ONSTOP)
GNA_CALLBACK_ARG(onWindowFocusChanged, int, CALLBACK_ONWINDOWFOCUSCHANGED)
GNA_CALLBACK_ARG(onNativeWindowCreated, ANativeWindow*, CALLBACK_ONNATIVEWINDOWCREATED)
GNA_CALLBACK_ARG(onNativeWindowResized, ANativeWindow*, CALLBACK_ONNATIVEWINDOWRESIZED)
GNA_CALLBACK_ARG(onNativeWindowRedrawNeeded, ANativeWindow*, CALLBACK_ONNATIVEWINDOWREDRAWNEEDED)
GNA_CALLBACK_ARG(onNativeWindowDestroyed, ANativeWindow*, CALLBACK_ONNATIVEWINDOWDESTROYED)
GNA_CALLBACK_ARG(onInputQueueCreated, AInputQueue*, CALLBACK_ONINPUTQUEUECREATED)
GNA_CALLBACK_ARG(onInputQueueDestroyed, AInputQueue*, CALLBACK_ONINPUTQUEUEDESTROYED)
GNA_CALLBACK_ARG(onContentRectChanged, const ARect*, CALLBACK_ONCONTENTRECTCHANGED)
GNA_CALLBACK(onConfigurationChanged, CALLBACK_ONCONFIGURATIONCHANGED)
GNA_CALLBACK(onLowMemory, CALLBACK_ONLOWMEMORY)

static void* GuestNativeActivity_onSaveInstanceState(ANativeActivity *activity, size_t *outSize)
{
  uint32_t callback = GuestNativeActivity_getCallback(activity, CALLBACK_ONSAVEINSTANCESTATE);
  if (callback) {
      ALOGW("GuestNativeActivity_onSaveInstanceState: ignoring for the time being");
      // QemuCpu::get()->call(callback, (uint32_t) activity->instance, (uint32_t) arg);
  }
  return nullptr;
}

static void GuestNativeActivity_onDestroy(ANativeActivity *activity)
{
  uint32_t callback = GuestNativeActivity_getCallback(activity, CALLBACK_ONDESTROY);
  if (callback) {
      ALOGI("GuestNativeActivity_onDestroy");
      QemuCpu::get()->call(callback, (uint32_t) activity->instance);
  }
  qemu_android_free((uint32_t) activity->instance);
  activity->instance = nullptr;
}

NativeActivityTrampoline::NativeActivityTrampoline(const std::string& name, uint32_t address)
     : Trampoline(name, address, "vppI")
{
}

void NativeActivityTrampoline::call(void *ret, void **args)
{
  ANativeActivity *host_activity = *(ANativeActivity **)args[0];
  uint32_t guest_activity_p = qemu_android_malloc(sizeof(GuestNativeActivity));

  // Setup host ANativeActivity
  host_activity->instance = (void *) guest_activity_p;
  host_activity->callbacks->onStart = GuestNativeActivity_onStart;
  host_activity->callbacks->onResume = GuestNativeActivity_onResume;
  host_activity->callbacks->onSaveInstanceState = GuestNativeActivity_onSaveInstanceState;
  host_activity->callbacks->onPause = GuestNativeActivity_onPause;
  host_activity->callbacks->onStop = GuestNativeActivity_onStop;
  host_activity->callbacks->onDestroy = GuestNativeActivity_onDestroy;
  host_activity->callbacks->onWindowFocusChanged = GuestNativeActivity_onWindowFocusChanged;
  host_activity->callbacks->onNativeWindowCreated = GuestNativeActivity_onNativeWindowCreated;
  host_activity->callbacks->onNativeWindowResized = GuestNativeActivity_onNativeWindowResized;
  host_activity->callbacks->onNativeWindowRedrawNeeded = GuestNativeActivity_onNativeWindowRedrawNeeded;
  host_activity->callbacks->onNativeWindowDestroyed = GuestNativeActivity_onNativeWindowDestroyed;
  host_activity->callbacks->onInputQueueCreated = GuestNativeActivity_onInputQueueCreated;
  host_activity->callbacks->onInputQueueDestroyed = GuestNativeActivity_onInputQueueDestroyed;
  host_activity->callbacks->onContentRectChanged = GuestNativeActivity_onContentRectChanged;
  host_activity->callbacks->onConfigurationChanged = GuestNativeActivity_onConfigurationChanged;
  host_activity->callbacks->onLowMemory = GuestNativeActivity_onLowMemory;

  // Setup guest ANativeActivity
  {
      QemuMemory::Region<GuestNativeActivity> guest_activity_r(guest_activity_p);
      GuestNativeActivity *guest_activity = guest_activity_r.get();

      guest_activity->assetManager = host_activity->assetManager;
      guest_activity->callbacks = (ANativeActivityCallbacks *) qemu_android_h2g(&guest_activity->callbacks_);
      guest_activity->clazz = host_activity->clazz;
      guest_activity->env = (JNIEnv *) JavaBridge::wrap_jni_env(host_activity->env);
      guest_activity->externalDataPath = (const char *) qemu_android_h2g((void *) host_activity->externalDataPath);
      guest_activity->internalDataPath = (const char *) qemu_android_h2g((void *) host_activity->internalDataPath);
      guest_activity->obbPath = (const char *) qemu_android_h2g((void *) host_activity->obbPath);
      guest_activity->sdkVersion = host_activity->sdkVersion;
      guest_activity->vm = (JavaVM *) JavaBridge::wrap_java_vm(host_activity->vm);

      guest_activity->native_ = host_activity;
      bzero(&guest_activity->callbacks_, sizeof(ANativeActivityCallbacks));
  }

  // Call trampoline
  void *new_args[3] = { &guest_activity_p, args[1], args[2] };
  Trampoline::call(ret, new_args);
}
