#ifndef LIBEGL_ITF_H_
#define LIBEGL_ITF_H_

#include <EGL/egl.h>
#include <GLES/gl.h>

#ifdef __cplusplus
extern "C" {
#endif

const char* eglQueryStringImplementationANDROID(EGLDisplay dpy, EGLint name);
int _ZN7android18egl_get_init_countEPv(EGLDisplay dpy);
void _ZN7android22egl_set_cache_filenameEPKc (const char* filename);
void _Z13eglBeginFramePvS_ (EGLDisplay dpy, EGLSurface surface);

void* libEGL_eglGetProcAddress(const char *name);
GLvoid libEGL_glDiscardFramebufferEXT (GLenum target, GLsizei numAttachments, const GLenum *attachments);

#ifdef __cplusplus
}
#endif

#endif
