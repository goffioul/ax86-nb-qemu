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
