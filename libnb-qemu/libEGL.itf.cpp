#define LOG_TAG "libnb-qemu"
//#define LOG_NDEBUG 0

#include <string.h>
#include <cutils/log.h>
#include "libEGL.itf.h"

typedef void (*glDiscardFramebufferEXT_t) (GLenum target, GLsizei numAttachments, const GLenum *attachments);
typedef void (*glDebugMessageControlKHR_t) (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled);
typedef void (*glDebugMessageInsertKHR_t) (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf);
typedef void (*glPushDebugGroupKHR_t) (GLenum source, GLuint id, GLsizei length, const GLchar *message);
typedef void (*glPopDebugGroupKHR_t) (void);
typedef void (*glObjectLabelKHR_t) (GLenum identifier, GLuint name, GLsizei length, const GLchar *label);
typedef void (*glGetObjectLabelKHR_t) (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label);
typedef void (*glInsertEventMarkerEXT_t) (GLsizei length, const GLchar *marker);
typedef void (*glPushGroupMarkerEXT_t) (GLsizei length, const GLchar *marker);
typedef void (*glPopGroupMarkerEXT_t) (void);
typedef void (*glGetQueryObjectui64vEXT_t) (GLuint id, GLenum pname, GLuint64 *params);
typedef void (*glCopyImageSubDataOES_t) (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth);
typedef void (*glDrawElementsBaseVertexOES_t) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (*glDrawRangeElementsBaseVertexOES_t) (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex);
typedef void (*glDrawElementsInstancedBaseVertexOES_t) (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex);
typedef void (*glMultiDrawElementsBaseVertexEXT_t) (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount, const GLint *basevertex);
typedef void (*glBlendBarrierKHR_t) (void);

static struct {
    // EXT_discard_framebuffer
    glDiscardFramebufferEXT_t glDiscardFramebufferEXT;
    // KHR_debug
    glDebugMessageControlKHR_t glDebugMessageControlKHR;
    glDebugMessageInsertKHR_t glDebugMessageInsertKHR;
    glPushDebugGroupKHR_t glPushDebugGroupKHR;
    glPopDebugGroupKHR_t glPopDebugGroupKHR;
    glObjectLabelKHR_t glObjectLabelKHR;
    glGetObjectLabelKHR_t glGetObjectLabelKHR;
    // EXT_debug_marker
    glInsertEventMarkerEXT_t glInsertEventMarkerEXT;
    glPushGroupMarkerEXT_t glPushGroupMarkerEXT;
    glPopGroupMarkerEXT_t glPopGroupMarkerEXT;
    // EXT_disjoint_timer_query
    glGetQueryObjectui64vEXT_t glGetQueryObjectui64vEXT;
    // OES_copy_image
    glCopyImageSubDataOES_t glCopyImageSubDataOES;
    // OES_draw_elements_base_vertex
    glDrawElementsBaseVertexOES_t glDrawElementsBaseVertexOES;
    glDrawRangeElementsBaseVertexOES_t glDrawRangeElementsBaseVertexOES;
    glDrawElementsInstancedBaseVertexOES_t glDrawElementsInstancedBaseVertexOES;
    glMultiDrawElementsBaseVertexEXT_t glMultiDrawElementsBaseVertexEXT;
    // KHR_blend_equation_advanced
    glBlendBarrierKHR_t glBlendBarrierKHR;
} sFuncTable;

void* libEGL_eglGetProcAddress(const char *fname)
{
    if (fname == nullptr) {
        return nullptr;
    }
#define DEFINE_EXT(name) \
    else if (strcmp(#name, fname) == 0) { \
        if (sFuncTable.name == nullptr) { \
            sFuncTable.name = (name ## _t) eglGetProcAddress(fname); \
            ALOGD("eglGetProcAddress(%s) => %p", #name, sFuncTable.name); \
        } \
        return (void *) sFuncTable.name; \
    }
DEFINE_EXT(glDiscardFramebufferEXT)
DEFINE_EXT(glDebugMessageControlKHR)
DEFINE_EXT(glDebugMessageInsertKHR)
DEFINE_EXT(glPushDebugGroupKHR)
DEFINE_EXT(glPopDebugGroupKHR)
DEFINE_EXT(glObjectLabelKHR)
DEFINE_EXT(glGetObjectLabelKHR)
DEFINE_EXT(glInsertEventMarkerEXT)
DEFINE_EXT(glPushGroupMarkerEXT)
DEFINE_EXT(glPopGroupMarkerEXT)
DEFINE_EXT(glGetQueryObjectui64vEXT)
DEFINE_EXT(glCopyImageSubDataOES)
DEFINE_EXT(glDrawElementsBaseVertexOES)
DEFINE_EXT(glDrawRangeElementsBaseVertexOES)
DEFINE_EXT(glDrawElementsInstancedBaseVertexOES)
DEFINE_EXT(glMultiDrawElementsBaseVertexEXT)
DEFINE_EXT(glBlendBarrierKHR)
#undef DEFINE_EXT
    else {
        ALOGE("Unsupported OpenGL extension: %s", fname);
        return nullptr;
    }
}

void libEGL_glDiscardFramebufferEXT (GLenum target, GLsizei numAttachments, const GLenum *attachments)
{
    if (sFuncTable.glDiscardFramebufferEXT) {
        sFuncTable.glDiscardFramebufferEXT(target, numAttachments, attachments);
    }
}

void libEGL_glDebugMessageControlKHR (GLenum source, GLenum type, GLenum severity, GLsizei count, const GLuint *ids, GLboolean enabled)
{
    if (sFuncTable.glDebugMessageControlKHR) {
        sFuncTable.glDebugMessageControlKHR(source, type, severity, count, ids, enabled);
    }
}

void libEGL_glDebugMessageInsertKHR (GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *buf)
{
    if (sFuncTable.glDebugMessageInsertKHR) {
        sFuncTable.glDebugMessageInsertKHR(source, type, id, severity, length, buf);
    }
}

void libEGL_glPushDebugGroupKHR (GLenum source, GLuint id, GLsizei length, const GLchar *message)
{
    if (sFuncTable.glPushDebugGroupKHR) {
        sFuncTable.glPushDebugGroupKHR(source, id, length, message);
    }
}

void libEGL_glPopDebugGroupKHR (void)
{
    if (sFuncTable.glPopDebugGroupKHR) {
        sFuncTable.glPopDebugGroupKHR();
    }
}

void libEGL_glObjectLabelKHR (GLenum identifier, GLuint name, GLsizei length, const GLchar *label)
{
    if (sFuncTable.glObjectLabelKHR) {
        sFuncTable.glObjectLabelKHR(identifier, name, length, label);
    }
}

void libEGL_glGetObjectLabelKHR (GLenum identifier, GLuint name, GLsizei bufSize, GLsizei *length, GLchar *label)
{
    if (sFuncTable.glGetObjectLabelKHR) {
        sFuncTable.glGetObjectLabelKHR(identifier, name, bufSize, length, label);
    }
}

void libEGL_glInsertEventMarkerEXT (GLsizei length, const GLchar *marker)
{
    if (sFuncTable.glInsertEventMarkerEXT) {
        sFuncTable.glInsertEventMarkerEXT(length, marker);
    }
}

void libEGL_glPushGroupMarkerEXT (GLsizei length, const GLchar *marker)
{
    if (sFuncTable.glPushGroupMarkerEXT) {
        sFuncTable.glPushGroupMarkerEXT(length, marker);
    }
}

void libEGL_glPopGroupMarkerEXT (void)
{
    if (sFuncTable.glPopGroupMarkerEXT) {
        sFuncTable.glPopGroupMarkerEXT();
    }
}

void libEGL_glGetQueryObjectui64vEXT (GLuint id, GLenum pname, GLuint64 *params)
{
    if (sFuncTable.glGetQueryObjectui64vEXT) {
        sFuncTable.glGetQueryObjectui64vEXT(id, pname, params);
    }
}

void libEGL_glCopyImageSubDataOES (GLuint srcName, GLenum srcTarget, GLint srcLevel, GLint srcX, GLint srcY, GLint srcZ, GLuint dstName, GLenum dstTarget, GLint dstLevel, GLint dstX, GLint dstY, GLint dstZ, GLsizei srcWidth, GLsizei srcHeight, GLsizei srcDepth)
{
    if (sFuncTable.glCopyImageSubDataOES) {
        sFuncTable.glCopyImageSubDataOES(srcName, srcTarget, srcLevel, srcX, srcY, srcZ, dstName, dstTarget, dstLevel, dstX, dstY, dstZ, srcWidth, srcHeight, srcDepth);
    }
}

void libEGL_glDrawElementsBaseVertexOES (GLenum mode, GLsizei count, GLenum type, const void *indices, GLint basevertex)
{
    if (sFuncTable.glDrawElementsBaseVertexOES) {
        sFuncTable.glDrawElementsBaseVertexOES(mode, count, type, indices, basevertex);
    }
}

void libEGL_glDrawRangeElementsBaseVertexOES (GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void *indices, GLint basevertex)
{
    if (sFuncTable.glDrawRangeElementsBaseVertexOES) {
        sFuncTable.glDrawRangeElementsBaseVertexOES(mode, start, end, count, type, indices, basevertex);
    }
}

void libEGL_glDrawElementsInstancedBaseVertexOES (GLenum mode, GLsizei count, GLenum type, const void *indices, GLsizei instancecount, GLint basevertex)
{
    if (sFuncTable.glDrawElementsInstancedBaseVertexOES) {
        sFuncTable.glDrawElementsInstancedBaseVertexOES(mode, count, type, indices, instancecount, basevertex);
    }
}

void libEGL_glMultiDrawElementsBaseVertexEXT (GLenum mode, const GLsizei *count, GLenum type, const void *const*indices, GLsizei primcount, const GLint *basevertex)
{
    if (sFuncTable.glMultiDrawElementsBaseVertexEXT) {
        sFuncTable.glMultiDrawElementsBaseVertexEXT(mode, count, type, indices, primcount, basevertex);
    }
}

void libEGL_glBlendBarrierKHR (void)
{
    if (sFuncTable.glBlendBarrierKHR) {
        sFuncTable.glBlendBarrierKHR();
    }
}
