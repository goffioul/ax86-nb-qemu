#ifndef LIBEGL_ITF_H_
#define LIBEGL_ITF_H_

#include <EGL/egl.h>
#include <GLES/gl.h>
#include <GLES/glext.h>

#ifdef __cplusplus
extern "C" {
#endif

const char* eglQueryStringImplementationANDROID(EGLDisplay dpy, EGLint name);
int _ZN7android18egl_get_init_countEPv(EGLDisplay dpy);
void _ZN7android22egl_set_cache_filenameEPKc (const char* filename);
void _Z13eglBeginFramePvS_ (EGLDisplay dpy, EGLSurface surface);

void* libEGL_eglGetProcAddress(const char *name);

void libEGL_glDiscardFramebufferEXT (GLenum target, GLsizei numAttachments, const GLenum *attachments);

void libEGL_glDebugMessageControlKHR (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
void libEGL_glDebugMessageInsertKHR (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
void libEGL_glPushDebugGroupKHR (GLenum source, GLuint id, GLsizei length, const GLchar *message);
void libEGL_glPopDebugGroupKHR (void);
void libEGL_glObjectLabelKHR (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
void libEGL_glGetObjectLabelKHR (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);

void libEGL_glInsertEventMarkerEXT (GLsizei length, const GLchar *marker);
void libEGL_glPushGroupMarkerEXT (GLsizei length, const GLchar *marker);
void libEGL_glPopGroupMarkerEXT (void);

void libEGL_glGetQueryObjectui64vEXT (GLuint id, GLenum pname, GLuint64 *params);

void libEGL_glCopyImageSubDataOES (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);

void libEGL_glDrawElementsBaseVertexOES (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
void libEGL_glDrawRangeElementsBaseVertexOES (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
void libEGL_glDrawElementsInstancedBaseVertexOES (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
void libEGL_glMultiDrawElementsBaseVertexEXT (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount, const GLint *basevertex);

void libEGL_glBlendBarrierKHR (void);

#ifdef __cplusplus
}
#endif

#endif
