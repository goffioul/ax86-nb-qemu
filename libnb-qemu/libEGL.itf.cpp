#include <string.h>
#include <cutils/log.h>
#include "libEGL.itf.h"

typedef GLvoid (*glDiscardFramebufferEXT_t) (GLenum target, GLsizei numAttachments, const GLenum *attachments);

static struct {
    glDiscardFramebufferEXT_t glDiscardFramebufferEXT;
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
        } \
        return (void *) sFuncTable.name; \
    }
DEFINE_EXT(glDiscardFramebufferEXT)
#undef DEFINE_EXT
    else {
        ALOGE("Unsupported OpenGL extension: %s", fname);
        return nullptr;
    }
}

GLvoid libEGL_glDiscardFramebufferEXT (GLenum target, GLsizei numAttachments, const GLenum *attachments)
{
    if (sFuncTable.glDiscardFramebufferEXT) {
        sFuncTable.glDiscardFramebufferEXT(target, numAttachments, attachments);
    }
}
