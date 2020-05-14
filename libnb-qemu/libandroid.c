#define LOG_TAG "libnb-qemu"
//#define LOG_NDEBUG 0

#include <stdint.h>
#include <log/log.h>
#include "QemuInclude.h"
#include <android/asset_manager_jni.h>
#include <android/asset_manager.h>
#include <android/configuration.h>
#include <android/input.h>
#include <android/native_window_jni.h>
#include <android/sensor.h>
#include "libandroid.itf.h"

extern void* unwrap_jni_env(void* env);

void nb_handle_AAssetDir_close(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    AAssetDir_close(
        *(void**)(&sp[0])
    );
}
void nb_handle_AAssetDir_getNextFileName(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)AAssetDir_getNextFileName(
        *(void**)(&sp[0])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_AAssetDir_rewind(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    AAssetDir_rewind(
        *(void**)(&sp[0])
    );
}
void nb_handle_AAssetManager_fromJava(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)AAssetManager_fromJava(
        unwrap_jni_env(*(void**)(&sp[0])),
        *(void**)(&sp[4])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_AAssetManager_open(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)AAssetManager_open(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(int*)(&sp[8])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_AAssetManager_openDir(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)AAssetManager_openDir(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_AAsset_close(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    AAsset_close(
        *(void**)(&sp[0])
    );
}
void nb_handle_AAsset_getBuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)AAsset_getBuffer(
        *(void**)(&sp[0])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_AAsset_getLength(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    off_t __nb_ret = (off_t)AAsset_getLength(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AAsset_getLength64(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    off64_t __nb_ret = (off64_t)AAsset_getLength64(
        *(void**)(&sp[0])
    );
    env->regs[0] = __nb_ret & 0xffffffff;
    env->regs[1] = (__nb_ret >> 32) & 0xffffffff;
}
void nb_handle_AAsset_getRemainingLength(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    off_t __nb_ret = (off_t)AAsset_getRemainingLength(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AAsset_getRemainingLength64(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    off64_t __nb_ret = (off64_t)AAsset_getRemainingLength64(
        *(void**)(&sp[0])
    );
    env->regs[0] = __nb_ret & 0xffffffff;
    env->regs[1] = (__nb_ret >> 32) & 0xffffffff;
}
void nb_handle_AAsset_isAllocated(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)AAsset_isAllocated(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AAsset_openFileDescriptor(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)AAsset_openFileDescriptor(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AAsset_openFileDescriptor64(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)AAsset_openFileDescriptor64(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AAsset_read(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)AAsset_read(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(size_t*)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AAsset_seek(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    off_t __nb_ret = (off_t)AAsset_seek(
        *(void**)(&sp[0]),
        *(off_t*)(&sp[4]),
        *(int*)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AAsset_seek64(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    off64_t __nb_ret = (off64_t)AAsset_seek64(
        *(void**)(&sp[0]),
        *(off64_t*)(&sp[8]),
        *(int*)(&sp[16])
    );
    env->regs[0] = __nb_ret & 0xffffffff;
    env->regs[1] = (__nb_ret >> 32) & 0xffffffff;
}
void nb_handle_ANativeWindow_acquire(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    ANativeWindow_acquire(
        *(void**)(&sp[0])
    );
}
void nb_handle_ANativeWindow_getFormat(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int32_t __nb_ret = (int32_t)ANativeWindow_getFormat(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ANativeWindow_getHeight(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int32_t __nb_ret = (int32_t)ANativeWindow_getHeight(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ANativeWindow_getWidth(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int32_t __nb_ret = (int32_t)ANativeWindow_getWidth(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ANativeWindow_lock(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int32_t __nb_ret = (int32_t)ANativeWindow_lock(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ANativeWindow_release(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    ANativeWindow_release(
        *(void**)(&sp[0])
    );
}
void nb_handle_ANativeWindow_setBuffersGeometry(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int32_t __nb_ret = (int32_t)ANativeWindow_setBuffersGeometry(
        *(void**)(&sp[0]),
        *(int32_t*)(&sp[4]),
        *(int32_t*)(&sp[8]),
        *(int32_t*)(&sp[12])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ANativeWindow_unlockAndPost(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int32_t __nb_ret = (int32_t)ANativeWindow_unlockAndPost(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ANativeWindow_fromSurface(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)ANativeWindow_fromSurface(
        unwrap_jni_env(*(void**)(&sp[0])),
        *(void**)(&sp[4])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_ALooper_acquire(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    ALooper_acquire(
        *(void**)(&sp[0])
    );
}
void nb_handle_libandroid_ALooper_addFd(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)libandroid_ALooper_addFd(
        *(void**)(&sp[0]),
        *(int*)(&sp[4]),
        *(int*)(&sp[8]),
        *(int*)(&sp[12]),
        *(void**)(&sp[16]),
        *(void**)(&sp[20])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ALooper_forThread(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)ALooper_forThread(
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_ALooper_pollAll(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)ALooper_pollAll(
        *(int*)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ALooper_pollOnce(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)ALooper_pollOnce(
        *(int*)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ALooper_prepare(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)ALooper_prepare(
        *(int*)(&sp[0])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_ALooper_release(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    ALooper_release(
        *(void**)(&sp[0])
    );
}
void nb_handle_ALooper_removeFd(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)ALooper_removeFd(
        *(void**)(&sp[0]),
        *(int*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ALooper_wake(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    ALooper_wake(
        *(void**)(&sp[0])
    );
}
void nb_handle_ASensorEventQueue_disableSensor(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)ASensorEventQueue_disableSensor(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ASensorEventQueue_enableSensor(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)ASensorEventQueue_enableSensor(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ASensorEventQueue_getEvents(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    ssize_t __nb_ret = (ssize_t)ASensorEventQueue_getEvents(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(size_t*)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ASensorEventQueue_hasEvents(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)ASensorEventQueue_hasEvents(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ASensorEventQueue_setEventRate(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)ASensorEventQueue_setEventRate(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(int32_t*)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_libandroid_ASensorManager_createEventQueue(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)libandroid_ASensorManager_createEventQueue(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(int*)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_ASensorManager_destroyEventQueue(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)ASensorManager_destroyEventQueue(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ASensorManager_getDefaultSensor(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)ASensorManager_getDefaultSensor(
        *(void**)(&sp[0]),
        *(int*)(&sp[4])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_ASensorManager_getInstance(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)ASensorManager_getInstance(
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_ASensorManager_getSensorList(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)ASensorManager_getSensorList(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ASensor_getMinDelay(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)ASensor_getMinDelay(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ASensor_getName(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)ASensor_getName(
        *(void**)(&sp[0])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_ASensor_getResolution(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    float __nb_ret = (float)ASensor_getResolution(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ASensor_getType(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)ASensor_getType(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_ASensor_getVendor(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)ASensor_getVendor(
        *(void**)(&sp[0])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_AConfiguration_delete(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    AConfiguration_delete(
        *(void**)(&sp[0])
    );
}
void nb_handle_AConfiguration_fromAssetManager(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    AConfiguration_fromAssetManager(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_AConfiguration_getCountry(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    AConfiguration_getCountry(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_AConfiguration_getDensity(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int32_t __nb_ret = (int32_t)AConfiguration_getDensity(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AConfiguration_getLanguage(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    AConfiguration_getLanguage(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_AConfiguration_new(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)AConfiguration_new(
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_libandroid_AInputQueue_attachLooper(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    libandroid_AInputQueue_attachLooper(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(int*)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_AInputQueue_detachLooper(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    AInputQueue_detachLooper(
        *(void**)(&sp[0])
    );
}
void nb_handle_AInputQueue_finishEvent(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    AInputQueue_finishEvent(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(int*)(&sp[8])
    );
}
void nb_handle_AInputQueue_getEvent(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int32_t __nb_ret = (int32_t)AInputQueue_getEvent(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AInputQueue_preDispatchEvent(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int32_t __nb_ret = (int32_t)AInputQueue_preDispatchEvent(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AInputEvent_getType(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int32_t __nb_ret = (int32_t)AInputEvent_getType(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AMotionEvent_getAction(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int32_t __nb_ret = (int32_t)AMotionEvent_getAction(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AMotionEvent_getDownTime(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int64_t __nb_ret = (int64_t)AMotionEvent_getDownTime(
        *(void**)(&sp[0])
    );
    env->regs[0] = __nb_ret & 0xffffffff;
    env->regs[1] = (__nb_ret >> 32) & 0xffffffff;
}
void nb_handle_AMotionEvent_getEventTime(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int64_t __nb_ret = (int64_t)AMotionEvent_getEventTime(
        *(void**)(&sp[0])
    );
    env->regs[0] = __nb_ret & 0xffffffff;
    env->regs[1] = (__nb_ret >> 32) & 0xffffffff;
}
void nb_handle_AMotionEvent_getPointerCount(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    size_t __nb_ret = (size_t)AMotionEvent_getPointerCount(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AMotionEvent_getPointerId(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int32_t __nb_ret = (int32_t)AMotionEvent_getPointerId(
        *(void**)(&sp[0]),
        *(size_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AMotionEvent_getX(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    float __nb_ret = (float)AMotionEvent_getX(
        *(void**)(&sp[0]),
        *(size_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_AMotionEvent_getY(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    float __nb_ret = (float)AMotionEvent_getY(
        *(void**)(&sp[0]),
        *(size_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
__attribute__((visibility("default")))
void nb_handle_svc(CPUARMState *env, int svc) {
    switch (svc) {
        case 0x0700: ALOGV("AAssetDir_close"); nb_handle_AAssetDir_close(env); break;
        case 0x0701: ALOGV("AAssetDir_getNextFileName"); nb_handle_AAssetDir_getNextFileName(env); break;
        case 0x0702: ALOGV("AAssetDir_rewind"); nb_handle_AAssetDir_rewind(env); break;
        case 0x0703: ALOGV("AAssetManager_fromJava"); nb_handle_AAssetManager_fromJava(env); break;
        case 0x0704: ALOGV("AAssetManager_open"); nb_handle_AAssetManager_open(env); break;
        case 0x0705: ALOGV("AAssetManager_openDir"); nb_handle_AAssetManager_openDir(env); break;
        case 0x0706: ALOGV("AAsset_close"); nb_handle_AAsset_close(env); break;
        case 0x0707: ALOGV("AAsset_getBuffer"); nb_handle_AAsset_getBuffer(env); break;
        case 0x0708: ALOGV("AAsset_getLength"); nb_handle_AAsset_getLength(env); break;
        case 0x0709: ALOGV("AAsset_getLength64"); nb_handle_AAsset_getLength64(env); break;
        case 0x070a: ALOGV("AAsset_getRemainingLength"); nb_handle_AAsset_getRemainingLength(env); break;
        case 0x070b: ALOGV("AAsset_getRemainingLength64"); nb_handle_AAsset_getRemainingLength64(env); break;
        case 0x070c: ALOGV("AAsset_isAllocated"); nb_handle_AAsset_isAllocated(env); break;
        case 0x070d: ALOGV("AAsset_openFileDescriptor"); nb_handle_AAsset_openFileDescriptor(env); break;
        case 0x070e: ALOGV("AAsset_openFileDescriptor64"); nb_handle_AAsset_openFileDescriptor64(env); break;
        case 0x070f: ALOGV("AAsset_read"); nb_handle_AAsset_read(env); break;
        case 0x0710: ALOGV("AAsset_seek"); nb_handle_AAsset_seek(env); break;
        case 0x0711: ALOGV("AAsset_seek64"); nb_handle_AAsset_seek64(env); break;
        case 0x0712: ALOGV("ANativeWindow_acquire"); nb_handle_ANativeWindow_acquire(env); break;
        case 0x0713: ALOGV("ANativeWindow_getFormat"); nb_handle_ANativeWindow_getFormat(env); break;
        case 0x0714: ALOGV("ANativeWindow_getHeight"); nb_handle_ANativeWindow_getHeight(env); break;
        case 0x0715: ALOGV("ANativeWindow_getWidth"); nb_handle_ANativeWindow_getWidth(env); break;
        case 0x0716: ALOGV("ANativeWindow_lock"); nb_handle_ANativeWindow_lock(env); break;
        case 0x0717: ALOGV("ANativeWindow_release"); nb_handle_ANativeWindow_release(env); break;
        case 0x0718: ALOGV("ANativeWindow_setBuffersGeometry"); nb_handle_ANativeWindow_setBuffersGeometry(env); break;
        case 0x0719: ALOGV("ANativeWindow_unlockAndPost"); nb_handle_ANativeWindow_unlockAndPost(env); break;
        case 0x071a: ALOGV("ANativeWindow_fromSurface"); nb_handle_ANativeWindow_fromSurface(env); break;
        case 0x071b: ALOGV("ALooper_acquire"); nb_handle_ALooper_acquire(env); break;
        case 0x071c: ALOGV("libandroid_ALooper_addFd"); nb_handle_libandroid_ALooper_addFd(env); break;
        case 0x071d: ALOGV("ALooper_forThread"); nb_handle_ALooper_forThread(env); break;
        case 0x071e: ALOGV("ALooper_pollAll"); nb_handle_ALooper_pollAll(env); break;
        case 0x071f: ALOGV("ALooper_pollOnce"); nb_handle_ALooper_pollOnce(env); break;
        case 0x0720: ALOGV("ALooper_prepare"); nb_handle_ALooper_prepare(env); break;
        case 0x0721: ALOGV("ALooper_release"); nb_handle_ALooper_release(env); break;
        case 0x0722: ALOGV("ALooper_removeFd"); nb_handle_ALooper_removeFd(env); break;
        case 0x0723: ALOGV("ALooper_wake"); nb_handle_ALooper_wake(env); break;
        case 0x0724: ALOGV("ASensorEventQueue_disableSensor"); nb_handle_ASensorEventQueue_disableSensor(env); break;
        case 0x0725: ALOGV("ASensorEventQueue_enableSensor"); nb_handle_ASensorEventQueue_enableSensor(env); break;
        case 0x0726: ALOGV("ASensorEventQueue_getEvents"); nb_handle_ASensorEventQueue_getEvents(env); break;
        case 0x0727: ALOGV("ASensorEventQueue_hasEvents"); nb_handle_ASensorEventQueue_hasEvents(env); break;
        case 0x0728: ALOGV("ASensorEventQueue_setEventRate"); nb_handle_ASensorEventQueue_setEventRate(env); break;
        case 0x0729: ALOGV("libandroid_ASensorManager_createEventQueue"); nb_handle_libandroid_ASensorManager_createEventQueue(env); break;
        case 0x072a: ALOGV("ASensorManager_destroyEventQueue"); nb_handle_ASensorManager_destroyEventQueue(env); break;
        case 0x072b: ALOGV("ASensorManager_getDefaultSensor"); nb_handle_ASensorManager_getDefaultSensor(env); break;
        case 0x072c: ALOGV("ASensorManager_getInstance"); nb_handle_ASensorManager_getInstance(env); break;
        case 0x072d: ALOGV("ASensorManager_getSensorList"); nb_handle_ASensorManager_getSensorList(env); break;
        case 0x072e: ALOGV("ASensor_getMinDelay"); nb_handle_ASensor_getMinDelay(env); break;
        case 0x072f: ALOGV("ASensor_getName"); nb_handle_ASensor_getName(env); break;
        case 0x0730: ALOGV("ASensor_getResolution"); nb_handle_ASensor_getResolution(env); break;
        case 0x0731: ALOGV("ASensor_getType"); nb_handle_ASensor_getType(env); break;
        case 0x0732: ALOGV("ASensor_getVendor"); nb_handle_ASensor_getVendor(env); break;
        case 0x0733: ALOGV("AConfiguration_delete"); nb_handle_AConfiguration_delete(env); break;
        case 0x0734: ALOGV("AConfiguration_fromAssetManager"); nb_handle_AConfiguration_fromAssetManager(env); break;
        case 0x0735: ALOGV("AConfiguration_getCountry"); nb_handle_AConfiguration_getCountry(env); break;
        case 0x0736: ALOGV("AConfiguration_getDensity"); nb_handle_AConfiguration_getDensity(env); break;
        case 0x0737: ALOGV("AConfiguration_getLanguage"); nb_handle_AConfiguration_getLanguage(env); break;
        case 0x0738: ALOGV("AConfiguration_new"); nb_handle_AConfiguration_new(env); break;
        case 0x0739: ALOGV("libandroid_AInputQueue_attachLooper"); nb_handle_libandroid_AInputQueue_attachLooper(env); break;
        case 0x073a: ALOGV("AInputQueue_detachLooper"); nb_handle_AInputQueue_detachLooper(env); break;
        case 0x073b: ALOGV("AInputQueue_finishEvent"); nb_handle_AInputQueue_finishEvent(env); break;
        case 0x073c: ALOGV("AInputQueue_getEvent"); nb_handle_AInputQueue_getEvent(env); break;
        case 0x073d: ALOGV("AInputQueue_preDispatchEvent"); nb_handle_AInputQueue_preDispatchEvent(env); break;
        case 0x073e: ALOGV("AInputEvent_getType"); nb_handle_AInputEvent_getType(env); break;
        case 0x073f: ALOGV("AMotionEvent_getAction"); nb_handle_AMotionEvent_getAction(env); break;
        case 0x0740: ALOGV("AMotionEvent_getDownTime"); nb_handle_AMotionEvent_getDownTime(env); break;
        case 0x0741: ALOGV("AMotionEvent_getEventTime"); nb_handle_AMotionEvent_getEventTime(env); break;
        case 0x0742: ALOGV("AMotionEvent_getPointerCount"); nb_handle_AMotionEvent_getPointerCount(env); break;
        case 0x0743: ALOGV("AMotionEvent_getPointerId"); nb_handle_AMotionEvent_getPointerId(env); break;
        case 0x0744: ALOGV("AMotionEvent_getX"); nb_handle_AMotionEvent_getX(env); break;
        case 0x0745: ALOGV("AMotionEvent_getY"); nb_handle_AMotionEvent_getY(env); break;
        default: LOG_ALWAYS_FATAL("Unknown SVC %08x", svc); break;
    }
}
