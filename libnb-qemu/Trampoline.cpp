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
#include "QemuCpu.h"
#include "Trampoline.h"

static ffi_type *jni_to_ffi(char t)
{
  switch (t) {
    case 'Z': return &ffi_type_uint8;
    case 'B': return &ffi_type_sint8;
    case 'C': return &ffi_type_uint16;
    case 'S': return &ffi_type_sint16;
    case 'I': return &ffi_type_sint32;
    case 'J': return &ffi_type_sint64;
    case 'F': return &ffi_type_float;
    case 'D': return &ffi_type_double;
    case 'L': return &ffi_type_pointer;
    case 'V': return &ffi_type_void;
    default:
        ALOGE("Unsupported JNI type: %c", t);
        return nullptr;
  }
}

Trampoline::Trampoline(const std::string& name, uint32_t address, const std::string& shorty, bool jni)
     : name_(name),
       address_(address),
       shorty_(shorty),
       jni_(jni),
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
      if (jni) {
          // First character in shorty is always the return value, plus the 2 mandatory JNI arguments
          // => shorty.length() - 1 + 2
          nargs_ = shorty.length() + 1;
          rtype_ = jni_to_ffi(shorty[0]);
          if (! rtype_)
            return;
          argtypes_ = reinterpret_cast<ffi_type **>(calloc(sizeof(ffi_type *), nargs_));
          // JNI function signature always is (JNIEnv*, jclass/jobject, ...)
          argtypes_[0] = &ffi_type_pointer;
          argtypes_[1] = &ffi_type_pointer;
          // Parse shorty to precompute argument type and calling convention (only 2 registers left,
          // the first 2 being used by the mandatory JNI arguments)
          for (int i = 2, nregs = 2; i < nargs_; i++) {
              argtypes_[i] = jni_to_ffi(shorty[i-1]);
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
                    if (nregs == 2) {
                        nregs = 0;
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
      else if (name == "JNI_OnLoad") {
          rtype_ = &ffi_type_sint;
          argtypes_ = reinterpret_cast<ffi_type **>(calloc(sizeof(ffi_type *), 2));
          argtypes_[0] = &ffi_type_pointer;
          argtypes_[1] = &ffi_type_pointer;
          nargs_ = 2;
      }
      else if (name == "JNI_OnUnload") {
          rtype_ = &ffi_type_void;
          argtypes_ = reinterpret_cast<ffi_type **>(calloc(sizeof(ffi_type *), 2));
          argtypes_[0] = &ffi_type_pointer;
          argtypes_[1] = &ffi_type_pointer;
          nargs_ = 2;
      }
      else if (name == "ANativeActivity_onCreate") {
          rtype_ = &ffi_type_void;
          argtypes_ = reinterpret_cast<ffi_type **>(calloc(sizeof(ffi_type *), 3));
          argtypes_[0] = &ffi_type_pointer;
          argtypes_[1] = &ffi_type_pointer;
          argtypes_[2] = &ffi_type_ulong;
          nargs_ = 3;
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
          if (argtypes_[i]->size <= 4)
            *(uint32_t*)(&stack[stackoffsets_[i - nregargs]]) = *(uint32_t *)args[i];
          else
            *(uint64_t*)(&stack[stackoffsets_[i - nregargs]]) = *(uint64_t *)args[i];
      }
  }

  for (int i = 0; i < nregargs; i++) {
      if (jni_ && rindex == 0)
        regs[rindex++] = JavaBridge::wrap_jni_env(*(JNIEnv **)args[i]);
      else if (rindex == 0 && (name_ == "JNI_OnLoad" || name_ == "JNI_OnUnload"))
        regs[rindex++] = JavaBridge::wrap_java_vm(*(JavaVM **)args[i]);
      else if (argtypes_[i]->size <= 4)
        regs[rindex++] = *(uint32_t *)args[i];
      else {
          rindex = rindex ? 2 : 0;
          *(uint64_t *)(&regs[rindex]) = *(uint64_t *)args[i];
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
