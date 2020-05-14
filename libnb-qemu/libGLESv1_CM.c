#define LOG_TAG "libnb-qemu"
//#define LOG_NDEBUG 0

#include <stdint.h>
#include <log/log.h>
#include "QemuInclude.h"
#include <GLES/gl.h>
#include <GLES/glext.h>
#include <libGLESv1_CM.def.h>

void nb_handle_glAlphaFunc(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glAlphaFunc(
        *(GLenum*)(&sp[0]),
        *(GLfloat*)(&sp[4])
    );
}
void nb_handle_glClearColor(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearColor(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12])
    );
}
void nb_handle_glClearDepthf(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearDepthf(
        *(GLfloat*)(&sp[0])
    );
}
void nb_handle_glClipPlanef(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClipPlanef(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glColor4f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glColor4f(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12])
    );
}
void nb_handle_glDepthRangef(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDepthRangef(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4])
    );
}
void nb_handle_glFogf(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFogf(
        *(GLenum*)(&sp[0]),
        *(GLfloat*)(&sp[4])
    );
}
void nb_handle_glFogfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFogfv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glFrustumf(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFrustumf(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12]),
        *(GLfloat*)(&sp[16]),
        *(GLfloat*)(&sp[20])
    );
}
void nb_handle_glGetClipPlanef(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetClipPlanef(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetFloatv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetFloatv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetLightfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetLightfv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetMaterialfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetMaterialfv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetTexEnvfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexEnvfv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetTexParameterfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexParameterfv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glLightModelf(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLightModelf(
        *(GLenum*)(&sp[0]),
        *(GLfloat*)(&sp[4])
    );
}
void nb_handle_glLightModelfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLightModelfv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glLightf(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLightf(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfloat*)(&sp[8])
    );
}
void nb_handle_glLightfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLightfv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glLineWidth(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLineWidth(
        *(GLfloat*)(&sp[0])
    );
}
void nb_handle_glLoadMatrixf(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLoadMatrixf(
        *(void**)(&sp[0])
    );
}
void nb_handle_glMaterialf(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMaterialf(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfloat*)(&sp[8])
    );
}
void nb_handle_glMaterialfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMaterialfv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glMultMatrixf(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMultMatrixf(
        *(void**)(&sp[0])
    );
}
void nb_handle_glMultiTexCoord4f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMultiTexCoord4f(
        *(GLenum*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12]),
        *(GLfloat*)(&sp[16])
    );
}
void nb_handle_glNormal3f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glNormal3f(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8])
    );
}
void nb_handle_glOrthof(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glOrthof(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12]),
        *(GLfloat*)(&sp[16]),
        *(GLfloat*)(&sp[20])
    );
}
void nb_handle_glPointParameterf(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPointParameterf(
        *(GLenum*)(&sp[0]),
        *(GLfloat*)(&sp[4])
    );
}
void nb_handle_glPointParameterfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPointParameterfv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glPointSize(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPointSize(
        *(GLfloat*)(&sp[0])
    );
}
void nb_handle_glPolygonOffset(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPolygonOffset(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4])
    );
}
void nb_handle_glRotatef(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glRotatef(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12])
    );
}
void nb_handle_glScalef(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glScalef(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8])
    );
}
void nb_handle_glTexEnvf(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexEnvf(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfloat*)(&sp[8])
    );
}
void nb_handle_glTexEnvfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexEnvfv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTexParameterf(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameterf(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfloat*)(&sp[8])
    );
}
void nb_handle_glTexParameterfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameterfv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTranslatef(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTranslatef(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8])
    );
}
void nb_handle_glActiveTexture(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glActiveTexture(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glAlphaFuncx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glAlphaFuncx(
        *(GLenum*)(&sp[0]),
        *(GLfixed*)(&sp[4])
    );
}
void nb_handle_glBindBuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindBuffer(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glBindTexture(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindTexture(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glBlendFunc(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendFunc(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4])
    );
}
void nb_handle_glBufferData(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBufferData(
        *(GLenum*)(&sp[0]),
        *(GLsizeiptr*)(&sp[4]),
        *(void**)(&sp[8]),
        *(GLenum*)(&sp[12])
    );
}
void nb_handle_glBufferSubData(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBufferSubData(
        *(GLenum*)(&sp[0]),
        *(GLintptr*)(&sp[4]),
        *(GLsizeiptr*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glClear(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClear(
        *(GLbitfield*)(&sp[0])
    );
}
void nb_handle_glClearColorx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearColorx(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12])
    );
}
void nb_handle_glClearDepthx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearDepthx(
        *(GLfixed*)(&sp[0])
    );
}
void nb_handle_glClearStencil(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearStencil(
        *(GLint*)(&sp[0])
    );
}
void nb_handle_glClientActiveTexture(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClientActiveTexture(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glClipPlanex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClipPlanex(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glColor4ub(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glColor4ub(
        *(GLubyte*)(&sp[0]),
        *(GLubyte*)(&sp[4]),
        *(GLubyte*)(&sp[8]),
        *(GLubyte*)(&sp[12])
    );
}
void nb_handle_glColor4x(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glColor4x(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12])
    );
}
void nb_handle_glColorMask(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glColorMask(
        *(GLboolean*)(&sp[0]),
        *(GLboolean*)(&sp[4]),
        *(GLboolean*)(&sp[8]),
        *(GLboolean*)(&sp[12])
    );
}
void nb_handle_glColorPointer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glColorPointer(
        *(GLint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glCompressedTexImage2D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCompressedTexImage2D(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(GLint*)(&sp[20]),
        *(GLsizei*)(&sp[24]),
        *(void**)(&sp[28])
    );
}
void nb_handle_glCompressedTexSubImage2D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCompressedTexSubImage2D(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(GLsizei*)(&sp[20]),
        *(GLenum*)(&sp[24]),
        *(GLsizei*)(&sp[28]),
        *(void**)(&sp[32])
    );
}
void nb_handle_glCopyTexImage2D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCopyTexImage2D(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16]),
        *(GLsizei*)(&sp[20]),
        *(GLsizei*)(&sp[24]),
        *(GLint*)(&sp[28])
    );
}
void nb_handle_glCopyTexSubImage2D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCopyTexSubImage2D(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16]),
        *(GLint*)(&sp[20]),
        *(GLsizei*)(&sp[24]),
        *(GLsizei*)(&sp[28])
    );
}
void nb_handle_glCullFace(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCullFace(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glDeleteBuffers(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteBuffers(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glDeleteTextures(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteTextures(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glDepthFunc(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDepthFunc(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glDepthMask(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDepthMask(
        *(GLboolean*)(&sp[0])
    );
}
void nb_handle_glDepthRangex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDepthRangex(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4])
    );
}
void nb_handle_glDisable(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDisable(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glDisableClientState(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDisableClientState(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glDrawArrays(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawArrays(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8])
    );
}
void nb_handle_glDrawElements(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawElements(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glEnable(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glEnable(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glEnableClientState(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glEnableClientState(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glFinish(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFinish(
    );
}
void nb_handle_glFlush(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFlush(
    );
}
void nb_handle_glFogx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFogx(
        *(GLenum*)(&sp[0]),
        *(GLfixed*)(&sp[4])
    );
}
void nb_handle_glFogxv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFogxv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glFrontFace(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFrontFace(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glFrustumx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFrustumx(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12]),
        *(GLfixed*)(&sp[16]),
        *(GLfixed*)(&sp[20])
    );
}
void nb_handle_glGetBooleanv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetBooleanv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetBufferParameteriv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetBufferParameteriv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetClipPlanex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetClipPlanex(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGenBuffers(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenBuffers(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGenTextures(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenTextures(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetError(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLenum __nb_ret = (GLenum)glGetError(
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glGetFixedv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetFixedv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetIntegerv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetIntegerv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetLightxv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetLightxv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetMaterialxv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetMaterialxv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetPointerv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetPointerv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetString(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)glGetString(
        *(GLenum*)(&sp[0])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_glGetTexEnviv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexEnviv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetTexEnvxv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexEnvxv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetTexParameteriv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexParameteriv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetTexParameterxv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexParameterxv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glHint(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glHint(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4])
    );
}
void nb_handle_glIsBuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsBuffer(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glIsEnabled(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsEnabled(
        *(GLenum*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glIsTexture(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsTexture(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glLightModelx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLightModelx(
        *(GLenum*)(&sp[0]),
        *(GLfixed*)(&sp[4])
    );
}
void nb_handle_glLightModelxv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLightModelxv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glLightx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLightx(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glLightxv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLightxv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glLineWidthx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLineWidthx(
        *(GLfixed*)(&sp[0])
    );
}
void nb_handle_glLoadIdentity(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLoadIdentity(
    );
}
void nb_handle_glLoadMatrixx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLoadMatrixx(
        *(void**)(&sp[0])
    );
}
void nb_handle_glLogicOp(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLogicOp(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glMaterialx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMaterialx(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glMaterialxv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMaterialxv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glMatrixMode(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMatrixMode(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glMultMatrixx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMultMatrixx(
        *(void**)(&sp[0])
    );
}
void nb_handle_glMultiTexCoord4x(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMultiTexCoord4x(
        *(GLenum*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12]),
        *(GLfixed*)(&sp[16])
    );
}
void nb_handle_glNormal3x(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glNormal3x(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glNormalPointer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glNormalPointer(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glOrthox(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glOrthox(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12]),
        *(GLfixed*)(&sp[16]),
        *(GLfixed*)(&sp[20])
    );
}
void nb_handle_glPixelStorei(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPixelStorei(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4])
    );
}
void nb_handle_glPointParameterx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPointParameterx(
        *(GLenum*)(&sp[0]),
        *(GLfixed*)(&sp[4])
    );
}
void nb_handle_glPointParameterxv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPointParameterxv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glPointSizex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPointSizex(
        *(GLfixed*)(&sp[0])
    );
}
void nb_handle_glPolygonOffsetx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPolygonOffsetx(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4])
    );
}
void nb_handle_glPopMatrix(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPopMatrix(
    );
}
void nb_handle_glPushMatrix(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPushMatrix(
    );
}
void nb_handle_glReadPixels(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glReadPixels(
        *(GLint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLenum*)(&sp[16]),
        *(GLenum*)(&sp[20]),
        *(void**)(&sp[24])
    );
}
void nb_handle_glRotatex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glRotatex(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12])
    );
}
void nb_handle_glSampleCoverage(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSampleCoverage(
        *(GLfloat*)(&sp[0]),
        *(GLboolean*)(&sp[4])
    );
}
void nb_handle_glSampleCoveragex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSampleCoveragex(
        *(GLclampx*)(&sp[0]),
        *(GLboolean*)(&sp[4])
    );
}
void nb_handle_glScalex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glScalex(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glScissor(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glScissor(
        *(GLint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLsizei*)(&sp[12])
    );
}
void nb_handle_glShadeModel(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glShadeModel(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glStencilFunc(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glStencilFunc(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLuint*)(&sp[8])
    );
}
void nb_handle_glStencilMask(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glStencilMask(
        *(GLuint*)(&sp[0])
    );
}
void nb_handle_glStencilOp(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glStencilOp(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8])
    );
}
void nb_handle_glTexCoordPointer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexCoordPointer(
        *(GLint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glTexEnvi(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexEnvi(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLint*)(&sp[8])
    );
}
void nb_handle_glTexEnvx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexEnvx(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glTexEnviv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexEnviv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTexEnvxv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexEnvxv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTexImage2D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexImage2D(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(GLint*)(&sp[20]),
        *(GLenum*)(&sp[24]),
        *(GLenum*)(&sp[28]),
        *(void**)(&sp[32])
    );
}
void nb_handle_glTexParameteri(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameteri(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLint*)(&sp[8])
    );
}
void nb_handle_glTexParameterx(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameterx(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glTexParameteriv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameteriv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTexParameterxv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameterxv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTexSubImage2D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexSubImage2D(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(GLsizei*)(&sp[20]),
        *(GLenum*)(&sp[24]),
        *(GLenum*)(&sp[28]),
        *(void**)(&sp[32])
    );
}
void nb_handle_glTranslatex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTranslatex(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glVertexPointer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexPointer(
        *(GLint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glViewport(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glViewport(
        *(GLint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLsizei*)(&sp[12])
    );
}
void nb_handle_glPointSizePointerOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPointSizePointerOES(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glEGLImageTargetTexture2DOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glEGLImageTargetTexture2DOES(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glEGLImageTargetRenderbufferStorageOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glEGLImageTargetRenderbufferStorageOES(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glQueryMatrixxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLbitfield __nb_ret = (GLbitfield)glQueryMatrixxOES(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glAlphaFuncxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glAlphaFuncxOES(
        *(GLenum*)(&sp[0]),
        *(GLfixed*)(&sp[4])
    );
}
void nb_handle_glClearColorxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearColorxOES(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12])
    );
}
void nb_handle_glClearDepthxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearDepthxOES(
        *(GLfixed*)(&sp[0])
    );
}
void nb_handle_glClipPlanexOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClipPlanexOES(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glColor4xOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glColor4xOES(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12])
    );
}
void nb_handle_glDepthRangexOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDepthRangexOES(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4])
    );
}
void nb_handle_glFogxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFogxOES(
        *(GLenum*)(&sp[0]),
        *(GLfixed*)(&sp[4])
    );
}
void nb_handle_glFogxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFogxvOES(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glFrustumxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFrustumxOES(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12]),
        *(GLfixed*)(&sp[16]),
        *(GLfixed*)(&sp[20])
    );
}
void nb_handle_glGetClipPlanexOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetClipPlanexOES(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetFixedvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetFixedvOES(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetTexEnvxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexEnvxvOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetTexParameterxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexParameterxvOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glLightModelxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLightModelxOES(
        *(GLenum*)(&sp[0]),
        *(GLfixed*)(&sp[4])
    );
}
void nb_handle_glLightModelxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLightModelxvOES(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glLightxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLightxOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glLightxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLightxvOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glLineWidthxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLineWidthxOES(
        *(GLfixed*)(&sp[0])
    );
}
void nb_handle_glLoadMatrixxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLoadMatrixxOES(
        *(void**)(&sp[0])
    );
}
void nb_handle_glMaterialxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMaterialxOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glMaterialxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMaterialxvOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glMultMatrixxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMultMatrixxOES(
        *(void**)(&sp[0])
    );
}
void nb_handle_glMultiTexCoord4xOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMultiTexCoord4xOES(
        *(GLenum*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12]),
        *(GLfixed*)(&sp[16])
    );
}
void nb_handle_glNormal3xOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glNormal3xOES(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glOrthoxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glOrthoxOES(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12]),
        *(GLfixed*)(&sp[16]),
        *(GLfixed*)(&sp[20])
    );
}
void nb_handle_glPointParameterxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPointParameterxvOES(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glPointSizexOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPointSizexOES(
        *(GLfixed*)(&sp[0])
    );
}
void nb_handle_glPolygonOffsetxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPolygonOffsetxOES(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4])
    );
}
void nb_handle_glRotatexOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glRotatexOES(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12])
    );
}
void nb_handle_glScalexOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glScalexOES(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glTexEnvxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexEnvxOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glTexEnvxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexEnvxvOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTexParameterxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameterxOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glTexParameterxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameterxvOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTranslatexOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTranslatexOES(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glGetLightxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetLightxvOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetMaterialxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetMaterialxvOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glPointParameterxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPointParameterxOES(
        *(GLenum*)(&sp[0]),
        *(GLfixed*)(&sp[4])
    );
}
void nb_handle_glSampleCoveragexOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSampleCoveragexOES(
        *(GLclampx*)(&sp[0]),
        *(GLboolean*)(&sp[4])
    );
}
void nb_handle_glGetTexGenxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexGenxvOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTexGenxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexGenxOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfixed*)(&sp[8])
    );
}
void nb_handle_glTexGenxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexGenxvOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glColorPointerBounds(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glColorPointerBounds(
        *(GLint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12]),
        *(GLsizei*)(&sp[16])
    );
}
void nb_handle_glNormalPointerBounds(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glNormalPointerBounds(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(GLsizei*)(&sp[12])
    );
}
void nb_handle_glTexCoordPointerBounds(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexCoordPointerBounds(
        *(GLint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12]),
        *(GLsizei*)(&sp[16])
    );
}
void nb_handle_glVertexPointerBounds(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexPointerBounds(
        *(GLint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12]),
        *(GLsizei*)(&sp[16])
    );
}
void nb_handle_glPointSizePointerOESBounds(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPointSizePointerOESBounds(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(GLsizei*)(&sp[12])
    );
}
void nb_handle_glMatrixIndexPointerOESBounds(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMatrixIndexPointerOESBounds(
        *(GLint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12]),
        *(GLsizei*)(&sp[16])
    );
}
void nb_handle_glWeightPointerOESBounds(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glWeightPointerOESBounds(
        *(GLint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12]),
        *(GLsizei*)(&sp[16])
    );
}
void nb_handle_glIsRenderbufferOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsRenderbufferOES(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glBindRenderbufferOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindRenderbufferOES(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glDeleteRenderbuffersOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteRenderbuffersOES(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGenRenderbuffersOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenRenderbuffersOES(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glRenderbufferStorageOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glRenderbufferStorageOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLsizei*)(&sp[12])
    );
}
void nb_handle_glGetRenderbufferParameterivOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetRenderbufferParameterivOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glIsFramebufferOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsFramebufferOES(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glBindFramebufferOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindFramebufferOES(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glDeleteFramebuffersOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteFramebuffersOES(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGenFramebuffersOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenFramebuffersOES(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glCheckFramebufferStatusOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLenum __nb_ret = (GLenum)glCheckFramebufferStatusOES(
        *(GLenum*)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glFramebufferRenderbufferOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFramebufferRenderbufferOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLuint*)(&sp[12])
    );
}
void nb_handle_glFramebufferTexture2DOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFramebufferTexture2DOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLuint*)(&sp[12]),
        *(GLint*)(&sp[16])
    );
}
void nb_handle_glGetFramebufferAttachmentParameterivOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetFramebufferAttachmentParameterivOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGenerateMipmapOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenerateMipmapOES(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glCurrentPaletteMatrixOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCurrentPaletteMatrixOES(
        *(GLuint*)(&sp[0])
    );
}
void nb_handle_glLoadPaletteFromModelViewMatrixOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLoadPaletteFromModelViewMatrixOES(
    );
}
void nb_handle_glMatrixIndexPointerOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMatrixIndexPointerOES(
        *(GLint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glWeightPointerOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glWeightPointerOES(
        *(GLint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glBindVertexArrayOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindVertexArrayOES(
        *(GLuint*)(&sp[0])
    );
}
void nb_handle_glDeleteVertexArraysOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteVertexArraysOES(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGenVertexArraysOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenVertexArraysOES(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glIsVertexArrayOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsVertexArrayOES(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glBlendFuncSeparateOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendFuncSeparateOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLenum*)(&sp[12])
    );
}
void nb_handle_glClearDepthfOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearDepthfOES(
        *(GLclampf*)(&sp[0])
    );
}
void nb_handle_glClipPlanefOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClipPlanefOES(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glDepthRangefOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDepthRangefOES(
        *(GLclampf*)(&sp[0]),
        *(GLclampf*)(&sp[4])
    );
}
void nb_handle_glFrustumfOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFrustumfOES(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12]),
        *(GLfloat*)(&sp[16]),
        *(GLfloat*)(&sp[20])
    );
}
void nb_handle_glGetClipPlanefOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetClipPlanefOES(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glOrthofOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glOrthofOES(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12]),
        *(GLfloat*)(&sp[16]),
        *(GLfloat*)(&sp[20])
    );
}
void nb_handle_glDrawTexsOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawTexsOES(
        *(GLshort*)(&sp[0]),
        *(GLshort*)(&sp[4]),
        *(GLshort*)(&sp[8]),
        *(GLshort*)(&sp[12]),
        *(GLshort*)(&sp[16])
    );
}
void nb_handle_glDrawTexiOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawTexiOES(
        *(GLint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16])
    );
}
void nb_handle_glDrawTexxOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawTexxOES(
        *(GLfixed*)(&sp[0]),
        *(GLfixed*)(&sp[4]),
        *(GLfixed*)(&sp[8]),
        *(GLfixed*)(&sp[12]),
        *(GLfixed*)(&sp[16])
    );
}
void nb_handle_glDrawTexsvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawTexsvOES(
        *(void**)(&sp[0])
    );
}
void nb_handle_glDrawTexivOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawTexivOES(
        *(void**)(&sp[0])
    );
}
void nb_handle_glDrawTexxvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawTexxvOES(
        *(void**)(&sp[0])
    );
}
void nb_handle_glDrawTexfOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawTexfOES(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12]),
        *(GLfloat*)(&sp[16])
    );
}
void nb_handle_glDrawTexfvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawTexfvOES(
        *(void**)(&sp[0])
    );
}
void nb_handle_glTexGenfOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexGenfOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfloat*)(&sp[8])
    );
}
void nb_handle_glTexGenfvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexGenfvOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTexGeniOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexGeniOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLint*)(&sp[8])
    );
}
void nb_handle_glTexGenivOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexGenivOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetTexGenfvOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexGenfvOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetTexGenivOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexGenivOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glMapBufferOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)glMapBufferOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_glUnmapBufferOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glUnmapBufferOES(
        *(GLenum*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glGetBufferPointervOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetBufferPointervOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glBlendEquationOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendEquationOES(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glBlendEquationSeparateOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendEquationSeparateOES(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4])
    );
}
void nb_handle_glClipPlanefIMG(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClipPlanefIMG(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glClipPlanexIMG(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClipPlanexIMG(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glRenderbufferStorageMultisampleIMG(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glRenderbufferStorageMultisampleIMG(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLsizei*)(&sp[16])
    );
}
void nb_handle_glFramebufferTexture2DMultisampleIMG(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFramebufferTexture2DMultisampleIMG(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLuint*)(&sp[12]),
        *(GLint*)(&sp[16]),
        *(GLsizei*)(&sp[20])
    );
}
void nb_handle_glDeleteFencesNV(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteFencesNV(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGenFencesNV(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenFencesNV(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glIsFenceNV(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsFenceNV(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glTestFenceNV(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glTestFenceNV(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glGetFenceivNV(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetFenceivNV(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glFinishFenceNV(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFinishFenceNV(
        *(GLuint*)(&sp[0])
    );
}
void nb_handle_glSetFenceNV(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSetFenceNV(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4])
    );
}
__attribute__((visibility("default")))
void nb_handle_svc(CPUARMState *env, int svc) {
    switch (svc) {
        case 0x0400: ALOGV("glAlphaFunc"); nb_handle_glAlphaFunc(env); break;
        case 0x0401: ALOGV("glClearColor"); nb_handle_glClearColor(env); break;
        case 0x0402: ALOGV("glClearDepthf"); nb_handle_glClearDepthf(env); break;
        case 0x0403: ALOGV("glClipPlanef"); nb_handle_glClipPlanef(env); break;
        case 0x0404: ALOGV("glColor4f"); nb_handle_glColor4f(env); break;
        case 0x0405: ALOGV("glDepthRangef"); nb_handle_glDepthRangef(env); break;
        case 0x0406: ALOGV("glFogf"); nb_handle_glFogf(env); break;
        case 0x0407: ALOGV("glFogfv"); nb_handle_glFogfv(env); break;
        case 0x0408: ALOGV("glFrustumf"); nb_handle_glFrustumf(env); break;
        case 0x0409: ALOGV("glGetClipPlanef"); nb_handle_glGetClipPlanef(env); break;
        case 0x040a: ALOGV("glGetFloatv"); nb_handle_glGetFloatv(env); break;
        case 0x040b: ALOGV("glGetLightfv"); nb_handle_glGetLightfv(env); break;
        case 0x040c: ALOGV("glGetMaterialfv"); nb_handle_glGetMaterialfv(env); break;
        case 0x040d: ALOGV("glGetTexEnvfv"); nb_handle_glGetTexEnvfv(env); break;
        case 0x040e: ALOGV("glGetTexParameterfv"); nb_handle_glGetTexParameterfv(env); break;
        case 0x040f: ALOGV("glLightModelf"); nb_handle_glLightModelf(env); break;
        case 0x0410: ALOGV("glLightModelfv"); nb_handle_glLightModelfv(env); break;
        case 0x0411: ALOGV("glLightf"); nb_handle_glLightf(env); break;
        case 0x0412: ALOGV("glLightfv"); nb_handle_glLightfv(env); break;
        case 0x0413: ALOGV("glLineWidth"); nb_handle_glLineWidth(env); break;
        case 0x0414: ALOGV("glLoadMatrixf"); nb_handle_glLoadMatrixf(env); break;
        case 0x0415: ALOGV("glMaterialf"); nb_handle_glMaterialf(env); break;
        case 0x0416: ALOGV("glMaterialfv"); nb_handle_glMaterialfv(env); break;
        case 0x0417: ALOGV("glMultMatrixf"); nb_handle_glMultMatrixf(env); break;
        case 0x0418: ALOGV("glMultiTexCoord4f"); nb_handle_glMultiTexCoord4f(env); break;
        case 0x0419: ALOGV("glNormal3f"); nb_handle_glNormal3f(env); break;
        case 0x041a: ALOGV("glOrthof"); nb_handle_glOrthof(env); break;
        case 0x041b: ALOGV("glPointParameterf"); nb_handle_glPointParameterf(env); break;
        case 0x041c: ALOGV("glPointParameterfv"); nb_handle_glPointParameterfv(env); break;
        case 0x041d: ALOGV("glPointSize"); nb_handle_glPointSize(env); break;
        case 0x041e: ALOGV("glPolygonOffset"); nb_handle_glPolygonOffset(env); break;
        case 0x041f: ALOGV("glRotatef"); nb_handle_glRotatef(env); break;
        case 0x0420: ALOGV("glScalef"); nb_handle_glScalef(env); break;
        case 0x0421: ALOGV("glTexEnvf"); nb_handle_glTexEnvf(env); break;
        case 0x0422: ALOGV("glTexEnvfv"); nb_handle_glTexEnvfv(env); break;
        case 0x0423: ALOGV("glTexParameterf"); nb_handle_glTexParameterf(env); break;
        case 0x0424: ALOGV("glTexParameterfv"); nb_handle_glTexParameterfv(env); break;
        case 0x0425: ALOGV("glTranslatef"); nb_handle_glTranslatef(env); break;
        case 0x0426: ALOGV("glActiveTexture"); nb_handle_glActiveTexture(env); break;
        case 0x0427: ALOGV("glAlphaFuncx"); nb_handle_glAlphaFuncx(env); break;
        case 0x0428: ALOGV("glBindBuffer"); nb_handle_glBindBuffer(env); break;
        case 0x0429: ALOGV("glBindTexture"); nb_handle_glBindTexture(env); break;
        case 0x042a: ALOGV("glBlendFunc"); nb_handle_glBlendFunc(env); break;
        case 0x042b: ALOGV("glBufferData"); nb_handle_glBufferData(env); break;
        case 0x042c: ALOGV("glBufferSubData"); nb_handle_glBufferSubData(env); break;
        case 0x042d: ALOGV("glClear"); nb_handle_glClear(env); break;
        case 0x042e: ALOGV("glClearColorx"); nb_handle_glClearColorx(env); break;
        case 0x042f: ALOGV("glClearDepthx"); nb_handle_glClearDepthx(env); break;
        case 0x0430: ALOGV("glClearStencil"); nb_handle_glClearStencil(env); break;
        case 0x0431: ALOGV("glClientActiveTexture"); nb_handle_glClientActiveTexture(env); break;
        case 0x0432: ALOGV("glClipPlanex"); nb_handle_glClipPlanex(env); break;
        case 0x0433: ALOGV("glColor4ub"); nb_handle_glColor4ub(env); break;
        case 0x0434: ALOGV("glColor4x"); nb_handle_glColor4x(env); break;
        case 0x0435: ALOGV("glColorMask"); nb_handle_glColorMask(env); break;
        case 0x0436: ALOGV("glColorPointer"); nb_handle_glColorPointer(env); break;
        case 0x0437: ALOGV("glCompressedTexImage2D"); nb_handle_glCompressedTexImage2D(env); break;
        case 0x0438: ALOGV("glCompressedTexSubImage2D"); nb_handle_glCompressedTexSubImage2D(env); break;
        case 0x0439: ALOGV("glCopyTexImage2D"); nb_handle_glCopyTexImage2D(env); break;
        case 0x043a: ALOGV("glCopyTexSubImage2D"); nb_handle_glCopyTexSubImage2D(env); break;
        case 0x043b: ALOGV("glCullFace"); nb_handle_glCullFace(env); break;
        case 0x043c: ALOGV("glDeleteBuffers"); nb_handle_glDeleteBuffers(env); break;
        case 0x043d: ALOGV("glDeleteTextures"); nb_handle_glDeleteTextures(env); break;
        case 0x043e: ALOGV("glDepthFunc"); nb_handle_glDepthFunc(env); break;
        case 0x043f: ALOGV("glDepthMask"); nb_handle_glDepthMask(env); break;
        case 0x0440: ALOGV("glDepthRangex"); nb_handle_glDepthRangex(env); break;
        case 0x0441: ALOGV("glDisable"); nb_handle_glDisable(env); break;
        case 0x0442: ALOGV("glDisableClientState"); nb_handle_glDisableClientState(env); break;
        case 0x0443: ALOGV("glDrawArrays"); nb_handle_glDrawArrays(env); break;
        case 0x0444: ALOGV("glDrawElements"); nb_handle_glDrawElements(env); break;
        case 0x0445: ALOGV("glEnable"); nb_handle_glEnable(env); break;
        case 0x0446: ALOGV("glEnableClientState"); nb_handle_glEnableClientState(env); break;
        case 0x0447: ALOGV("glFinish"); nb_handle_glFinish(env); break;
        case 0x0448: ALOGV("glFlush"); nb_handle_glFlush(env); break;
        case 0x0449: ALOGV("glFogx"); nb_handle_glFogx(env); break;
        case 0x044a: ALOGV("glFogxv"); nb_handle_glFogxv(env); break;
        case 0x044b: ALOGV("glFrontFace"); nb_handle_glFrontFace(env); break;
        case 0x044c: ALOGV("glFrustumx"); nb_handle_glFrustumx(env); break;
        case 0x044d: ALOGV("glGetBooleanv"); nb_handle_glGetBooleanv(env); break;
        case 0x044e: ALOGV("glGetBufferParameteriv"); nb_handle_glGetBufferParameteriv(env); break;
        case 0x044f: ALOGV("glGetClipPlanex"); nb_handle_glGetClipPlanex(env); break;
        case 0x0450: ALOGV("glGenBuffers"); nb_handle_glGenBuffers(env); break;
        case 0x0451: ALOGV("glGenTextures"); nb_handle_glGenTextures(env); break;
        case 0x0452: ALOGV("glGetError"); nb_handle_glGetError(env); break;
        case 0x0453: ALOGV("glGetFixedv"); nb_handle_glGetFixedv(env); break;
        case 0x0454: ALOGV("glGetIntegerv"); nb_handle_glGetIntegerv(env); break;
        case 0x0455: ALOGV("glGetLightxv"); nb_handle_glGetLightxv(env); break;
        case 0x0456: ALOGV("glGetMaterialxv"); nb_handle_glGetMaterialxv(env); break;
        case 0x0457: ALOGV("glGetPointerv"); nb_handle_glGetPointerv(env); break;
        case 0x0458: ALOGV("glGetString"); nb_handle_glGetString(env); break;
        case 0x0459: ALOGV("glGetTexEnviv"); nb_handle_glGetTexEnviv(env); break;
        case 0x045a: ALOGV("glGetTexEnvxv"); nb_handle_glGetTexEnvxv(env); break;
        case 0x045b: ALOGV("glGetTexParameteriv"); nb_handle_glGetTexParameteriv(env); break;
        case 0x045c: ALOGV("glGetTexParameterxv"); nb_handle_glGetTexParameterxv(env); break;
        case 0x045d: ALOGV("glHint"); nb_handle_glHint(env); break;
        case 0x045e: ALOGV("glIsBuffer"); nb_handle_glIsBuffer(env); break;
        case 0x045f: ALOGV("glIsEnabled"); nb_handle_glIsEnabled(env); break;
        case 0x0460: ALOGV("glIsTexture"); nb_handle_glIsTexture(env); break;
        case 0x0461: ALOGV("glLightModelx"); nb_handle_glLightModelx(env); break;
        case 0x0462: ALOGV("glLightModelxv"); nb_handle_glLightModelxv(env); break;
        case 0x0463: ALOGV("glLightx"); nb_handle_glLightx(env); break;
        case 0x0464: ALOGV("glLightxv"); nb_handle_glLightxv(env); break;
        case 0x0465: ALOGV("glLineWidthx"); nb_handle_glLineWidthx(env); break;
        case 0x0466: ALOGV("glLoadIdentity"); nb_handle_glLoadIdentity(env); break;
        case 0x0467: ALOGV("glLoadMatrixx"); nb_handle_glLoadMatrixx(env); break;
        case 0x0468: ALOGV("glLogicOp"); nb_handle_glLogicOp(env); break;
        case 0x0469: ALOGV("glMaterialx"); nb_handle_glMaterialx(env); break;
        case 0x046a: ALOGV("glMaterialxv"); nb_handle_glMaterialxv(env); break;
        case 0x046b: ALOGV("glMatrixMode"); nb_handle_glMatrixMode(env); break;
        case 0x046c: ALOGV("glMultMatrixx"); nb_handle_glMultMatrixx(env); break;
        case 0x046d: ALOGV("glMultiTexCoord4x"); nb_handle_glMultiTexCoord4x(env); break;
        case 0x046e: ALOGV("glNormal3x"); nb_handle_glNormal3x(env); break;
        case 0x046f: ALOGV("glNormalPointer"); nb_handle_glNormalPointer(env); break;
        case 0x0470: ALOGV("glOrthox"); nb_handle_glOrthox(env); break;
        case 0x0471: ALOGV("glPixelStorei"); nb_handle_glPixelStorei(env); break;
        case 0x0472: ALOGV("glPointParameterx"); nb_handle_glPointParameterx(env); break;
        case 0x0473: ALOGV("glPointParameterxv"); nb_handle_glPointParameterxv(env); break;
        case 0x0474: ALOGV("glPointSizex"); nb_handle_glPointSizex(env); break;
        case 0x0475: ALOGV("glPolygonOffsetx"); nb_handle_glPolygonOffsetx(env); break;
        case 0x0476: ALOGV("glPopMatrix"); nb_handle_glPopMatrix(env); break;
        case 0x0477: ALOGV("glPushMatrix"); nb_handle_glPushMatrix(env); break;
        case 0x0478: ALOGV("glReadPixels"); nb_handle_glReadPixels(env); break;
        case 0x0479: ALOGV("glRotatex"); nb_handle_glRotatex(env); break;
        case 0x047a: ALOGV("glSampleCoverage"); nb_handle_glSampleCoverage(env); break;
        case 0x047b: ALOGV("glSampleCoveragex"); nb_handle_glSampleCoveragex(env); break;
        case 0x047c: ALOGV("glScalex"); nb_handle_glScalex(env); break;
        case 0x047d: ALOGV("glScissor"); nb_handle_glScissor(env); break;
        case 0x047e: ALOGV("glShadeModel"); nb_handle_glShadeModel(env); break;
        case 0x047f: ALOGV("glStencilFunc"); nb_handle_glStencilFunc(env); break;
        case 0x0480: ALOGV("glStencilMask"); nb_handle_glStencilMask(env); break;
        case 0x0481: ALOGV("glStencilOp"); nb_handle_glStencilOp(env); break;
        case 0x0482: ALOGV("glTexCoordPointer"); nb_handle_glTexCoordPointer(env); break;
        case 0x0483: ALOGV("glTexEnvi"); nb_handle_glTexEnvi(env); break;
        case 0x0484: ALOGV("glTexEnvx"); nb_handle_glTexEnvx(env); break;
        case 0x0485: ALOGV("glTexEnviv"); nb_handle_glTexEnviv(env); break;
        case 0x0486: ALOGV("glTexEnvxv"); nb_handle_glTexEnvxv(env); break;
        case 0x0487: ALOGV("glTexImage2D"); nb_handle_glTexImage2D(env); break;
        case 0x0488: ALOGV("glTexParameteri"); nb_handle_glTexParameteri(env); break;
        case 0x0489: ALOGV("glTexParameterx"); nb_handle_glTexParameterx(env); break;
        case 0x048a: ALOGV("glTexParameteriv"); nb_handle_glTexParameteriv(env); break;
        case 0x048b: ALOGV("glTexParameterxv"); nb_handle_glTexParameterxv(env); break;
        case 0x048c: ALOGV("glTexSubImage2D"); nb_handle_glTexSubImage2D(env); break;
        case 0x048d: ALOGV("glTranslatex"); nb_handle_glTranslatex(env); break;
        case 0x048e: ALOGV("glVertexPointer"); nb_handle_glVertexPointer(env); break;
        case 0x048f: ALOGV("glViewport"); nb_handle_glViewport(env); break;
        case 0x0490: ALOGV("glPointSizePointerOES"); nb_handle_glPointSizePointerOES(env); break;
        case 0x0491: ALOGV("glEGLImageTargetTexture2DOES"); nb_handle_glEGLImageTargetTexture2DOES(env); break;
        case 0x0492: ALOGV("glEGLImageTargetRenderbufferStorageOES"); nb_handle_glEGLImageTargetRenderbufferStorageOES(env); break;
        case 0x0493: ALOGV("glQueryMatrixxOES"); nb_handle_glQueryMatrixxOES(env); break;
        case 0x0494: ALOGV("glAlphaFuncxOES"); nb_handle_glAlphaFuncxOES(env); break;
        case 0x0495: ALOGV("glClearColorxOES"); nb_handle_glClearColorxOES(env); break;
        case 0x0496: ALOGV("glClearDepthxOES"); nb_handle_glClearDepthxOES(env); break;
        case 0x0497: ALOGV("glClipPlanexOES"); nb_handle_glClipPlanexOES(env); break;
        case 0x0498: ALOGV("glColor4xOES"); nb_handle_glColor4xOES(env); break;
        case 0x0499: ALOGV("glDepthRangexOES"); nb_handle_glDepthRangexOES(env); break;
        case 0x049a: ALOGV("glFogxOES"); nb_handle_glFogxOES(env); break;
        case 0x049b: ALOGV("glFogxvOES"); nb_handle_glFogxvOES(env); break;
        case 0x049c: ALOGV("glFrustumxOES"); nb_handle_glFrustumxOES(env); break;
        case 0x049d: ALOGV("glGetClipPlanexOES"); nb_handle_glGetClipPlanexOES(env); break;
        case 0x049e: ALOGV("glGetFixedvOES"); nb_handle_glGetFixedvOES(env); break;
        case 0x049f: ALOGV("glGetTexEnvxvOES"); nb_handle_glGetTexEnvxvOES(env); break;
        case 0x04a0: ALOGV("glGetTexParameterxvOES"); nb_handle_glGetTexParameterxvOES(env); break;
        case 0x04a1: ALOGV("glLightModelxOES"); nb_handle_glLightModelxOES(env); break;
        case 0x04a2: ALOGV("glLightModelxvOES"); nb_handle_glLightModelxvOES(env); break;
        case 0x04a3: ALOGV("glLightxOES"); nb_handle_glLightxOES(env); break;
        case 0x04a4: ALOGV("glLightxvOES"); nb_handle_glLightxvOES(env); break;
        case 0x04a5: ALOGV("glLineWidthxOES"); nb_handle_glLineWidthxOES(env); break;
        case 0x04a6: ALOGV("glLoadMatrixxOES"); nb_handle_glLoadMatrixxOES(env); break;
        case 0x04a7: ALOGV("glMaterialxOES"); nb_handle_glMaterialxOES(env); break;
        case 0x04a8: ALOGV("glMaterialxvOES"); nb_handle_glMaterialxvOES(env); break;
        case 0x04a9: ALOGV("glMultMatrixxOES"); nb_handle_glMultMatrixxOES(env); break;
        case 0x04aa: ALOGV("glMultiTexCoord4xOES"); nb_handle_glMultiTexCoord4xOES(env); break;
        case 0x04ab: ALOGV("glNormal3xOES"); nb_handle_glNormal3xOES(env); break;
        case 0x04ac: ALOGV("glOrthoxOES"); nb_handle_glOrthoxOES(env); break;
        case 0x04ad: ALOGV("glPointParameterxvOES"); nb_handle_glPointParameterxvOES(env); break;
        case 0x04ae: ALOGV("glPointSizexOES"); nb_handle_glPointSizexOES(env); break;
        case 0x04af: ALOGV("glPolygonOffsetxOES"); nb_handle_glPolygonOffsetxOES(env); break;
        case 0x04b0: ALOGV("glRotatexOES"); nb_handle_glRotatexOES(env); break;
        case 0x04b1: ALOGV("glScalexOES"); nb_handle_glScalexOES(env); break;
        case 0x04b2: ALOGV("glTexEnvxOES"); nb_handle_glTexEnvxOES(env); break;
        case 0x04b3: ALOGV("glTexEnvxvOES"); nb_handle_glTexEnvxvOES(env); break;
        case 0x04b4: ALOGV("glTexParameterxOES"); nb_handle_glTexParameterxOES(env); break;
        case 0x04b5: ALOGV("glTexParameterxvOES"); nb_handle_glTexParameterxvOES(env); break;
        case 0x04b6: ALOGV("glTranslatexOES"); nb_handle_glTranslatexOES(env); break;
        case 0x04b7: ALOGV("glGetLightxvOES"); nb_handle_glGetLightxvOES(env); break;
        case 0x04b8: ALOGV("glGetMaterialxvOES"); nb_handle_glGetMaterialxvOES(env); break;
        case 0x04b9: ALOGV("glPointParameterxOES"); nb_handle_glPointParameterxOES(env); break;
        case 0x04ba: ALOGV("glSampleCoveragexOES"); nb_handle_glSampleCoveragexOES(env); break;
        case 0x04bb: ALOGV("glGetTexGenxvOES"); nb_handle_glGetTexGenxvOES(env); break;
        case 0x04bc: ALOGV("glTexGenxOES"); nb_handle_glTexGenxOES(env); break;
        case 0x04bd: ALOGV("glTexGenxvOES"); nb_handle_glTexGenxvOES(env); break;
        case 0x04be: ALOGV("glColorPointerBounds"); nb_handle_glColorPointerBounds(env); break;
        case 0x04bf: ALOGV("glNormalPointerBounds"); nb_handle_glNormalPointerBounds(env); break;
        case 0x04c0: ALOGV("glTexCoordPointerBounds"); nb_handle_glTexCoordPointerBounds(env); break;
        case 0x04c1: ALOGV("glVertexPointerBounds"); nb_handle_glVertexPointerBounds(env); break;
        case 0x04c2: ALOGV("glPointSizePointerOESBounds"); nb_handle_glPointSizePointerOESBounds(env); break;
        case 0x04c3: ALOGV("glMatrixIndexPointerOESBounds"); nb_handle_glMatrixIndexPointerOESBounds(env); break;
        case 0x04c4: ALOGV("glWeightPointerOESBounds"); nb_handle_glWeightPointerOESBounds(env); break;
        case 0x04c5: ALOGV("glIsRenderbufferOES"); nb_handle_glIsRenderbufferOES(env); break;
        case 0x04c6: ALOGV("glBindRenderbufferOES"); nb_handle_glBindRenderbufferOES(env); break;
        case 0x04c7: ALOGV("glDeleteRenderbuffersOES"); nb_handle_glDeleteRenderbuffersOES(env); break;
        case 0x04c8: ALOGV("glGenRenderbuffersOES"); nb_handle_glGenRenderbuffersOES(env); break;
        case 0x04c9: ALOGV("glRenderbufferStorageOES"); nb_handle_glRenderbufferStorageOES(env); break;
        case 0x04ca: ALOGV("glGetRenderbufferParameterivOES"); nb_handle_glGetRenderbufferParameterivOES(env); break;
        case 0x04cb: ALOGV("glIsFramebufferOES"); nb_handle_glIsFramebufferOES(env); break;
        case 0x04cc: ALOGV("glBindFramebufferOES"); nb_handle_glBindFramebufferOES(env); break;
        case 0x04cd: ALOGV("glDeleteFramebuffersOES"); nb_handle_glDeleteFramebuffersOES(env); break;
        case 0x04ce: ALOGV("glGenFramebuffersOES"); nb_handle_glGenFramebuffersOES(env); break;
        case 0x04cf: ALOGV("glCheckFramebufferStatusOES"); nb_handle_glCheckFramebufferStatusOES(env); break;
        case 0x04d0: ALOGV("glFramebufferRenderbufferOES"); nb_handle_glFramebufferRenderbufferOES(env); break;
        case 0x04d1: ALOGV("glFramebufferTexture2DOES"); nb_handle_glFramebufferTexture2DOES(env); break;
        case 0x04d2: ALOGV("glGetFramebufferAttachmentParameterivOES"); nb_handle_glGetFramebufferAttachmentParameterivOES(env); break;
        case 0x04d3: ALOGV("glGenerateMipmapOES"); nb_handle_glGenerateMipmapOES(env); break;
        case 0x04d4: ALOGV("glCurrentPaletteMatrixOES"); nb_handle_glCurrentPaletteMatrixOES(env); break;
        case 0x04d5: ALOGV("glLoadPaletteFromModelViewMatrixOES"); nb_handle_glLoadPaletteFromModelViewMatrixOES(env); break;
        case 0x04d6: ALOGV("glMatrixIndexPointerOES"); nb_handle_glMatrixIndexPointerOES(env); break;
        case 0x04d7: ALOGV("glWeightPointerOES"); nb_handle_glWeightPointerOES(env); break;
        case 0x04d8: ALOGV("glBindVertexArrayOES"); nb_handle_glBindVertexArrayOES(env); break;
        case 0x04d9: ALOGV("glDeleteVertexArraysOES"); nb_handle_glDeleteVertexArraysOES(env); break;
        case 0x04da: ALOGV("glGenVertexArraysOES"); nb_handle_glGenVertexArraysOES(env); break;
        case 0x04db: ALOGV("glIsVertexArrayOES"); nb_handle_glIsVertexArrayOES(env); break;
        case 0x04dc: ALOGV("glBlendFuncSeparateOES"); nb_handle_glBlendFuncSeparateOES(env); break;
        case 0x04dd: ALOGV("glClearDepthfOES"); nb_handle_glClearDepthfOES(env); break;
        case 0x04de: ALOGV("glClipPlanefOES"); nb_handle_glClipPlanefOES(env); break;
        case 0x04df: ALOGV("glDepthRangefOES"); nb_handle_glDepthRangefOES(env); break;
        case 0x04e0: ALOGV("glFrustumfOES"); nb_handle_glFrustumfOES(env); break;
        case 0x04e1: ALOGV("glGetClipPlanefOES"); nb_handle_glGetClipPlanefOES(env); break;
        case 0x04e2: ALOGV("glOrthofOES"); nb_handle_glOrthofOES(env); break;
        case 0x04e3: ALOGV("glDrawTexsOES"); nb_handle_glDrawTexsOES(env); break;
        case 0x04e4: ALOGV("glDrawTexiOES"); nb_handle_glDrawTexiOES(env); break;
        case 0x04e5: ALOGV("glDrawTexxOES"); nb_handle_glDrawTexxOES(env); break;
        case 0x04e6: ALOGV("glDrawTexsvOES"); nb_handle_glDrawTexsvOES(env); break;
        case 0x04e7: ALOGV("glDrawTexivOES"); nb_handle_glDrawTexivOES(env); break;
        case 0x04e8: ALOGV("glDrawTexxvOES"); nb_handle_glDrawTexxvOES(env); break;
        case 0x04e9: ALOGV("glDrawTexfOES"); nb_handle_glDrawTexfOES(env); break;
        case 0x04ea: ALOGV("glDrawTexfvOES"); nb_handle_glDrawTexfvOES(env); break;
        case 0x04eb: ALOGV("glTexGenfOES"); nb_handle_glTexGenfOES(env); break;
        case 0x04ec: ALOGV("glTexGenfvOES"); nb_handle_glTexGenfvOES(env); break;
        case 0x04ed: ALOGV("glTexGeniOES"); nb_handle_glTexGeniOES(env); break;
        case 0x04ee: ALOGV("glTexGenivOES"); nb_handle_glTexGenivOES(env); break;
        case 0x04ef: ALOGV("glGetTexGenfvOES"); nb_handle_glGetTexGenfvOES(env); break;
        case 0x04f0: ALOGV("glGetTexGenivOES"); nb_handle_glGetTexGenivOES(env); break;
        case 0x04f1: ALOGV("glMapBufferOES"); nb_handle_glMapBufferOES(env); break;
        case 0x04f2: ALOGV("glUnmapBufferOES"); nb_handle_glUnmapBufferOES(env); break;
        case 0x04f3: ALOGV("glGetBufferPointervOES"); nb_handle_glGetBufferPointervOES(env); break;
        case 0x04f4: ALOGV("glBlendEquationOES"); nb_handle_glBlendEquationOES(env); break;
        case 0x04f5: ALOGV("glBlendEquationSeparateOES"); nb_handle_glBlendEquationSeparateOES(env); break;
        case 0x04f6: ALOGV("glClipPlanefIMG"); nb_handle_glClipPlanefIMG(env); break;
        case 0x04f7: ALOGV("glClipPlanexIMG"); nb_handle_glClipPlanexIMG(env); break;
        case 0x04f8: ALOGV("glRenderbufferStorageMultisampleIMG"); nb_handle_glRenderbufferStorageMultisampleIMG(env); break;
        case 0x04f9: ALOGV("glFramebufferTexture2DMultisampleIMG"); nb_handle_glFramebufferTexture2DMultisampleIMG(env); break;
        case 0x04fa: ALOGV("glDeleteFencesNV"); nb_handle_glDeleteFencesNV(env); break;
        case 0x04fb: ALOGV("glGenFencesNV"); nb_handle_glGenFencesNV(env); break;
        case 0x04fc: ALOGV("glIsFenceNV"); nb_handle_glIsFenceNV(env); break;
        case 0x04fd: ALOGV("glTestFenceNV"); nb_handle_glTestFenceNV(env); break;
        case 0x04fe: ALOGV("glGetFenceivNV"); nb_handle_glGetFenceivNV(env); break;
        case 0x04ff: ALOGV("glFinishFenceNV"); nb_handle_glFinishFenceNV(env); break;
        case 0x0500: ALOGV("glSetFenceNV"); nb_handle_glSetFenceNV(env); break;
        default: LOG_ALWAYS_FATAL("Unknown SVC %08x", svc); break;
    }
}
