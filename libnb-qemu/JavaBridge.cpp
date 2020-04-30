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
#include <map>
#include <memory>
#include <sstream>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <log/log.h>
#include "JavaBridge.h"
#include "QemuCore.h"
#include "QemuMemory.h"
#include "Trampoline.h"

thread_local JNIEnv *jni_env_ = nullptr;
static JavaVM *java_vm_ = nullptr;
static const android::NativeBridgeRuntimeCallbacks *runtime_ = nullptr;

static uint32_t guest_jni_env_;
static uint32_t guest_java_vm_;

static std::map<std::string, std::shared_ptr<Trampoline>> native_methods_;

#define ALIGN_DWORD(x) ((x+7)&(~7))

typedef int32_t(*wrapper_fcn_t)(void *cpu_env,
                                uint32_t arg1, uint32_t arg2, uint32_t arg3,
                                uint32_t arg4, uint32_t arg5);

#define WRAPPER(name) wrap_##name
#define DEFINE_WRAPPER(name) \
static int32_t WRAPPER(name)(void *cpu_env, \
                             uint32_t arg1, uint32_t arg2, uint32_t arg3, \
                             uint32_t arg4, uint32_t arg5)

int va_args_size(const char *sig, uint32_t start)
{
  uint32_t end = start;
  for (int i = 0; sig[i]; i++) {
      if (sig[i] == 'J' || sig[i] == 'D') {
          end = ALIGN_DWORD(end);
          end += 8;
      }
      else
        end += 4;
  }
  return (end - start);
}

void unpack_va_args(jmethodID mID, jvalue **jargs, uint32_t start)
{
  const char *shorty = runtime_->getMethodShorty(jni_env_, mID);
  int nargs = strlen(shorty) - 1;
  int size = va_args_size(&shorty[1], start);
  QemuMemory::Region<char> args(start, size);
  uint32_t current = start;

#define DATA (&args[current-start])
#define SKIP(n) current += n
#define REALIGN current = ALIGN_DWORD(current)

  *jargs = reinterpret_cast<jvalue *>(calloc(sizeof(jvalue), nargs));
  for (int i = 0; i < nargs; i++) {
      switch (shorty[i+1]) {
          case 'Z':
            (*jargs)[i].z = *(jboolean*)DATA;
            SKIP(4);
            ALOGV("  [z]: %s", (*jargs)[i].z ? "true" : "false");
            break;
          case 'B':
            (*jargs)[i].b = *(jbyte*)DATA;
            SKIP(4);
            ALOGV("  [b]: %02x", (*jargs)[i].b);
            break;
          case 'C':
            (*jargs)[i].c = *(jchar*)DATA;
            SKIP(4);
            ALOGV("  [c]: %04x", (*jargs)[i].c);
            break;
          case 'S':
            (*jargs)[i].s = *(jshort*)DATA;
            SKIP(4);
            ALOGV("  [s]: %d", (*jargs)[i].s);
            break;
          case 'I':
            (*jargs)[i].i = *(jint*)DATA;
            SKIP(4);
            ALOGV("  [i]: %d", (*jargs)[i].i);
            break;
          case 'J':
            REALIGN;
            (*jargs)[i].j = *(jlong*)DATA;
            SKIP(8);
            ALOGV("  [j]: %lld", (*jargs)[i].j);
            break;
          case 'F':
            (*jargs)[i].f = *(jfloat*)DATA;
            SKIP(4);
            ALOGV("  [f]: %f", (*jargs)[i].f);
            break;
          case 'D':
            REALIGN;
            (*jargs)[i].d = *(jdouble*)DATA;
            SKIP(8);
            ALOGV("  [d]: %g", (*jargs)[i].d);
            break;
          default:
            (*jargs)[i].l = *(jobject*)DATA;
            SKIP(4);
            ALOGV("  [l]: %p", (*jargs)[i].l);
            break;
      }
  }

#undef DATA
#undef SKIP
#undef REALIGN

}

std::string unicode_to_string(const jchar *s, jsize len)
{
  std::string ss(len, ' ');
  for (int i = 0; i < len; i++) {
      ss[i] = (char)(s[i]&0xff);
  }
  return ss;
}

std::string get_class_name(JNIEnv *env, jclass cls)
{
  jclass clsCls = env->GetObjectClass(cls);
  jmethodID mID = env->GetMethodID(clsCls, "getName", "()Ljava/lang/String;");
  jstring clsName = reinterpret_cast<jstring>(env->CallObjectMethod(cls, mID));
  const char *clsNameS = env->GetStringUTFChars(clsName, nullptr);
  std::string result(clsNameS);
  env->ReleaseStringUTFChars(clsName, clsNameS);
  return result;
}

DEFINE_WRAPPER(GetVersion)
{
  return jni_env_->GetVersion();
}

DEFINE_WRAPPER(DefineClass)
{
  QemuMemory::String name(arg1);
  QemuMemory::Region<jbyte> buf(arg3, arg4);
  jclass cls = jni_env_->DefineClass(name.c_str(), reinterpret_cast<jobject>(arg2), buf.get(), arg4);
  ALOGV("DefineClass(%s, %p, %p, %d) => %p", name.c_str(), reinterpret_cast<jobject>(arg2), buf.get(), arg4, cls);
  QemuMemory::memcpy(arg5, &cls, sizeof(jclass));
  return 0;
}

DEFINE_WRAPPER(FindClass)
{
  QemuMemory::String name(arg1);
  jclass cls = jni_env_->FindClass(name.c_str());
  ALOGV("FindClass(%s) => %p", name.c_str(), cls);
  QemuMemory::memcpy(arg2, &cls, sizeof(jclass));
  return 0;
}

DEFINE_WRAPPER(FromReflectedMethod)
{
  jmethodID mID = jni_env_->FromReflectedMethod(reinterpret_cast<jobject>(arg1));
  ALOGV("FromReflectedMethod(%p) => %p", reinterpret_cast<jobject>(arg1), mID);
  QemuMemory::memcpy(arg2, &mID, sizeof(jmethodID));
  return 0;
}

DEFINE_WRAPPER(FromReflectedField)
{
  jfieldID fID = jni_env_->FromReflectedField(reinterpret_cast<jobject>(arg1));
  ALOGV("FromReflectedField(%p) => %p", reinterpret_cast<jobject>(arg1), fID);
  QemuMemory::memcpy(arg2, &fID, sizeof(jfieldID));
  return 0;
}

DEFINE_WRAPPER(ToReflectedMethod)
{
  jobject ret = jni_env_->ToReflectedMethod(reinterpret_cast<jclass>(arg1), reinterpret_cast<jmethodID>(arg2), arg3);
  ALOGV("ToReflectedMethod(%p, %p, %d) => %p", reinterpret_cast<jclass>(arg1), reinterpret_cast<jmethodID>(arg2), arg3, ret);
  QemuMemory::memcpy(arg4, &ret, sizeof(jobject));
  return 0;
}

DEFINE_WRAPPER(GetSuperclass)
{
  jclass cls = jni_env_->GetSuperclass(reinterpret_cast<jclass>(arg1));
  ALOGV("GetSuperclass(%p) => %p", reinterpret_cast<jclass>(arg1), cls);
  QemuMemory::memcpy(arg2, &cls, sizeof(jclass));
  return 0;
}

DEFINE_WRAPPER(IsAssignableFrom)
{
  jboolean ret = jni_env_->IsAssignableFrom(reinterpret_cast<jclass>(arg1), reinterpret_cast<jclass>(arg2));
  ALOGV("IsAssignableFrom(%p, %p) => %d", reinterpret_cast<jclass>(arg1), reinterpret_cast<jclass>(arg2), ret);
  return ret;
}

DEFINE_WRAPPER(ToReflectedField)
{
  jobject ret = jni_env_->ToReflectedField(reinterpret_cast<jclass>(arg1), reinterpret_cast<jfieldID>(arg2), arg3);
  ALOGV("ToReflectedField(%p, %p, %d) => %p", reinterpret_cast<jclass>(arg1), reinterpret_cast<jfieldID>(arg2), arg3, ret);
  QemuMemory::memcpy(arg4, &ret, sizeof(jobject));
  return 0;
}

DEFINE_WRAPPER(Throw)
{
  jint result = jni_env_->Throw(reinterpret_cast<jthrowable>(arg1));
  ALOGV("Throw(%p) => %d", reinterpret_cast<jthrowable>(arg1), result);
  return result;
}

DEFINE_WRAPPER(ThrowNew)
{
  QemuMemory::String message(arg2);
  jint result = jni_env_->ThrowNew(reinterpret_cast<jclass>(arg1), message.c_str());
  ALOGV("ThrowNew(%p, %s) => %d", reinterpret_cast<jclass>(arg1), message.c_str(), result);
  return result;
}

DEFINE_WRAPPER(ExceptionOccurred)
{
  jthrowable thr = jni_env_->ExceptionOccurred();
  ALOGV("ExceptionOccurred => %p", thr);
  QemuMemory::memcpy(arg1, &thr, sizeof(jthrowable));
  return 0;
}

DEFINE_WRAPPER(ExceptionDescribe)
{
  jni_env_->ExceptionDescribe();
  ALOGV("ExceptionDescribe");
  return 0;
}

DEFINE_WRAPPER(ExceptionClear)
{
  jni_env_->ExceptionClear();
  ALOGV("ExceptionClear");
  return 0;
}

DEFINE_WRAPPER(FatalError)
{
  QemuMemory::String msg(arg1);
  ALOGV("FatalError(%s)", msg.c_str());
  jni_env_->FatalError(msg.c_str());
  return 0;
}

DEFINE_WRAPPER(PushLocalFrame)
{
  ALOGV("PushLocalFrame(%d)", arg1);
  return jni_env_->PushLocalFrame(arg1);
}

DEFINE_WRAPPER(PopLocalFrame)
{
  jobject obj = jni_env_->PopLocalFrame(reinterpret_cast<jobject>(arg1));
  ALOGV("PopLocalFrame(%p) => %p", reinterpret_cast<jobject>(arg1), obj);
  QemuMemory::memcpy(arg2, &obj, sizeof(jobject));
  return 0;
}

DEFINE_WRAPPER(NewGlobalRef)
{
  jobject obj = jni_env_->NewGlobalRef(reinterpret_cast<jobject>(arg1));
  ALOGV("NewGlobalRef(%p) => %p", reinterpret_cast<jobject>(arg1), obj);
  QemuMemory::memcpy(arg2, &obj, sizeof(jobject));
  return 0;
}

DEFINE_WRAPPER(DeleteGlobalRef)
{
  jni_env_->DeleteGlobalRef(reinterpret_cast<jobject>(arg1));
  ALOGV("DeleteGlobalRef(%p)", reinterpret_cast<jobject>(arg1));
  return 0;
}

DEFINE_WRAPPER(DeleteLocalRef)
{
  jni_env_->DeleteLocalRef(reinterpret_cast<jobject>(arg1));
  ALOGV("DeleteLocalRef(%p)", reinterpret_cast<jobject>(arg1));
  return 0;
}

DEFINE_WRAPPER(IsSameObject)
{
  jboolean ret = jni_env_->IsSameObject(reinterpret_cast<jobject>(arg1), reinterpret_cast<jobject>(arg2));
  ALOGV("IsSameObject(%p, %p) => %d", reinterpret_cast<jobject>(arg1), reinterpret_cast<jobject>(arg2), ret);
  return ret;
}

DEFINE_WRAPPER(NewLocalRef)
{
  jobject obj = jni_env_->NewLocalRef(reinterpret_cast<jobject>(arg1));
  ALOGV("NewLocalRef(%p) => %p", reinterpret_cast<jobject>(arg1), obj);
  QemuMemory::memcpy(arg2, &obj, sizeof(jobject));
  return 0;
}

DEFINE_WRAPPER(EnsureLocalCapacity)
{
  jint ret = jni_env_->EnsureLocalCapacity(arg1);
  ALOGV("EnsureLocalCapacity(%d) => %d", arg1, ret);
  return ret;
}

DEFINE_WRAPPER(AllocObject)
{
  jobject obj = jni_env_->AllocObject(reinterpret_cast<jclass>(arg1));
  ALOGV("AllocObject(%p) => %p", reinterpret_cast<jclass>(arg1), obj);
  QemuMemory::memcpy(arg2, &obj, sizeof(jobject));
  return 0;
}

DEFINE_WRAPPER(NewObjectV)
{
  jclass cls = reinterpret_cast<jclass>(arg1);
  jmethodID mID = reinterpret_cast<jmethodID>(arg2);
  jvalue *jargs = nullptr;
  ALOGV("NewObjectV(%p, %p, ...) -- START", cls, mID);
  unpack_va_args(mID, &jargs, arg3);
  jobject obj = jni_env_->NewObjectA(cls, mID, jargs);
  ALOGV("NewObjectV(%p, %p, ...) -- END => %p", cls, mID, obj);
  QemuMemory::memcpy(arg4, &obj, sizeof(jobject));
  free(jargs);
  return 0;
}

DEFINE_WRAPPER(NewObjectA)
{
  jclass cls = reinterpret_cast<jclass>(arg1);
  jmethodID mID = reinterpret_cast<jmethodID>(arg2);
  int nargs = strlen(runtime_->getMethodShorty(jni_env_, mID)) - 1;
  QemuMemory::Region<jvalue> args(arg3, nargs);
  ALOGV("NewObjectA(%p, %p, ...) -- START", cls, mID);
  jobject obj = jni_env_->NewObjectA(cls, mID, args.get());
  ALOGV("NewObjectA(%p, %p, ...) -- END => %p", cls, mID, obj);
  QemuMemory::memcpy(arg4, &obj, sizeof(jobject));
  return 0;
}

DEFINE_WRAPPER(GetObjectClass)
{
  jclass cls = jni_env_->GetObjectClass(reinterpret_cast<jobject>(arg1));
  ALOGV("GetObjectClass(%p) => %p", reinterpret_cast<jobject>(arg1), cls);
  QemuMemory::memcpy(arg2, &cls, sizeof(jclass));
  return 0;
}

DEFINE_WRAPPER(IsInstanceOf)
{
  jboolean ret = jni_env_->IsInstanceOf(reinterpret_cast<jobject>(arg1), reinterpret_cast<jclass>(arg2));
  ALOGV("IsInstanceOf(%p, %p) => %d", reinterpret_cast<jobject>(arg1), reinterpret_cast<jclass>(arg2), ret);
  return ret;
}

DEFINE_WRAPPER(GetMethodID)
{
  QemuMemory::String name(arg2), sig(arg3);
  jmethodID mID = jni_env_->GetMethodID(reinterpret_cast<jclass>(arg1), name.c_str(), sig.c_str());
  ALOGV("GetMethodID(%p, %s, %s) => %p", reinterpret_cast<jclass>(arg1), name.c_str(), sig.c_str(), mID);
  QemuMemory::memcpy(arg4, &mID, sizeof(jmethodID));
  return 0;
}

#define CALL_METHOD_WRAPPER(name, type, format) \
DEFINE_WRAPPER(Call##name##MethodV) \
{ \
  jobject obj = reinterpret_cast<jobject>(arg1); \
  jmethodID mID = reinterpret_cast<jmethodID>(arg2); \
  jvalue *jargs = nullptr; \
  ALOGV("Call" #name "MethodV(%p, %p, ...) -- START", obj, mID); \
  unpack_va_args(mID, &jargs, arg3); \
  type ret = jni_env_->Call##name##MethodA(obj, mID, jargs); \
  ALOGV("Call" #name "MethodV(%p, %p, ...) -- END => " #format, obj, mID, ret); \
  QemuMemory::memcpy(arg4, &ret, sizeof(type)); \
  free(jargs); \
  return 0; \
} \
 \
DEFINE_WRAPPER(Call##name##MethodA) \
{ \
  jobject obj = reinterpret_cast<jobject>(arg1); \
  jmethodID mID = reinterpret_cast<jmethodID>(arg2); \
  int nargs = strlen(runtime_->getMethodShorty(jni_env_, mID)) - 1; \
  QemuMemory::Region<jvalue> args(arg3, nargs); \
  ALOGV("Call" #name "MethodA(%p, %p, ...) -- START", obj, mID); \
  type ret = jni_env_->Call##name##MethodA(obj, mID, args.get()); \
  ALOGV("Call" #name "MethodA(%p, %p, ...) -- END => " #format, obj, mID, ret); \
  QemuMemory::memcpy(arg4, &ret, sizeof(type)); \
  return 0; \
}

#define CALL_VOID_METHOD_WRAPPER \
DEFINE_WRAPPER(CallVoidMethodV) \
{ \
  jobject obj = reinterpret_cast<jobject>(arg1); \
  jmethodID mID = reinterpret_cast<jmethodID>(arg2); \
  jvalue *jargs = nullptr; \
  ALOGV("CallVoidMethodV(%p, %p, ...) -- START", obj, mID); \
  unpack_va_args(mID, &jargs, arg3); \
  jni_env_->CallVoidMethodA(obj, mID, jargs); \
  ALOGV("CallVoidMethodV(%p, %p, ...) -- END", obj, mID); \
  free(jargs); \
  return 0; \
} \
 \
DEFINE_WRAPPER(CallVoidMethodA) \
{ \
  jobject obj = reinterpret_cast<jobject>(arg1); \
  jmethodID mID = reinterpret_cast<jmethodID>(arg2); \
  int nargs = strlen(runtime_->getMethodShorty(jni_env_, mID)) - 1; \
  QemuMemory::Region<jvalue> args(arg3, nargs); \
  ALOGV("CallVoidMethodA(%p, %p, ...) -- START", obj, mID); \
  jni_env_->CallVoidMethodA(obj, mID, args.get()); \
  ALOGV("CallVoidMethodA(%p, %p, ...) -- END", obj, mID); \
  return 0; \
}

CALL_METHOD_WRAPPER(Object, jobject, %p)
CALL_METHOD_WRAPPER(Boolean, jboolean, %d)
CALL_METHOD_WRAPPER(Byte, jbyte, %02x)
CALL_METHOD_WRAPPER(Char, jchar, %04x)
CALL_METHOD_WRAPPER(Short, jshort, %d)
CALL_METHOD_WRAPPER(Int, jint, %d)
CALL_METHOD_WRAPPER(Long, jlong, %lld)
CALL_METHOD_WRAPPER(Float, jfloat, %f)
CALL_METHOD_WRAPPER(Double, jdouble, %g)
CALL_VOID_METHOD_WRAPPER

#define CALL_NONVIRTUAL_METHOD_WRAPPER(name, type, format) \
DEFINE_WRAPPER(CallNonvirtual##name##MethodV) \
{ \
  jobject obj = reinterpret_cast<jobject>(arg1); \
  jclass cls = reinterpret_cast<jclass>(arg2); \
  jmethodID mID = reinterpret_cast<jmethodID>(arg3); \
  jvalue *jargs = nullptr; \
  ALOGV("CallNonvirtual" #name "MethodV(%p, %p, %p, ...) -- START", obj, cls, mID); \
  unpack_va_args(mID, &jargs, arg4); \
  type ret = jni_env_->CallNonvirtual##name##MethodA(obj, cls, mID, jargs); \
  ALOGV("CallNonvirtual" #name "MethodV(%p, %p, %p, ...) -- END => " #format, obj, cls, mID, ret); \
  QemuMemory::memcpy(arg5, &ret, sizeof(type)); \
  free(jargs); \
  return 0; \
} \
 \
DEFINE_WRAPPER(CallNonvirtual##name##MethodA) \
{ \
  jobject obj = reinterpret_cast<jobject>(arg1); \
  jclass cls = reinterpret_cast<jclass>(arg2); \
  jmethodID mID = reinterpret_cast<jmethodID>(arg3); \
  int nargs = strlen(runtime_->getMethodShorty(jni_env_, mID)) - 1; \
  QemuMemory::Region<jvalue> args(arg4, nargs); \
  ALOGV("CallNonvirtual" #name "MethodA(%p, %p, %p, ...) -- START", obj, cls, mID); \
  type ret = jni_env_->CallNonvirtual##name##MethodA(obj, cls, mID, args.get()); \
  ALOGV("CallNonvirtual" #name "MethodA(%p, %p, %p, ...) -- END => " #format, obj, cls, mID, ret); \
  QemuMemory::memcpy(arg5, &ret, sizeof(type)); \
  return 0; \
}

#define CALL_NONVIRTUAL_VOID_METHOD_WRAPPER \
DEFINE_WRAPPER(CallNonvirtualVoidMethodV) \
{ \
  jobject obj = reinterpret_cast<jobject>(arg1); \
  jclass cls = reinterpret_cast<jclass>(arg2); \
  jmethodID mID = reinterpret_cast<jmethodID>(arg3); \
  jvalue *jargs = nullptr; \
  ALOGV("CallNonvirtualVoidMethodV(%p, %p, %p, ...) -- START", obj, cls, mID); \
  unpack_va_args(mID, &jargs, arg4); \
  jni_env_->CallNonvirtualVoidMethodA(obj, cls, mID, jargs); \
  ALOGV("CallNonvirtualVoidMethodV(%p, %p, %p, ...) -- END", obj, cls, mID); \
  free(jargs); \
  return 0; \
} \
 \
DEFINE_WRAPPER(CallNonvirtualVoidMethodA) \
{ \
  jobject obj = reinterpret_cast<jobject>(arg1); \
  jclass cls = reinterpret_cast<jclass>(arg2); \
  jmethodID mID = reinterpret_cast<jmethodID>(arg3); \
  int nargs = strlen(runtime_->getMethodShorty(jni_env_, mID)) - 1; \
  QemuMemory::Region<jvalue> args(arg4, nargs); \
  ALOGV("CallNonvirtualVoidMethodA(%p, %p, %p, ...) -- START", obj, cls, mID); \
  jni_env_->CallNonvirtualVoidMethodA(obj, cls, mID, args.get()); \
  ALOGV("CallNonvirtualVoidMethodA(%p, %p, %p, ...) -- END", obj, cls, mID); \
  return 0; \
}

CALL_NONVIRTUAL_METHOD_WRAPPER(Object, jobject, %p)
CALL_NONVIRTUAL_METHOD_WRAPPER(Boolean, jboolean, %d)
CALL_NONVIRTUAL_METHOD_WRAPPER(Byte, jbyte, %02x)
CALL_NONVIRTUAL_METHOD_WRAPPER(Char, jchar, %04x)
CALL_NONVIRTUAL_METHOD_WRAPPER(Short, jshort, %d)
CALL_NONVIRTUAL_METHOD_WRAPPER(Int, jint, %d)
CALL_NONVIRTUAL_METHOD_WRAPPER(Long, jlong, %lld)
CALL_NONVIRTUAL_METHOD_WRAPPER(Float, jfloat, %f)
CALL_NONVIRTUAL_METHOD_WRAPPER(Double, jdouble, %g)
CALL_NONVIRTUAL_VOID_METHOD_WRAPPER

DEFINE_WRAPPER(GetFieldID)
{
  QemuMemory::String name(arg2), sig(arg3);
  jfieldID fID = jni_env_->GetFieldID(reinterpret_cast<jclass>(arg1), name.c_str(), sig.c_str());
  ALOGV("GetFieldID(%p, %s, %s) => %p", reinterpret_cast<jclass>(arg1), name.c_str(), sig.c_str(), fID);
  QemuMemory::memcpy(arg4, &fID, sizeof(jfieldID));
  return 0;
}

#define GET_FIELD_WRAPPER(name, type, format) \
DEFINE_WRAPPER(Get##name##Field) \
{ \
  ALOGV("Get" #name "Field(%p, %p)", reinterpret_cast<jclass>(arg1), reinterpret_cast<jfieldID>(arg2)); \
  type value = jni_env_->Get##name##Field(reinterpret_cast<jobject>(arg1), reinterpret_cast<jfieldID>(arg2)); \
  ALOGV("Get" #name "Field(%p, %p) => " #format, reinterpret_cast<jclass>(arg1), reinterpret_cast<jfieldID>(arg2), value); \
  QemuMemory::memcpy(arg3, &value, sizeof(type)); \
  return 0; \
}

GET_FIELD_WRAPPER(Object, jobject, %p)
GET_FIELD_WRAPPER(Boolean, jboolean, %d)
GET_FIELD_WRAPPER(Byte, jbyte, %02x)
GET_FIELD_WRAPPER(Char, jchar, %04x)
GET_FIELD_WRAPPER(Short, jshort, %d)
GET_FIELD_WRAPPER(Int, jint, %d)
GET_FIELD_WRAPPER(Long, jlong, %lld)
GET_FIELD_WRAPPER(Float, jfloat, %f)
GET_FIELD_WRAPPER(Double, jdouble, %g)

#define SET_FIELD_WRAPPER(name, type, format) \
DEFINE_WRAPPER(Set##name##Field) \
{ \
  jobject obj = reinterpret_cast<jobject>(arg1); \
  jfieldID fID = reinterpret_cast<jfieldID>(arg2); \
  QemuMemory::Region<type> value(arg3); \
  jni_env_->Set##name##Field(obj, fID, *value.get()); \
  ALOGV("Set" #name "Field(%p, %p) <= " #format, obj, fID, *value.get()); \
  return 0; \
}

SET_FIELD_WRAPPER(Object, jobject, %p)
SET_FIELD_WRAPPER(Boolean, jboolean, %d)
SET_FIELD_WRAPPER(Byte, jbyte, %02x)
SET_FIELD_WRAPPER(Char, jchar, %04x)
SET_FIELD_WRAPPER(Short, jshort, %d)
SET_FIELD_WRAPPER(Int, jint, %d)
SET_FIELD_WRAPPER(Long, jlong, %lld)
SET_FIELD_WRAPPER(Float, jfloat, %f)
SET_FIELD_WRAPPER(Double, jdouble, %g)

DEFINE_WRAPPER(GetStaticMethodID)
{
  QemuMemory::String name(arg2), sig(arg3);
  jmethodID mID = jni_env_->GetStaticMethodID(reinterpret_cast<jclass>(arg1), name.c_str(), sig.c_str());
  ALOGV("GetStaticMethodID(%p, %s, %s) => %p", reinterpret_cast<jclass>(arg1), name.c_str(), sig.c_str(), mID);
  QemuMemory::memcpy(arg4, &mID, sizeof(jmethodID));
  return 0;
}

#define CALL_STATIC_METHOD_WRAPPER(name, type, format) \
DEFINE_WRAPPER(CallStatic##name##MethodV) \
{ \
  jclass cls = reinterpret_cast<jclass>(arg1); \
  jmethodID mID = reinterpret_cast<jmethodID>(arg2); \
  jvalue *jargs = nullptr; \
  ALOGV("CallStatic" #name "MethodV(%p, %p, ...) -- START", cls, mID); \
  unpack_va_args(mID, &jargs, arg3); \
  type ret = jni_env_->CallStatic##name##MethodA(cls, mID, jargs); \
  ALOGV("CallStatic" #name "MethodV(%p, %p, ...) -- END => " #format, cls, mID, ret); \
  QemuMemory::memcpy(arg4, &ret, sizeof(type)); \
  free(jargs); \
  return 0; \
} \
 \
DEFINE_WRAPPER(CallStatic##name##MethodA) \
{ \
  jclass cls = reinterpret_cast<jclass>(arg1); \
  jmethodID mID = reinterpret_cast<jmethodID>(arg2); \
  int nargs = strlen(runtime_->getMethodShorty(jni_env_, mID)) - 1; \
  QemuMemory::Region<jvalue> args(arg3, nargs); \
  ALOGV("CallStatic" #name "MethodA(%p, %p, ...) -- START", cls, mID); \
  type ret = jni_env_->CallStatic##name##MethodA(cls, mID, args.get()); \
  ALOGV("CallStatic" #name "MethodA(%p, %p, ...) -- END => " #format, cls, mID, ret); \
  QemuMemory::memcpy(arg4, &ret, sizeof(type)); \
  return 0; \
}

#define CALL_STATIC_VOID_METHOD_WRAPPER \
DEFINE_WRAPPER(CallStaticVoidMethodV) \
{ \
  jclass cls = reinterpret_cast<jclass>(arg1); \
  jmethodID mID = reinterpret_cast<jmethodID>(arg2); \
  jvalue *jargs = nullptr; \
  ALOGV("CallStaticVoidMethodV(%p, %p, ...) -- START", cls, mID); \
  unpack_va_args(mID, &jargs, arg3); \
  jni_env_->CallStaticVoidMethodA(cls, mID, jargs); \
  ALOGV("CallStaticVoidMethodV(%p, %p, ...) -- END", cls, mID); \
  free(jargs); \
  return 0; \
} \
 \
DEFINE_WRAPPER(CallStaticVoidMethodA) \
{ \
  jclass cls = reinterpret_cast<jclass>(arg1); \
  jmethodID mID = reinterpret_cast<jmethodID>(arg2); \
  int nargs = strlen(runtime_->getMethodShorty(jni_env_, mID)) - 1; \
  QemuMemory::Region<jvalue> args(arg3, nargs); \
  ALOGV("CallStaticVoidMethodA(%p, %p, ...) -- START", cls, mID); \
  jni_env_->CallStaticVoidMethodA(cls, mID, args.get()); \
  ALOGV("CallStaticVoidMethodA(%p, %p, ...) -- END", cls, mID); \
  return 0; \
}

CALL_STATIC_METHOD_WRAPPER(Object, jobject, %p)
CALL_STATIC_METHOD_WRAPPER(Boolean, jboolean, %d)
CALL_STATIC_METHOD_WRAPPER(Byte, jbyte, %02x)
CALL_STATIC_METHOD_WRAPPER(Char, jchar, %04x)
CALL_STATIC_METHOD_WRAPPER(Short, jshort, %d)
CALL_STATIC_METHOD_WRAPPER(Int, jint, %d)
CALL_STATIC_METHOD_WRAPPER(Long, jlong, %lld)
CALL_STATIC_METHOD_WRAPPER(Float, jfloat, %f)
CALL_STATIC_METHOD_WRAPPER(Double, jdouble, %g)
CALL_STATIC_VOID_METHOD_WRAPPER

DEFINE_WRAPPER(GetStaticFieldID)
{
  QemuMemory::String name(arg2), sig(arg3);
  jfieldID fID = jni_env_->GetStaticFieldID(reinterpret_cast<jclass>(arg1), name.c_str(), sig.c_str());
  ALOGV("GetStaticFieldID(%p, %s, %s) => %p", reinterpret_cast<jclass>(arg1), name.c_str(), sig.c_str(), fID);
  QemuMemory::memcpy(arg4, &fID, sizeof(jfieldID));
  return 0;
}

#define GET_STATIC_FIELD_WRAPPER(name, type, format) \
DEFINE_WRAPPER(GetStatic##name##Field) \
{ \
  type value = jni_env_->GetStatic##name##Field(reinterpret_cast<jclass>(arg1), reinterpret_cast<jfieldID>(arg2)); \
  ALOGV("GetStatic" #name "Field(%p, %p) => " #format, reinterpret_cast<jclass>(arg1), reinterpret_cast<jfieldID>(arg2), value); \
  QemuMemory::memcpy(arg3, &value, sizeof(type)); \
  return 0; \
}

GET_STATIC_FIELD_WRAPPER(Object, jobject, %p)
GET_STATIC_FIELD_WRAPPER(Boolean, jboolean, %d)
GET_STATIC_FIELD_WRAPPER(Byte, jbyte, %02x)
GET_STATIC_FIELD_WRAPPER(Char, jchar, %04x)
GET_STATIC_FIELD_WRAPPER(Short, jshort, %d)
GET_STATIC_FIELD_WRAPPER(Int, jint, %d)
GET_STATIC_FIELD_WRAPPER(Long, jlong, %lld)
GET_STATIC_FIELD_WRAPPER(Float, jfloat, %f)
GET_STATIC_FIELD_WRAPPER(Double, jdouble, %g)

#define SET_STATIC_FIELD_WRAPPER(name, type, format) \
DEFINE_WRAPPER(SetStatic##name##Field) \
{ \
  jclass cls = reinterpret_cast<jclass>(arg1); \
  jfieldID fID = reinterpret_cast<jfieldID>(arg2); \
  QemuMemory::Region<type> value(arg3); \
  jni_env_->SetStatic##name##Field(cls, fID, *value.get()); \
  ALOGV("SetStatic" #name "Field(%p, %p) <= " #format, cls, fID, *value.get()); \
  return 0; \
}

SET_STATIC_FIELD_WRAPPER(Object, jobject, %p)
SET_STATIC_FIELD_WRAPPER(Boolean, jboolean, %d)
SET_STATIC_FIELD_WRAPPER(Byte, jbyte, %02x)
SET_STATIC_FIELD_WRAPPER(Char, jchar, %04x)
SET_STATIC_FIELD_WRAPPER(Short, jshort, %d)
SET_STATIC_FIELD_WRAPPER(Int, jint, %d)
SET_STATIC_FIELD_WRAPPER(Long, jlong, %lld)
SET_STATIC_FIELD_WRAPPER(Float, jfloat, %f)
SET_STATIC_FIELD_WRAPPER(Double, jdouble, %g)

DEFINE_WRAPPER(NewString)
{
  jsize len = arg2;
  QemuMemory::Region<jchar> chars(arg1, len + 1);
  jstring str = jni_env_->NewString(chars.get(), len);
  std::string ss = unicode_to_string(chars.get(), len);
  ALOGV("NewString => [%p] %s", str, ss.c_str());
  QemuMemory::memcpy(arg3, &str, sizeof(jstring));
  return 0;
}

DEFINE_WRAPPER(GetStringLength)
{
  jsize len = jni_env_->GetStringLength(reinterpret_cast<jstring>(arg1));
  ALOGV("GetStringLength(%p) => %d", reinterpret_cast<jstring>(arg1), len);
  return len;
}

DEFINE_WRAPPER(GetStringChars)
{
  jboolean isCopy;
  const jchar *s = jni_env_->GetStringChars(reinterpret_cast<jstring>(arg1), &isCopy);
  std::string ss = unicode_to_string(s, jni_env_->GetStringLength(reinterpret_cast<jstring>(arg1)));
  ALOGV("GetStringChars(%p) => [%p, copy=%d] %s", reinterpret_cast<jstring>(arg1), s, isCopy, ss.c_str());
  QemuMemory::memcpy(arg2, &isCopy, sizeof(jboolean));
  QemuMemory::memcpy(arg3, &s, sizeof(const jchar *));
  return 0;
}

DEFINE_WRAPPER(ReleaseStringChars)
{
  jni_env_->ReleaseStringChars(reinterpret_cast<jstring>(arg1), reinterpret_cast<const jchar *>(arg2));
  ALOGV("ReleaseStringChars(%p, %p)", reinterpret_cast<jstring>(arg1), reinterpret_cast<const jchar *>(arg2));
  return 0;
}

DEFINE_WRAPPER(NewStringUTF)
{
  QemuMemory::String bytes(arg1);
  jstring s = jni_env_->NewStringUTF(bytes.c_str());
  ALOGV("NewStringUTF(%s) => %p", bytes.c_str(), s);
  QemuMemory::memcpy(arg2, &s, sizeof(jstring));
  return 0;
}

DEFINE_WRAPPER(GetStringUTFLength)
{
  jsize len = jni_env_->GetStringUTFLength(reinterpret_cast<jstring>(arg1));
  ALOGV("GetStringUTFLength(%p) => %d", reinterpret_cast<jstring>(arg1), len);
  return len;
}

DEFINE_WRAPPER(GetStringUTFChars)
{
  jboolean isCopy;
  const char *s = jni_env_->GetStringUTFChars(reinterpret_cast<jstring>(arg1), &isCopy);
  ALOGV("GetStringUTFChars(%p) => [%p, copy=%d] %s", reinterpret_cast<jstring>(arg1), s, isCopy, s);
  QemuMemory::memcpy(arg2, &isCopy, sizeof(jboolean));
  QemuMemory::memcpy(arg3, &s, sizeof(const char *));
  return 0;
}

DEFINE_WRAPPER(ReleaseStringUTFChars)
{
  jni_env_->ReleaseStringUTFChars(reinterpret_cast<jstring>(arg1), reinterpret_cast<const char *>(arg2));
  ALOGV("ReleaseStringUTFChars(%p, %p)", reinterpret_cast<jstring>(arg1), reinterpret_cast<const char *>(arg2));
  return 0;
}

DEFINE_WRAPPER(GetArrayLength)
{
  jsize len = jni_env_->GetArrayLength(reinterpret_cast<jarray>(arg1));
  ALOGV("GetArrayLength(%p) => %d", reinterpret_cast<jarray>(arg1), len);
  return len;
}

DEFINE_WRAPPER(NewObjectArray)
{
  jobjectArray array = jni_env_->NewObjectArray(arg1, reinterpret_cast<jclass>(arg2), reinterpret_cast<jobject>(arg3));
  ALOGV("NewObjectArray(%d, %p, %p) => %p", arg1, reinterpret_cast<jclass>(arg2), reinterpret_cast<jobject>(arg3), array);
  QemuMemory::memcpy(arg4, &array, sizeof(jobjectArray));
  return 0;
}

DEFINE_WRAPPER(GetObjectArrayElement)
{
  jobject obj = jni_env_->GetObjectArrayElement(reinterpret_cast<jobjectArray>(arg1), arg2);
  ALOGV("GetObjectArrayElement(%p, %d) => %p", reinterpret_cast<jobjectArray>(arg1), arg2, obj);
  QemuMemory::memcpy(arg3, &obj, sizeof(jobject));
  return 0;
}

DEFINE_WRAPPER(SetObjectArrayElement)
{
  jni_env_->SetObjectArrayElement(reinterpret_cast<jobjectArray>(arg1), arg2, reinterpret_cast<jobject>(arg3));
  ALOGV("SetObjectArrayElement(%p, %d, %p)", reinterpret_cast<jobjectArray>(arg1), arg2, reinterpret_cast<jobject>(arg3));
  return 0;
}

#define NEW_ARRAY_WRAPPER(name, atype) \
DEFINE_WRAPPER(New##name##Array) \
{ \
  atype array = jni_env_->New##name##Array(arg1); \
  ALOGV("New" #name "Array(%d) => %p", arg1, array); \
  QemuMemory::memcpy(arg2, &array, sizeof(atype)); \
  return 0; \
}

NEW_ARRAY_WRAPPER(Boolean, jbooleanArray)
NEW_ARRAY_WRAPPER(Byte, jbyteArray)
NEW_ARRAY_WRAPPER(Char, jcharArray)
NEW_ARRAY_WRAPPER(Short, jshortArray)
NEW_ARRAY_WRAPPER(Int, jintArray)
NEW_ARRAY_WRAPPER(Long, jlongArray)
NEW_ARRAY_WRAPPER(Float, jfloatArray)
NEW_ARRAY_WRAPPER(Double, jdoubleArray)

#define ACCESS_ARRAY_ELEMENTS(name, type, atype) \
DEFINE_WRAPPER(Get##name##ArrayElements) \
{ \
  jboolean isCopy; \
  type *elems = jni_env_->Get##name##ArrayElements(reinterpret_cast<atype>(arg1), &isCopy); \
  ALOGV("Get" #name "ArrayElements(%p) => %p [copy=%d]", reinterpret_cast<atype>(arg1), elems, isCopy); \
  QemuMemory::memcpy(arg2, &isCopy, sizeof(jboolean)); \
  QemuMemory::memcpy(arg3, &elems, sizeof(type*)); \
  return 0; \
} \
 \
DEFINE_WRAPPER(Release##name##ArrayElements) \
{ \
  jni_env_->Release##name##ArrayElements(reinterpret_cast<atype>(arg1), reinterpret_cast<type *>(arg2), arg3); \
  ALOGV("Release" #name "ArrayElements(%p, %p, %d)", reinterpret_cast<atype>(arg1), reinterpret_cast<type *>(arg2), arg3); \
  return 0; \
}

ACCESS_ARRAY_ELEMENTS(Boolean, jboolean, jbooleanArray)
ACCESS_ARRAY_ELEMENTS(Byte, jbyte, jbyteArray)
ACCESS_ARRAY_ELEMENTS(Char, jchar, jcharArray)
ACCESS_ARRAY_ELEMENTS(Short, jshort, jshortArray)
ACCESS_ARRAY_ELEMENTS(Int, jint, jintArray)
ACCESS_ARRAY_ELEMENTS(Long, jlong, jlongArray)
ACCESS_ARRAY_ELEMENTS(Float, jfloat, jfloatArray)
ACCESS_ARRAY_ELEMENTS(Double, jdouble, jdoubleArray)

#define ACCESS_ARRAY_REGION(name, type, atype) \
DEFINE_WRAPPER(Get##name##ArrayRegion) \
{ \
  QemuMemory::Region<type> buf(arg4, arg3); \
  jni_env_->Get##name##ArrayRegion(reinterpret_cast<atype>(arg1), arg2, arg3, buf.get()); \
  ALOGV("Get" #name "ArrayRegion(%p, %d, %d, %p)", reinterpret_cast<atype>(arg1), arg2, arg3, reinterpret_cast<void *>(arg4)); \
  return 0; \
} \
 \
DEFINE_WRAPPER(Set##name##ArrayRegion) \
{ \
  QemuMemory::Region<type> buf(arg4, arg3); \
  jni_env_->Set##name##ArrayRegion(reinterpret_cast<atype>(arg1), arg2, arg3, buf.get()); \
  ALOGV("Set" #name "ArrayRegion(%p, %d, %d, %p)", reinterpret_cast<atype>(arg1), arg2, arg3, reinterpret_cast<void *>(arg4)); \
  return 0; \
}

ACCESS_ARRAY_REGION(Boolean, jboolean, jbooleanArray)
ACCESS_ARRAY_REGION(Byte, jbyte, jbyteArray)
ACCESS_ARRAY_REGION(Char, jchar, jcharArray)
ACCESS_ARRAY_REGION(Short, jshort, jshortArray)
ACCESS_ARRAY_REGION(Int, jint, jintArray)
ACCESS_ARRAY_REGION(Long, jlong, jlongArray)
ACCESS_ARRAY_REGION(Float, jfloat, jfloatArray)
ACCESS_ARRAY_REGION(Double, jdouble, jdoubleArray)

typedef struct {
    uint32_t name;
    uint32_t signature;
    uint32_t fnPtr;
} guest_JNINativeMethod;

DEFINE_WRAPPER(RegisterNatives)
{
  jclass cls = reinterpret_cast<jclass>(arg1);
  std::string cls_name(get_class_name(jni_env_, cls));
  ALOGV("RegisterNatives[%p]: %s", cls, cls_name.c_str());
  jint n_methods = arg3;
  JNINativeMethod methods[n_methods];
  QemuMemory::Region<guest_JNINativeMethod> g_methods(arg2, n_methods);
  memset(methods, 0, sizeof(methods));
  for (int i = 0; i < n_methods; i++) {
      QemuMemory::String name(g_methods[i].name), sig(g_methods[i].signature);
      ALOGV("RegisterNatives[%p]:   %s %s %08x", cls, name.c_str(), sig.c_str(), g_methods[i].fnPtr);
      jmethodID mID = jni_env_->GetMethodID(cls, name.c_str(), sig.c_str());
      if (! mID) {
          jni_env_->ExceptionClear();
          mID = jni_env_->GetStaticMethodID(cls, name.c_str(), sig.c_str());
          if (! mID) {
              jni_env_->ExceptionClear();
              ALOGE("RegisterNatives[%p]: unknwon method %s %s", cls, name.c_str(), sig.c_str());
              continue;
          }
      }
      const char *shorty = runtime_->getMethodShorty(jni_env_, mID);
      methods[i].name = strdup(name.c_str());
      methods[i].signature = strdup(sig.c_str());
      std::ostringstream tramp_name;
      tramp_name << cls_name << "::" << methods[i].name << "::" << shorty;
      std::shared_ptr<Trampoline> tramp(new JNITrampoline(tramp_name.str(), g_methods[i].fnPtr, shorty));
      native_methods_[tramp->get_name()] = tramp;
      methods[i].fnPtr = tramp->get_handle();
  }
  jint result = jni_env_->RegisterNatives(cls, methods, n_methods);
  ALOGV("RegisterNatives[%p] => %d", cls, result);
  for (int i = 0; i < n_methods; i++) {
      free(const_cast<char *>(methods[i].name));
      free(const_cast<char *>(methods[i].signature));
  }
  return result;
}

DEFINE_WRAPPER(UnregisterNatives)
{
  return jni_env_->UnregisterNatives(reinterpret_cast<jclass>(arg1));
}

DEFINE_WRAPPER(MonitorEnter)
{
  jint ret = jni_env_->MonitorEnter(reinterpret_cast<jobject>(arg1));
  ALOGV("MonitorEnter(%p) => %d", reinterpret_cast<jobject>(arg1), ret);
  return ret;
}

DEFINE_WRAPPER(MonitorExit)
{
  jint ret = jni_env_->MonitorExit(reinterpret_cast<jobject>(arg1));
  ALOGV("MonitorExit(%p) => %d", reinterpret_cast<jobject>(arg1), ret);
  return ret;
}

DEFINE_WRAPPER(GetJavaVM)
{
  JavaVM *vm;
  return jni_env_->GetJavaVM(&vm);
}

DEFINE_WRAPPER(GetStringRegion)
{
  QemuMemory::Region<jchar> buf(arg4, arg3);
  jni_env_->GetStringRegion(reinterpret_cast<jstring>(arg1), arg2, arg3, buf.get());
  ALOGV("GetStringRegion(%p, %d, %d, %p)", reinterpret_cast<jstring>(arg1), arg2, arg3, reinterpret_cast<void *>(arg4));
  return 0;
}

DEFINE_WRAPPER(GetStringUTFRegion)
{
  QemuMemory::Region<char> buf(arg4, arg3);
  jni_env_->GetStringUTFRegion(reinterpret_cast<jstring>(arg1), arg2, arg3, buf.get());
  ALOGV("GetStringUTFRegion(%p, %d, %d, %p)", reinterpret_cast<jstring>(arg1), arg2, arg3, reinterpret_cast<void *>(arg4));
  return 0;
}

DEFINE_WRAPPER(GetPrimitiveArrayCritical)
{
  jboolean isCopy;
  void *ptr = jni_env_->GetPrimitiveArrayCritical(reinterpret_cast<jarray>(arg1), &isCopy);
  ALOGV("GetPrimitiveArrayCritical(%p) => %p [copy=%d]", reinterpret_cast<jarray>(arg1), ptr, isCopy);
  QemuMemory::memcpy(arg2, &isCopy, sizeof(jboolean));
  QemuMemory::memcpy(arg3, &ptr, sizeof(void *));
  return 0;
}

DEFINE_WRAPPER(ReleasePrimitiveArrayCritical)
{
  jni_env_->ReleasePrimitiveArrayCritical(reinterpret_cast<jarray>(arg1), reinterpret_cast<void *>(arg2), arg3);
  ALOGV("ReleasePrimitiveArrayCritical(%p, %p, %d)", reinterpret_cast<jarray>(arg1), reinterpret_cast<void *>(arg2), arg3);
  return 0;
}

DEFINE_WRAPPER(GetStringCritical)
{
  jboolean isCopy;
  jsize len = jni_env_->GetStringLength(reinterpret_cast<jstring>(arg1));
  const jchar *s = jni_env_->GetStringCritical(reinterpret_cast<jstring>(arg1), &isCopy);
  std::string ss = unicode_to_string(s, len);
  ALOGV("GetStringCritical(%p) => [%p, copy=%d] %s", reinterpret_cast<jstring>(arg1), s, isCopy, ss.c_str());
  QemuMemory::memcpy(arg2, &isCopy, sizeof(jboolean));
  QemuMemory::memcpy(arg3, &s, sizeof(const jchar *));
  return 0;
}

DEFINE_WRAPPER(ReleaseStringCritical)
{
  jni_env_->ReleaseStringCritical(reinterpret_cast<jstring>(arg1), reinterpret_cast<const jchar *>(arg2));
  ALOGV("ReleaseStringCritical(%p, %p)", reinterpret_cast<jstring>(arg1), reinterpret_cast<const jchar *>(arg2));
  return 0;
}

DEFINE_WRAPPER(NewWeakGlobalRef)
{
  jweak obj = jni_env_->NewWeakGlobalRef(reinterpret_cast<jobject>(arg1));
  ALOGV("NewWeakGlobalRef(%p) => %p", reinterpret_cast<jobject>(arg1), obj);
  QemuMemory::memcpy(arg2, &obj, sizeof(jweak));
  return 0;
}

DEFINE_WRAPPER(DeleteWeakGlobalRef)
{
  jni_env_->DeleteWeakGlobalRef(reinterpret_cast<jweak>(arg1));
  ALOGV("DeleteWeakGlobalRef(%p)", reinterpret_cast<jweak>(arg1));
  return 0;
}

DEFINE_WRAPPER(ExceptionCheck)
{
  jboolean ret = jni_env_->ExceptionCheck();
  ALOGV("ExceptionCheck => %s", ret ? "true" : "false");
  return ret == JNI_TRUE ? -1 : 0;
}

DEFINE_WRAPPER(NewDirectByteBuffer)
{
  void *address = reinterpret_cast<void *>(arg1);
  QemuMemory::Region<jlong> capacity(arg2);
  jobject obj = jni_env_->NewDirectByteBuffer(address, capacity[0]);
  ALOGV("NewDirectByteBuffer(%p, %lld) => %p", address, capacity[0], obj);
  QemuMemory::memcpy(arg3, &obj, sizeof(jobject));
  return 0;
}

DEFINE_WRAPPER(GetDirectBufferAddress)
{
  void *addr = jni_env_->GetDirectBufferAddress(reinterpret_cast<jobject>(arg1));
  ALOGV("GetDirectBufferAddress(%p) => %p", reinterpret_cast<jobject>(arg1), addr);
  QemuMemory::memcpy(arg2, &addr, sizeof(void *));
  return 0;
}

DEFINE_WRAPPER(GetDirectBufferCapacity)
{
  jlong ret = jni_env_->GetDirectBufferCapacity(reinterpret_cast<jobject>(arg1));
  ALOGV("GetDirectBufferCapacity(%p) => %lld", reinterpret_cast<jobject>(arg1), ret);
  QemuMemory::memcpy(arg2, &ret, sizeof(jlong));
  return 0;
}

DEFINE_WRAPPER(GetObjectRefType)
{
  jobjectRefType ret = jni_env_->GetObjectRefType(reinterpret_cast<jobject>(arg1));
  ALOGV("GetObjectRefType(%p) => %d", reinterpret_cast<jobject>(arg1), ret);
  return ret;
}

static wrapper_fcn_t jni_env_wrapper_[] = {
    [4] = WRAPPER(GetVersion),
    [5] = WRAPPER(DefineClass),
    [6] = WRAPPER(FindClass),
    [7] = WRAPPER(FromReflectedMethod),
    [8] = WRAPPER(FromReflectedField),
    [9] = WRAPPER(ToReflectedMethod),
    [10] = WRAPPER(GetSuperclass),
    [11] = WRAPPER(IsAssignableFrom),
    [12] = WRAPPER(ToReflectedField),
    [13] = WRAPPER(Throw),
    [14] = WRAPPER(ThrowNew),
    [15] = WRAPPER(ExceptionOccurred),
    [16] = WRAPPER(ExceptionDescribe),
    [17] = WRAPPER(ExceptionClear),
    [18] = WRAPPER(FatalError),
    [19] = WRAPPER(PushLocalFrame),
    [20] = WRAPPER(PopLocalFrame),
    [21] = WRAPPER(NewGlobalRef),
    [22] = WRAPPER(DeleteGlobalRef),
    [23] = WRAPPER(DeleteLocalRef),
    [24] = WRAPPER(IsSameObject),
    [25] = WRAPPER(NewLocalRef),
    [26] = WRAPPER(EnsureLocalCapacity),
    [27] = WRAPPER(AllocObject),
    [29] = WRAPPER(NewObjectV),
    [30] = WRAPPER(NewObjectA),
    [31] = WRAPPER(GetObjectClass),
    [32] = WRAPPER(IsInstanceOf),
    [33] = WRAPPER(GetMethodID),
    [35] = WRAPPER(CallObjectMethodV),
    [36] = WRAPPER(CallObjectMethodA),
    [38] = WRAPPER(CallBooleanMethodV),
    [39] = WRAPPER(CallBooleanMethodA),
    [41] = WRAPPER(CallByteMethodV),
    [42] = WRAPPER(CallByteMethodA),
    [44] = WRAPPER(CallCharMethodV),
    [45] = WRAPPER(CallCharMethodA),
    [47] = WRAPPER(CallShortMethodV),
    [48] = WRAPPER(CallShortMethodA),
    [50] = WRAPPER(CallIntMethodV),
    [51] = WRAPPER(CallIntMethodA),
    [53] = WRAPPER(CallLongMethodV),
    [54] = WRAPPER(CallLongMethodA),
    [56] = WRAPPER(CallFloatMethodV),
    [57] = WRAPPER(CallFloatMethodA),
    [59] = WRAPPER(CallDoubleMethodV),
    [60] = WRAPPER(CallDoubleMethodA),
    [62] = WRAPPER(CallVoidMethodV),
    [63] = WRAPPER(CallVoidMethodA),
    [65] = WRAPPER(CallNonvirtualObjectMethodV),
    [66] = WRAPPER(CallNonvirtualObjectMethodA),
    [68] = WRAPPER(CallNonvirtualBooleanMethodV),
    [69] = WRAPPER(CallNonvirtualBooleanMethodA),
    [71] = WRAPPER(CallNonvirtualByteMethodV),
    [72] = WRAPPER(CallNonvirtualByteMethodA),
    [74] = WRAPPER(CallNonvirtualCharMethodV),
    [75] = WRAPPER(CallNonvirtualCharMethodA),
    [77] = WRAPPER(CallNonvirtualShortMethodV),
    [78] = WRAPPER(CallNonvirtualShortMethodA),
    [80] = WRAPPER(CallNonvirtualIntMethodV),
    [81] = WRAPPER(CallNonvirtualIntMethodA),
    [83] = WRAPPER(CallNonvirtualLongMethodV),
    [84] = WRAPPER(CallNonvirtualLongMethodA),
    [86] = WRAPPER(CallNonvirtualFloatMethodV),
    [87] = WRAPPER(CallNonvirtualFloatMethodA),
    [89] = WRAPPER(CallNonvirtualDoubleMethodV),
    [90] = WRAPPER(CallNonvirtualDoubleMethodA),
    [92] = WRAPPER(CallNonvirtualVoidMethodV),
    [93] = WRAPPER(CallNonvirtualVoidMethodA),
    [94] = WRAPPER(GetFieldID),
    [95] = WRAPPER(GetObjectField),
    [96] = WRAPPER(GetBooleanField),
    [97] = WRAPPER(GetByteField),
    [98] = WRAPPER(GetCharField),
    [99] = WRAPPER(GetShortField),
    [100] = WRAPPER(GetIntField),
    [101] = WRAPPER(GetLongField),
    [102] = WRAPPER(GetFloatField),
    [103] = WRAPPER(GetDoubleField),
    [104] = WRAPPER(SetObjectField),
    [105] = WRAPPER(SetBooleanField),
    [106] = WRAPPER(SetByteField),
    [107] = WRAPPER(SetCharField),
    [108] = WRAPPER(SetShortField),
    [109] = WRAPPER(SetIntField),
    [110] = WRAPPER(SetLongField),
    [111] = WRAPPER(SetFloatField),
    [112] = WRAPPER(SetDoubleField),
    [113] = WRAPPER(GetStaticMethodID),
    [115] = WRAPPER(CallStaticObjectMethodV),
    [116] = WRAPPER(CallStaticObjectMethodA),
    [118] = WRAPPER(CallStaticBooleanMethodV),
    [119] = WRAPPER(CallStaticBooleanMethodA),
    [121] = WRAPPER(CallStaticByteMethodV),
    [122] = WRAPPER(CallStaticByteMethodA),
    [124] = WRAPPER(CallStaticCharMethodV),
    [125] = WRAPPER(CallStaticCharMethodA),
    [127] = WRAPPER(CallStaticShortMethodV),
    [128] = WRAPPER(CallStaticShortMethodA),
    [130] = WRAPPER(CallStaticIntMethodV),
    [131] = WRAPPER(CallStaticIntMethodA),
    [133] = WRAPPER(CallStaticLongMethodV),
    [134] = WRAPPER(CallStaticLongMethodA),
    [136] = WRAPPER(CallStaticFloatMethodV),
    [137] = WRAPPER(CallStaticFloatMethodA),
    [139] = WRAPPER(CallStaticDoubleMethodV),
    [140] = WRAPPER(CallStaticDoubleMethodA),
    [142] = WRAPPER(CallStaticVoidMethodV),
    [143] = WRAPPER(CallStaticVoidMethodA),
    [144] = WRAPPER(GetStaticFieldID),
    [145] = WRAPPER(GetStaticObjectField),
    [146] = WRAPPER(GetStaticBooleanField),
    [147] = WRAPPER(GetStaticByteField),
    [148] = WRAPPER(GetStaticCharField),
    [149] = WRAPPER(GetStaticShortField),
    [150] = WRAPPER(GetStaticIntField),
    [151] = WRAPPER(GetStaticLongField),
    [152] = WRAPPER(GetStaticFloatField),
    [153] = WRAPPER(GetStaticDoubleField),
    [154] = WRAPPER(SetStaticObjectField),
    [155] = WRAPPER(SetStaticBooleanField),
    [156] = WRAPPER(SetStaticByteField),
    [157] = WRAPPER(SetStaticCharField),
    [158] = WRAPPER(SetStaticShortField),
    [159] = WRAPPER(SetStaticIntField),
    [160] = WRAPPER(SetStaticLongField),
    [161] = WRAPPER(SetStaticFloatField),
    [162] = WRAPPER(SetStaticDoubleField),
    [163] = WRAPPER(NewString),
    [164] = WRAPPER(GetStringLength),
    [165] = WRAPPER(GetStringChars),
    [166] = WRAPPER(ReleaseStringChars),
    [167] = WRAPPER(NewStringUTF),
    [168] = WRAPPER(GetStringUTFLength),
    [169] = WRAPPER(GetStringUTFChars),
    [170] = WRAPPER(ReleaseStringUTFChars),
    [171] = WRAPPER(GetArrayLength),
    [172] = WRAPPER(NewObjectArray),
    [173] = WRAPPER(GetObjectArrayElement),
    [174] = WRAPPER(SetObjectArrayElement),
    [175] = WRAPPER(NewBooleanArray),
    [176] = WRAPPER(NewByteArray),
    [177] = WRAPPER(NewCharArray),
    [178] = WRAPPER(NewShortArray),
    [179] = WRAPPER(NewIntArray),
    [180] = WRAPPER(NewLongArray),
    [181] = WRAPPER(NewFloatArray),
    [182] = WRAPPER(NewDoubleArray),
    [183] = WRAPPER(GetBooleanArrayElements),
    [184] = WRAPPER(GetByteArrayElements),
    [185] = WRAPPER(GetCharArrayElements),
    [186] = WRAPPER(GetShortArrayElements),
    [187] = WRAPPER(GetIntArrayElements),
    [188] = WRAPPER(GetLongArrayElements),
    [189] = WRAPPER(GetFloatArrayElements),
    [190] = WRAPPER(GetDoubleArrayElements),
    [191] = WRAPPER(ReleaseBooleanArrayElements),
    [192] = WRAPPER(ReleaseByteArrayElements),
    [193] = WRAPPER(ReleaseCharArrayElements),
    [194] = WRAPPER(ReleaseShortArrayElements),
    [195] = WRAPPER(ReleaseIntArrayElements),
    [196] = WRAPPER(ReleaseLongArrayElements),
    [197] = WRAPPER(ReleaseFloatArrayElements),
    [198] = WRAPPER(ReleaseDoubleArrayElements),
    [199] = WRAPPER(GetBooleanArrayRegion),
    [200] = WRAPPER(GetByteArrayRegion),
    [201] = WRAPPER(GetCharArrayRegion),
    [202] = WRAPPER(GetShortArrayRegion),
    [203] = WRAPPER(GetIntArrayRegion),
    [204] = WRAPPER(GetLongArrayRegion),
    [205] = WRAPPER(GetFloatArrayRegion),
    [206] = WRAPPER(GetDoubleArrayRegion),
    [207] = WRAPPER(SetBooleanArrayRegion),
    [208] = WRAPPER(SetByteArrayRegion),
    [209] = WRAPPER(SetCharArrayRegion),
    [210] = WRAPPER(SetShortArrayRegion),
    [211] = WRAPPER(SetIntArrayRegion),
    [212] = WRAPPER(SetLongArrayRegion),
    [213] = WRAPPER(SetFloatArrayRegion),
    [214] = WRAPPER(SetDoubleArrayRegion),
    [215] = WRAPPER(RegisterNatives),
    [216] = WRAPPER(UnregisterNatives),
    [217] = WRAPPER(MonitorEnter),
    [218] = WRAPPER(MonitorExit),
    [219] = WRAPPER(GetJavaVM),
    [220] = WRAPPER(GetStringRegion),
    [221] = WRAPPER(GetStringUTFRegion),
    [222] = WRAPPER(GetPrimitiveArrayCritical),
    [223] = WRAPPER(ReleasePrimitiveArrayCritical),
    [224] = WRAPPER(GetStringCritical),
    [225] = WRAPPER(ReleaseStringCritical),
    [226] = WRAPPER(NewWeakGlobalRef),
    [227] = WRAPPER(DeleteWeakGlobalRef),
    [228] = WRAPPER(ExceptionCheck),
    [229] = WRAPPER(NewDirectByteBuffer),
    [230] = WRAPPER(GetDirectBufferAddress),
    [231] = WRAPPER(GetDirectBufferCapacity),
    [232] = WRAPPER(GetObjectRefType)
};

static int32_t syscall_jni_env(void *cpu_env, int num,
                               uint32_t arg1, uint32_t arg2, uint32_t arg3,
                               uint32_t arg4, uint32_t arg5, uint32_t arg6)
{
  wrapper_fcn_t func = jni_env_wrapper_[arg1];
  if (func)
    return func(cpu_env, arg2, arg3, arg4, arg5, arg6);
  ALOGE("syscall_jni_env[%d] not implemented", arg1);
  return -ENOSYS;
}

DEFINE_WRAPPER(AttachCurrentThread)
{
  JNIEnv *env;
  jint result = java_vm_->AttachCurrentThread(&env, nullptr);
  ALOGV("AttachCurrentThread => %d", result);
  if (result == JNI_OK && ! jni_env_)
    jni_env_ = env;
  return result;
}

DEFINE_WRAPPER(DetachCurrentThread)
{
  jint result = java_vm_->DetachCurrentThread();
  ALOGV("DetachCurrentThread => %d", result);
  jni_env_ = nullptr;
  return result;
}

DEFINE_WRAPPER(GetEnv)
{
  JNIEnv *env;
  jint result = java_vm_->GetEnv(reinterpret_cast<void **>(&env), arg1);
  ALOGV("GetEnv(%08x) => %d", arg1, result);
  if (result == JNI_OK && ! jni_env_)
    jni_env_ = env;
  return result;
}

static wrapper_fcn_t java_vm_wrapper_[] = {
    [4] = WRAPPER(AttachCurrentThread),
    [5] = WRAPPER(DetachCurrentThread),
    [6] = WRAPPER(GetEnv),
};

static int32_t syscall_java_vm(void *cpu_env, int num,
                               uint32_t arg1, uint32_t arg2, uint32_t arg3,
                               uint32_t arg4, uint32_t arg5, uint32_t arg6)
{
  wrapper_fcn_t func = java_vm_wrapper_[arg1];
  if (func)
    return func(cpu_env, arg2, arg3, arg4, arg5, arg6);
  ALOGE("syscall_java_vm[%d] not implemented", arg1);
  return -ENOSYS;
}

static int32_t syscall_handler(void *cpu_env, int num,
                               uint32_t arg1, uint32_t arg2, uint32_t arg3,
                               uint32_t arg4, uint32_t arg5, uint32_t arg6)
{
    switch (num) {
        case 0x1000: return syscall_jni_env(cpu_env, num, arg1, arg2, arg3, arg4, arg5, arg6);
        case 0x1001: return syscall_java_vm(cpu_env, num, arg1, arg2, arg3, arg4, arg5, arg6);
        default: return -ENOSYS;
    }
}

namespace JavaBridge {

void initialize(const NativeBridgeRuntimeCallbacks *runtime)
{
  jsize count;

  JNI_GetCreatedJavaVMs(&java_vm_, 1, &count);
  ALOGV("JavaBridge::java_vm_: %p", java_vm_);

  guest_jni_env_ = QemuCore::lookup_symbol("nb_qemu_JNIEnv");
  ALOGV("JavaBridge::guest_jni_env_: %p", reinterpret_cast<void *>(guest_jni_env_));
  guest_java_vm_ = QemuCore::lookup_symbol("nb_qemu_JavaVM");
  ALOGV("JavaBridge::guest_java_vm_: %p", reinterpret_cast<void *>(guest_java_vm_));

  QemuCore::register_syscall_handler(syscall_handler);

  runtime_ = runtime;
}

uint32_t& wrap_jni_env(JNIEnv *env)
{
  jni_env_ = env;
  if (jni_env_ && ! java_vm_)
    jni_env_->GetJavaVM(&java_vm_);
  return guest_jni_env_;
}

uint32_t& wrap_java_vm(JavaVM *vm)
{
  if (java_vm_ && vm != java_vm_)
    ALOGW("JavaVM changed (%p != %p)", java_vm_, vm);
  java_vm_ = vm;
  return guest_java_vm_;
}

}

extern "C" {

JNIEnv* unwrap_jni_env(uint32_t env)
{
  ALOGI("unwrap_jni_env: %08x", env);
  if (env != guest_jni_env_)
    ALOGW("unwrap_jni_env: unexpected guest JNIEnv, %08x != %08x", env, guest_jni_env_);
  return jni_env_;
}

}
