#define LOG_TAG "libnb-qemu"
#define LOG_NDEBUG 0

#include <stdint.h>
#include <log/log.h>
#include "QemuInclude.h"
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <libEGL.def.h>

void nb_handle_eglChooseConfig(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglChooseConfig(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(EGLint*)(&sp[12]),
        *(void**)(&sp[16])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglCopyBuffers(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglCopyBuffers(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglCreateContext(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreateContext(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglCreatePbufferSurface(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreatePbufferSurface(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglCreatePixmapSurface(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreatePixmapSurface(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglCreateWindowSurface(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreateWindowSurface(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglDestroyContext(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglDestroyContext(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglDestroySurface(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglDestroySurface(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglGetConfigAttrib(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglGetConfigAttrib(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglGetConfigs(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglGetConfigs(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglGetCurrentDisplay(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglGetCurrentDisplay(
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglGetCurrentSurface(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglGetCurrentSurface(
        *(EGLint*)(&sp[0])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglGetDisplay(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglGetDisplay(
        *(void**)(&sp[0])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglGetError(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLint __nb_ret = (EGLint)eglGetError(
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_eglInitialize(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglInitialize(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglMakeCurrent(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglMakeCurrent(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglQueryContext(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglQueryContext(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglQueryString(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglQueryString(
        *(void**)(&sp[0]),
        *(EGLint*)(&sp[4])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglQuerySurface(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglQuerySurface(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglSwapBuffers(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglSwapBuffers(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglTerminate(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglTerminate(
        *(void**)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglWaitGL(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglWaitGL(
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglWaitNative(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglWaitNative(
        *(EGLint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglBindTexImage(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglBindTexImage(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglReleaseTexImage(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglReleaseTexImage(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglSurfaceAttrib(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglSurfaceAttrib(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8]),
        *(EGLint*)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglSwapInterval(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglSwapInterval(
        *(void**)(&sp[0]),
        *(EGLint*)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglBindAPI(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglBindAPI(
        *(EGLenum*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglQueryAPI(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLenum __nb_ret = (EGLenum)eglQueryAPI(
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_eglCreatePbufferFromClientBuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreatePbufferFromClientBuffer(
        *(void**)(&sp[0]),
        *(EGLenum*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglReleaseThread(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglReleaseThread(
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglWaitClient(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglWaitClient(
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglGetCurrentContext(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglGetCurrentContext(
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglCreateSync(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreateSync(
        *(void**)(&sp[0]),
        *(EGLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglDestroySync(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglDestroySync(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglClientWaitSync(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLint __nb_ret = (EGLint)eglClientWaitSync(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8]),
        *(EGLTime*)(&sp[16])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_eglGetSyncAttrib(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglGetSyncAttrib(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglCreateImage(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreateImage(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLenum*)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglDestroyImage(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglDestroyImage(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglGetPlatformDisplay(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglGetPlatformDisplay(
        *(EGLenum*)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglCreatePlatformWindowSurface(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreatePlatformWindowSurface(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglCreatePlatformPixmapSurface(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreatePlatformPixmapSurface(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglWaitSync(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglWaitSync(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglCreateSyncKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreateSyncKHR(
        *(void**)(&sp[0]),
        *(EGLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglDestroySyncKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglDestroySyncKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglClientWaitSyncKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLint __nb_ret = (EGLint)eglClientWaitSyncKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8]),
        *(EGLTimeKHR*)(&sp[16])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_eglGetSyncAttribKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglGetSyncAttribKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglCreateImageKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreateImageKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLenum*)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglDestroyImageKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglDestroyImageKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglSetDamageRegionKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglSetDamageRegionKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(EGLint*)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglSwapBuffersWithDamageKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglSwapBuffersWithDamageKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(EGLint*)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglCreateStreamKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreateStreamKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglDestroyStreamKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglDestroyStreamKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglStreamAttribKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglStreamAttribKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLenum*)(&sp[8]),
        *(EGLint*)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglQueryStreamKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglQueryStreamKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLenum*)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglQueryStreamu64KHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglQueryStreamu64KHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLenum*)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglCreateStreamFromFileDescriptorKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreateStreamFromFileDescriptorKHR(
        *(void**)(&sp[0]),
        *(EGLNativeFileDescriptorKHR*)(&sp[4])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglGetStreamFileDescriptorKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLNativeFileDescriptorKHR __nb_ret = (EGLNativeFileDescriptorKHR)eglGetStreamFileDescriptorKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_eglQueryStreamTimeKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglQueryStreamTimeKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLenum*)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglCreateStreamProducerSurfaceKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglCreateStreamProducerSurfaceKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglStreamConsumerGLTextureExternalKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglStreamConsumerGLTextureExternalKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglStreamConsumerAcquireKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglStreamConsumerAcquireKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglStreamConsumerReleaseKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglStreamConsumerReleaseKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglDupNativeFenceFDANDROID(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLint __nb_ret = (EGLint)eglDupNativeFenceFDANDROID(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_eglWaitSyncKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLint __nb_ret = (EGLint)eglWaitSyncKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_eglSignalSyncKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglSignalSyncKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLenum*)(&sp[8])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglLockSurfaceKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglLockSurfaceKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglUnlockSurfaceKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglUnlockSurfaceKHR(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglPresentationTimeANDROID(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglPresentationTimeANDROID(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLnsecsANDROID*)(&sp[8])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglQueryStringImplementationANDROID(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglQueryStringImplementationANDROID(
        *(void**)(&sp[0]),
        *(EGLint*)(&sp[4])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglGetNativeClientBufferANDROID(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)eglGetNativeClientBufferANDROID(
        *(void**)(&sp[0])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_eglGetCompositorTimingSupportedANDROID(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglGetCompositorTimingSupportedANDROID(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglGetCompositorTimingANDROID(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglGetCompositorTimingANDROID(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglGetNextFrameIdANDROID(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglGetNextFrameIdANDROID(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglGetFrameTimestampSupportedANDROID(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglGetFrameTimestampSupportedANDROID(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLint*)(&sp[8])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglGetFrameTimestampsANDROID(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLBoolean __nb_ret = (EGLBoolean)eglGetFrameTimestampsANDROID(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(EGLuint64KHR*)(&sp[8]),
        *(EGLint*)(&sp[16]),
        *(void**)(&sp[20]),
        *(void**)(&sp[24])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_eglGetSystemTimeFrequencyNV(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLuint64NV __nb_ret = (EGLuint64NV)eglGetSystemTimeFrequencyNV(
    );
    env->regs[0] = __nb_ret & 0xffffffff;
    env->regs[1] = (__nb_ret >> 32) & 0xffffffff;
}
void nb_handle_eglGetSystemTimeNV(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    EGLuint64NV __nb_ret = (EGLuint64NV)eglGetSystemTimeNV(
    );
    env->regs[0] = __nb_ret & 0xffffffff;
    env->regs[1] = (__nb_ret >> 32) & 0xffffffff;
}
void nb_handle__ZN7android18egl_get_init_countEPv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    int __nb_ret = (int)_ZN7android18egl_get_init_countEPv(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle__ZN7android22egl_set_cache_filenameEPKc(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    _ZN7android22egl_set_cache_filenameEPKc(
        *(void**)(&sp[0])
    );
}
void nb_handle__Z13eglBeginFramePvS_(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    _Z13eglBeginFramePvS_(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
}
__attribute__((visibility("default")))
void nb_handle_svc(CPUARMState *env, int svc) {
    switch (svc) {
        case 0x0100: ALOGV("eglChooseConfig"); nb_handle_eglChooseConfig(env); break;
        case 0x0101: ALOGV("eglCopyBuffers"); nb_handle_eglCopyBuffers(env); break;
        case 0x0102: ALOGV("eglCreateContext"); nb_handle_eglCreateContext(env); break;
        case 0x0103: ALOGV("eglCreatePbufferSurface"); nb_handle_eglCreatePbufferSurface(env); break;
        case 0x0104: ALOGV("eglCreatePixmapSurface"); nb_handle_eglCreatePixmapSurface(env); break;
        case 0x0105: ALOGV("eglCreateWindowSurface"); nb_handle_eglCreateWindowSurface(env); break;
        case 0x0106: ALOGV("eglDestroyContext"); nb_handle_eglDestroyContext(env); break;
        case 0x0107: ALOGV("eglDestroySurface"); nb_handle_eglDestroySurface(env); break;
        case 0x0108: ALOGV("eglGetConfigAttrib"); nb_handle_eglGetConfigAttrib(env); break;
        case 0x0109: ALOGV("eglGetConfigs"); nb_handle_eglGetConfigs(env); break;
        case 0x010a: ALOGV("eglGetCurrentDisplay"); nb_handle_eglGetCurrentDisplay(env); break;
        case 0x010b: ALOGV("eglGetCurrentSurface"); nb_handle_eglGetCurrentSurface(env); break;
        case 0x010c: ALOGV("eglGetDisplay"); nb_handle_eglGetDisplay(env); break;
        case 0x010d: ALOGV("eglGetError"); nb_handle_eglGetError(env); break;
        case 0x010e: ALOGV("eglInitialize"); nb_handle_eglInitialize(env); break;
        case 0x010f: ALOGV("eglMakeCurrent"); nb_handle_eglMakeCurrent(env); break;
        case 0x0110: ALOGV("eglQueryContext"); nb_handle_eglQueryContext(env); break;
        case 0x0111: ALOGV("eglQueryString"); nb_handle_eglQueryString(env); break;
        case 0x0112: ALOGV("eglQuerySurface"); nb_handle_eglQuerySurface(env); break;
        case 0x0113: ALOGV("eglSwapBuffers"); nb_handle_eglSwapBuffers(env); break;
        case 0x0114: ALOGV("eglTerminate"); nb_handle_eglTerminate(env); break;
        case 0x0115: ALOGV("eglWaitGL"); nb_handle_eglWaitGL(env); break;
        case 0x0116: ALOGV("eglWaitNative"); nb_handle_eglWaitNative(env); break;
        case 0x0117: ALOGV("eglBindTexImage"); nb_handle_eglBindTexImage(env); break;
        case 0x0118: ALOGV("eglReleaseTexImage"); nb_handle_eglReleaseTexImage(env); break;
        case 0x0119: ALOGV("eglSurfaceAttrib"); nb_handle_eglSurfaceAttrib(env); break;
        case 0x011a: ALOGV("eglSwapInterval"); nb_handle_eglSwapInterval(env); break;
        case 0x011b: ALOGV("eglBindAPI"); nb_handle_eglBindAPI(env); break;
        case 0x011c: ALOGV("eglQueryAPI"); nb_handle_eglQueryAPI(env); break;
        case 0x011d: ALOGV("eglCreatePbufferFromClientBuffer"); nb_handle_eglCreatePbufferFromClientBuffer(env); break;
        case 0x011e: ALOGV("eglReleaseThread"); nb_handle_eglReleaseThread(env); break;
        case 0x011f: ALOGV("eglWaitClient"); nb_handle_eglWaitClient(env); break;
        case 0x0120: ALOGV("eglGetCurrentContext"); nb_handle_eglGetCurrentContext(env); break;
        case 0x0121: ALOGV("eglCreateSync"); nb_handle_eglCreateSync(env); break;
        case 0x0122: ALOGV("eglDestroySync"); nb_handle_eglDestroySync(env); break;
        case 0x0123: ALOGV("eglClientWaitSync"); nb_handle_eglClientWaitSync(env); break;
        case 0x0124: ALOGV("eglGetSyncAttrib"); nb_handle_eglGetSyncAttrib(env); break;
        case 0x0125: ALOGV("eglCreateImage"); nb_handle_eglCreateImage(env); break;
        case 0x0126: ALOGV("eglDestroyImage"); nb_handle_eglDestroyImage(env); break;
        case 0x0127: ALOGV("eglGetPlatformDisplay"); nb_handle_eglGetPlatformDisplay(env); break;
        case 0x0128: ALOGV("eglCreatePlatformWindowSurface"); nb_handle_eglCreatePlatformWindowSurface(env); break;
        case 0x0129: ALOGV("eglCreatePlatformPixmapSurface"); nb_handle_eglCreatePlatformPixmapSurface(env); break;
        case 0x012a: ALOGV("eglWaitSync"); nb_handle_eglWaitSync(env); break;
        case 0x012b: ALOGV("eglCreateSyncKHR"); nb_handle_eglCreateSyncKHR(env); break;
        case 0x012c: ALOGV("eglDestroySyncKHR"); nb_handle_eglDestroySyncKHR(env); break;
        case 0x012d: ALOGV("eglClientWaitSyncKHR"); nb_handle_eglClientWaitSyncKHR(env); break;
        case 0x012e: ALOGV("eglGetSyncAttribKHR"); nb_handle_eglGetSyncAttribKHR(env); break;
        case 0x012f: ALOGV("eglCreateImageKHR"); nb_handle_eglCreateImageKHR(env); break;
        case 0x0130: ALOGV("eglDestroyImageKHR"); nb_handle_eglDestroyImageKHR(env); break;
        case 0x0131: ALOGV("eglSetDamageRegionKHR"); nb_handle_eglSetDamageRegionKHR(env); break;
        case 0x0132: ALOGV("eglSwapBuffersWithDamageKHR"); nb_handle_eglSwapBuffersWithDamageKHR(env); break;
        case 0x0133: ALOGV("eglCreateStreamKHR"); nb_handle_eglCreateStreamKHR(env); break;
        case 0x0134: ALOGV("eglDestroyStreamKHR"); nb_handle_eglDestroyStreamKHR(env); break;
        case 0x0135: ALOGV("eglStreamAttribKHR"); nb_handle_eglStreamAttribKHR(env); break;
        case 0x0136: ALOGV("eglQueryStreamKHR"); nb_handle_eglQueryStreamKHR(env); break;
        case 0x0137: ALOGV("eglQueryStreamu64KHR"); nb_handle_eglQueryStreamu64KHR(env); break;
        case 0x0138: ALOGV("eglCreateStreamFromFileDescriptorKHR"); nb_handle_eglCreateStreamFromFileDescriptorKHR(env); break;
        case 0x0139: ALOGV("eglGetStreamFileDescriptorKHR"); nb_handle_eglGetStreamFileDescriptorKHR(env); break;
        case 0x013a: ALOGV("eglQueryStreamTimeKHR"); nb_handle_eglQueryStreamTimeKHR(env); break;
        case 0x013b: ALOGV("eglCreateStreamProducerSurfaceKHR"); nb_handle_eglCreateStreamProducerSurfaceKHR(env); break;
        case 0x013c: ALOGV("eglStreamConsumerGLTextureExternalKHR"); nb_handle_eglStreamConsumerGLTextureExternalKHR(env); break;
        case 0x013d: ALOGV("eglStreamConsumerAcquireKHR"); nb_handle_eglStreamConsumerAcquireKHR(env); break;
        case 0x013e: ALOGV("eglStreamConsumerReleaseKHR"); nb_handle_eglStreamConsumerReleaseKHR(env); break;
        case 0x013f: ALOGV("eglDupNativeFenceFDANDROID"); nb_handle_eglDupNativeFenceFDANDROID(env); break;
        case 0x0140: ALOGV("eglWaitSyncKHR"); nb_handle_eglWaitSyncKHR(env); break;
        case 0x0141: ALOGV("eglSignalSyncKHR"); nb_handle_eglSignalSyncKHR(env); break;
        case 0x0142: ALOGV("eglLockSurfaceKHR"); nb_handle_eglLockSurfaceKHR(env); break;
        case 0x0143: ALOGV("eglUnlockSurfaceKHR"); nb_handle_eglUnlockSurfaceKHR(env); break;
        case 0x0144: ALOGV("eglPresentationTimeANDROID"); nb_handle_eglPresentationTimeANDROID(env); break;
        case 0x0145: ALOGV("eglQueryStringImplementationANDROID"); nb_handle_eglQueryStringImplementationANDROID(env); break;
        case 0x0146: ALOGV("eglGetNativeClientBufferANDROID"); nb_handle_eglGetNativeClientBufferANDROID(env); break;
        case 0x0147: ALOGV("eglGetCompositorTimingSupportedANDROID"); nb_handle_eglGetCompositorTimingSupportedANDROID(env); break;
        case 0x0148: ALOGV("eglGetCompositorTimingANDROID"); nb_handle_eglGetCompositorTimingANDROID(env); break;
        case 0x0149: ALOGV("eglGetNextFrameIdANDROID"); nb_handle_eglGetNextFrameIdANDROID(env); break;
        case 0x014a: ALOGV("eglGetFrameTimestampSupportedANDROID"); nb_handle_eglGetFrameTimestampSupportedANDROID(env); break;
        case 0x014b: ALOGV("eglGetFrameTimestampsANDROID"); nb_handle_eglGetFrameTimestampsANDROID(env); break;
        case 0x014c: ALOGV("eglGetSystemTimeFrequencyNV"); nb_handle_eglGetSystemTimeFrequencyNV(env); break;
        case 0x014d: ALOGV("eglGetSystemTimeNV"); nb_handle_eglGetSystemTimeNV(env); break;
        case 0x014e: ALOGV("_ZN7android18egl_get_init_countEPv"); nb_handle__ZN7android18egl_get_init_countEPv(env); break;
        case 0x014f: ALOGV("_ZN7android22egl_set_cache_filenameEPKc"); nb_handle__ZN7android22egl_set_cache_filenameEPKc(env); break;
        case 0x0150: ALOGV("_Z13eglBeginFramePvS_"); nb_handle__Z13eglBeginFramePvS_(env); break;
        default: LOG_ALWAYS_FATAL("Unknown SVC %08x", svc); break;
    }
}
