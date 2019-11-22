#define LOG_TAG "libnb-qemu"
#define LOG_NDEBUG 0

#include <stdint.h>
#include <log/log.h>
#include "QemuInclude.h"
#include <GLES3/gl32.h>
#include <GLES2/gl2ext.h>

void nb_handle_glActiveTexture(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glActiveTexture(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glAttachShader(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glAttachShader(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glBindAttribLocation(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindAttribLocation(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glBindBuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindBuffer(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glBindFramebuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindFramebuffer(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glBindRenderbuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindRenderbuffer(
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
void nb_handle_glBlendColor(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendColor(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12])
    );
}
void nb_handle_glBlendEquation(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendEquation(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glBlendEquationSeparate(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendEquationSeparate(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4])
    );
}
void nb_handle_glBlendFunc(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendFunc(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4])
    );
}
void nb_handle_glBlendFuncSeparate(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendFuncSeparate(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLenum*)(&sp[12])
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
void nb_handle_glCheckFramebufferStatus(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLenum __nb_ret = (GLenum)glCheckFramebufferStatus(
        *(GLenum*)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glClear(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClear(
        *(GLbitfield*)(&sp[0])
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
void nb_handle_glClearStencil(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearStencil(
        *(GLint*)(&sp[0])
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
void nb_handle_glCompileShader(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCompileShader(
        *(GLuint*)(&sp[0])
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
void nb_handle_glCreateProgram(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLuint __nb_ret = (GLuint)glCreateProgram(
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glCreateShader(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLuint __nb_ret = (GLuint)glCreateShader(
        *(GLenum*)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
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
void nb_handle_glDeleteFramebuffers(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteFramebuffers(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glDeleteProgram(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteProgram(
        *(GLuint*)(&sp[0])
    );
}
void nb_handle_glDeleteRenderbuffers(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteRenderbuffers(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glDeleteShader(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteShader(
        *(GLuint*)(&sp[0])
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
void nb_handle_glDepthRangef(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDepthRangef(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4])
    );
}
void nb_handle_glDetachShader(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDetachShader(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glDisable(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDisable(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glDisableVertexAttribArray(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDisableVertexAttribArray(
        *(GLuint*)(&sp[0])
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
void nb_handle_glEnableVertexAttribArray(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glEnableVertexAttribArray(
        *(GLuint*)(&sp[0])
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
void nb_handle_glFramebufferRenderbuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFramebufferRenderbuffer(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLuint*)(&sp[12])
    );
}
void nb_handle_glFramebufferTexture2D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFramebufferTexture2D(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLuint*)(&sp[12]),
        *(GLint*)(&sp[16])
    );
}
void nb_handle_glFrontFace(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFrontFace(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glGenBuffers(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenBuffers(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGenerateMipmap(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenerateMipmap(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glGenFramebuffers(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenFramebuffers(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGenRenderbuffers(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenRenderbuffers(
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
void nb_handle_glGetActiveAttrib(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetActiveAttrib(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16]),
        *(void**)(&sp[20]),
        *(void**)(&sp[24])
    );
}
void nb_handle_glGetActiveUniform(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetActiveUniform(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16]),
        *(void**)(&sp[20]),
        *(void**)(&sp[24])
    );
}
void nb_handle_glGetAttachedShaders(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetAttachedShaders(
        *(GLuint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetAttribLocation(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLint __nb_ret = (GLint)glGetAttribLocation(
        *(GLuint*)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
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
void nb_handle_glGetError(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLenum __nb_ret = (GLenum)glGetError(
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glGetFloatv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetFloatv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetFramebufferAttachmentParameteriv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetFramebufferAttachmentParameteriv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetIntegerv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetIntegerv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetProgramiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetProgramiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetProgramInfoLog(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetProgramInfoLog(
        *(GLuint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetRenderbufferParameteriv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetRenderbufferParameteriv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetShaderiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetShaderiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetShaderInfoLog(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetShaderInfoLog(
        *(GLuint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetShaderPrecisionFormat(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetShaderPrecisionFormat(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetShaderSource(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetShaderSource(
        *(GLuint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetString(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)glGetString(
        *(GLenum*)(&sp[0])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_glGetTexParameterfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexParameterfv(
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
void nb_handle_glGetUniformfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetUniformfv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetUniformiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetUniformiv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetUniformLocation(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLint __nb_ret = (GLint)glGetUniformLocation(
        *(GLuint*)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glGetVertexAttribfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetVertexAttribfv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetVertexAttribiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetVertexAttribiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetVertexAttribPointerv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetVertexAttribPointerv(
        *(GLuint*)(&sp[0]),
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
void nb_handle_glIsFramebuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsFramebuffer(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glIsProgram(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsProgram(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glIsRenderbuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsRenderbuffer(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glIsShader(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsShader(
        *(GLuint*)(&sp[0])
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
void nb_handle_glLineWidth(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLineWidth(
        *(GLfloat*)(&sp[0])
    );
}
void nb_handle_glLinkProgram(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glLinkProgram(
        *(GLuint*)(&sp[0])
    );
}
void nb_handle_glPixelStorei(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPixelStorei(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4])
    );
}
void nb_handle_glPolygonOffset(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPolygonOffset(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4])
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
void nb_handle_glReleaseShaderCompiler(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glReleaseShaderCompiler(
    );
}
void nb_handle_glRenderbufferStorage(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glRenderbufferStorage(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLsizei*)(&sp[12])
    );
}
void nb_handle_glSampleCoverage(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSampleCoverage(
        *(GLfloat*)(&sp[0]),
        *(GLboolean*)(&sp[4])
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
void nb_handle_glShaderBinary(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glShaderBinary(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(void**)(&sp[12]),
        *(GLsizei*)(&sp[16])
    );
}
void nb_handle_glShaderSource(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glShaderSource(
        *(GLuint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
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
void nb_handle_glStencilFuncSeparate(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glStencilFuncSeparate(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLuint*)(&sp[12])
    );
}
void nb_handle_glStencilMask(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glStencilMask(
        *(GLuint*)(&sp[0])
    );
}
void nb_handle_glStencilMaskSeparate(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glStencilMaskSeparate(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
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
void nb_handle_glStencilOpSeparate(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glStencilOpSeparate(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLenum*)(&sp[12])
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
void nb_handle_glTexParameteri(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameteri(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLint*)(&sp[8])
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
void nb_handle_glUniform1f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform1f(
        *(GLint*)(&sp[0]),
        *(GLfloat*)(&sp[4])
    );
}
void nb_handle_glUniform1fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform1fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glUniform1i(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform1i(
        *(GLint*)(&sp[0]),
        *(GLint*)(&sp[4])
    );
}
void nb_handle_glUniform1iv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform1iv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glUniform2f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform2f(
        *(GLint*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8])
    );
}
void nb_handle_glUniform2fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform2fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glUniform2i(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform2i(
        *(GLint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8])
    );
}
void nb_handle_glUniform2iv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform2iv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glUniform3f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform3f(
        *(GLint*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12])
    );
}
void nb_handle_glUniform3fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform3fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glUniform3i(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform3i(
        *(GLint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12])
    );
}
void nb_handle_glUniform3iv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform3iv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glUniform4f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform4f(
        *(GLint*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12]),
        *(GLfloat*)(&sp[16])
    );
}
void nb_handle_glUniform4fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform4fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glUniform4i(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform4i(
        *(GLint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16])
    );
}
void nb_handle_glUniform4iv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform4iv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glUniformMatrix2fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniformMatrix2fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLboolean*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glUniformMatrix3fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniformMatrix3fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLboolean*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glUniformMatrix4fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniformMatrix4fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLboolean*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glUseProgram(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUseProgram(
        *(GLuint*)(&sp[0])
    );
}
void nb_handle_glValidateProgram(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glValidateProgram(
        *(GLuint*)(&sp[0])
    );
}
void nb_handle_glVertexAttrib1f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttrib1f(
        *(GLuint*)(&sp[0]),
        *(GLfloat*)(&sp[4])
    );
}
void nb_handle_glVertexAttrib1fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttrib1fv(
        *(GLuint*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glVertexAttrib2f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttrib2f(
        *(GLuint*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8])
    );
}
void nb_handle_glVertexAttrib2fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttrib2fv(
        *(GLuint*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glVertexAttrib3f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttrib3f(
        *(GLuint*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12])
    );
}
void nb_handle_glVertexAttrib3fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttrib3fv(
        *(GLuint*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glVertexAttrib4f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttrib4f(
        *(GLuint*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12]),
        *(GLfloat*)(&sp[16])
    );
}
void nb_handle_glVertexAttrib4fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttrib4fv(
        *(GLuint*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glVertexAttribPointer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttribPointer(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(void**)(&sp[20])
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
void nb_handle_glReadBuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glReadBuffer(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glDrawRangeElements(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawRangeElements(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLenum*)(&sp[16]),
        *(void**)(&sp[20])
    );
}
void nb_handle_glTexImage3D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexImage3D(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(GLsizei*)(&sp[20]),
        *(GLint*)(&sp[24]),
        *(GLenum*)(&sp[28]),
        *(GLenum*)(&sp[32]),
        *(void**)(&sp[36])
    );
}
void nb_handle_glTexSubImage3D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexSubImage3D(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16]),
        *(GLsizei*)(&sp[20]),
        *(GLsizei*)(&sp[24]),
        *(GLsizei*)(&sp[28]),
        *(GLenum*)(&sp[32]),
        *(GLenum*)(&sp[36]),
        *(void**)(&sp[40])
    );
}
void nb_handle_glCopyTexSubImage3D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCopyTexSubImage3D(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16]),
        *(GLint*)(&sp[20]),
        *(GLint*)(&sp[24]),
        *(GLsizei*)(&sp[28]),
        *(GLsizei*)(&sp[32])
    );
}
void nb_handle_glCompressedTexImage3D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCompressedTexImage3D(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(GLsizei*)(&sp[20]),
        *(GLint*)(&sp[24]),
        *(GLsizei*)(&sp[28]),
        *(void**)(&sp[32])
    );
}
void nb_handle_glCompressedTexSubImage3D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCompressedTexSubImage3D(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16]),
        *(GLsizei*)(&sp[20]),
        *(GLsizei*)(&sp[24]),
        *(GLsizei*)(&sp[28]),
        *(GLenum*)(&sp[32]),
        *(GLsizei*)(&sp[36]),
        *(void**)(&sp[40])
    );
}
void nb_handle_glGenQueries(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenQueries(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glDeleteQueries(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteQueries(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glIsQuery(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsQuery(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glBeginQuery(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBeginQuery(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glEndQuery(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glEndQuery(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glGetQueryiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetQueryiv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetQueryObjectuiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetQueryObjectuiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glUnmapBuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glUnmapBuffer(
        *(GLenum*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glGetBufferPointerv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetBufferPointerv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glDrawBuffers(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawBuffers(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glUniformMatrix2x3fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniformMatrix2x3fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLboolean*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glUniformMatrix3x2fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniformMatrix3x2fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLboolean*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glUniformMatrix2x4fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniformMatrix2x4fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLboolean*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glUniformMatrix4x2fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniformMatrix4x2fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLboolean*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glUniformMatrix3x4fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniformMatrix3x4fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLboolean*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glUniformMatrix4x3fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniformMatrix4x3fv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLboolean*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glBlitFramebuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlitFramebuffer(
        *(GLint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16]),
        *(GLint*)(&sp[20]),
        *(GLint*)(&sp[24]),
        *(GLint*)(&sp[28]),
        *(GLbitfield*)(&sp[32]),
        *(GLenum*)(&sp[36])
    );
}
void nb_handle_glRenderbufferStorageMultisample(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glRenderbufferStorageMultisample(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLsizei*)(&sp[16])
    );
}
void nb_handle_glFramebufferTextureLayer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFramebufferTextureLayer(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16])
    );
}
void nb_handle_glMapBufferRange(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)glMapBufferRange(
        *(GLenum*)(&sp[0]),
        *(GLintptr*)(&sp[4]),
        *(GLsizeiptr*)(&sp[8]),
        *(GLbitfield*)(&sp[12])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_glFlushMappedBufferRange(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFlushMappedBufferRange(
        *(GLenum*)(&sp[0]),
        *(GLintptr*)(&sp[4]),
        *(GLsizeiptr*)(&sp[8])
    );
}
void nb_handle_glBindVertexArray(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindVertexArray(
        *(GLuint*)(&sp[0])
    );
}
void nb_handle_glDeleteVertexArrays(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteVertexArrays(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGenVertexArrays(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenVertexArrays(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glIsVertexArray(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsVertexArray(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glGetIntegeri_v(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetIntegeri_v(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glBeginTransformFeedback(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBeginTransformFeedback(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glEndTransformFeedback(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glEndTransformFeedback(
    );
}
void nb_handle_glBindBufferRange(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindBufferRange(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLintptr*)(&sp[12]),
        *(GLsizeiptr*)(&sp[16])
    );
}
void nb_handle_glBindBufferBase(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindBufferBase(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLuint*)(&sp[8])
    );
}
void nb_handle_glTransformFeedbackVaryings(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTransformFeedbackVaryings(
        *(GLuint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(GLenum*)(&sp[12])
    );
}
void nb_handle_glGetTransformFeedbackVarying(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTransformFeedbackVarying(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16]),
        *(void**)(&sp[20]),
        *(void**)(&sp[24])
    );
}
void nb_handle_glVertexAttribIPointer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttribIPointer(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glGetVertexAttribIiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetVertexAttribIiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetVertexAttribIuiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetVertexAttribIuiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glVertexAttribI4i(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttribI4i(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16])
    );
}
void nb_handle_glVertexAttribI4ui(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttribI4ui(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLuint*)(&sp[12]),
        *(GLuint*)(&sp[16])
    );
}
void nb_handle_glVertexAttribI4iv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttribI4iv(
        *(GLuint*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glVertexAttribI4uiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttribI4uiv(
        *(GLuint*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetUniformuiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetUniformuiv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetFragDataLocation(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLint __nb_ret = (GLint)glGetFragDataLocation(
        *(GLuint*)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glUniform1ui(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform1ui(
        *(GLint*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glUniform2ui(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform2ui(
        *(GLint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLuint*)(&sp[8])
    );
}
void nb_handle_glUniform3ui(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform3ui(
        *(GLint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLuint*)(&sp[12])
    );
}
void nb_handle_glUniform4ui(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform4ui(
        *(GLint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLuint*)(&sp[12]),
        *(GLuint*)(&sp[16])
    );
}
void nb_handle_glUniform1uiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform1uiv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glUniform2uiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform2uiv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glUniform3uiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform3uiv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glUniform4uiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniform4uiv(
        *(GLint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glClearBufferiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearBufferiv(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glClearBufferuiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearBufferuiv(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glClearBufferfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearBufferfv(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glClearBufferfi(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glClearBufferfi(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLint*)(&sp[12])
    );
}
void nb_handle_glGetStringi(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)glGetStringi(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_glCopyBufferSubData(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCopyBufferSubData(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLintptr*)(&sp[8]),
        *(GLintptr*)(&sp[12]),
        *(GLsizeiptr*)(&sp[16])
    );
}
void nb_handle_glGetUniformIndices(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetUniformIndices(
        *(GLuint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetActiveUniformsiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetActiveUniformsiv(
        *(GLuint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(GLenum*)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glGetUniformBlockIndex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLuint __nb_ret = (GLuint)glGetUniformBlockIndex(
        *(GLuint*)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glGetActiveUniformBlockiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetActiveUniformBlockiv(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetActiveUniformBlockName(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetActiveUniformBlockName(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glUniformBlockBinding(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUniformBlockBinding(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLuint*)(&sp[8])
    );
}
void nb_handle_glDrawArraysInstanced(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawArraysInstanced(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLsizei*)(&sp[12])
    );
}
void nb_handle_glDrawElementsInstanced(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawElementsInstanced(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(void**)(&sp[12]),
        *(GLsizei*)(&sp[16])
    );
}
void nb_handle_glFenceSync(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    void* __nb_ret = (void*)glFenceSync(
        *(GLenum*)(&sp[0]),
        *(GLbitfield*)(&sp[4])
    );
    env->regs[0] = h2g_nocheck(__nb_ret);
}
void nb_handle_glIsSync(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsSync(
        *(void**)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glDeleteSync(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteSync(
        *(void**)(&sp[0])
    );
}
void nb_handle_glClientWaitSync(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLenum __nb_ret = (GLenum)glClientWaitSync(
        *(void**)(&sp[0]),
        *(GLbitfield*)(&sp[4]),
        *(GLuint64*)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glWaitSync(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glWaitSync(
        *(void**)(&sp[0]),
        *(GLbitfield*)(&sp[4]),
        *(GLuint64*)(&sp[8])
    );
}
void nb_handle_glGetInteger64v(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetInteger64v(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetSynciv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetSynciv(
        *(void**)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glGetInteger64i_v(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetInteger64i_v(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetBufferParameteri64v(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetBufferParameteri64v(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGenSamplers(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenSamplers(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glDeleteSamplers(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteSamplers(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glIsSampler(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsSampler(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glBindSampler(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindSampler(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glSamplerParameteri(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSamplerParameteri(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLint*)(&sp[8])
    );
}
void nb_handle_glSamplerParameteriv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSamplerParameteriv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glSamplerParameterf(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSamplerParameterf(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLfloat*)(&sp[8])
    );
}
void nb_handle_glSamplerParameterfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSamplerParameterfv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetSamplerParameteriv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetSamplerParameteriv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetSamplerParameterfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetSamplerParameterfv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glVertexAttribDivisor(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttribDivisor(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glBindTransformFeedback(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindTransformFeedback(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glDeleteTransformFeedbacks(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteTransformFeedbacks(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGenTransformFeedbacks(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenTransformFeedbacks(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glIsTransformFeedback(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsTransformFeedback(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glPauseTransformFeedback(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPauseTransformFeedback(
    );
}
void nb_handle_glResumeTransformFeedback(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glResumeTransformFeedback(
    );
}
void nb_handle_glGetProgramBinary(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetProgramBinary(
        *(GLuint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glProgramBinary(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramBinary(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8]),
        *(GLsizei*)(&sp[12])
    );
}
void nb_handle_glProgramParameteri(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramParameteri(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLint*)(&sp[8])
    );
}
void nb_handle_glInvalidateFramebuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glInvalidateFramebuffer(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glInvalidateSubFramebuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glInvalidateSubFramebuffer(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16]),
        *(GLsizei*)(&sp[20]),
        *(GLsizei*)(&sp[24])
    );
}
void nb_handle_glTexStorage2D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexStorage2D(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLsizei*)(&sp[16])
    );
}
void nb_handle_glTexStorage3D(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexStorage3D(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(GLsizei*)(&sp[20])
    );
}
void nb_handle_glGetInternalformativ(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetInternalformativ(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glDispatchCompute(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDispatchCompute(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLuint*)(&sp[8])
    );
}
void nb_handle_glDispatchComputeIndirect(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDispatchComputeIndirect(
        *(GLintptr*)(&sp[0])
    );
}
void nb_handle_glDrawArraysIndirect(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawArraysIndirect(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glDrawElementsIndirect(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawElementsIndirect(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glFramebufferParameteri(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFramebufferParameteri(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLint*)(&sp[8])
    );
}
void nb_handle_glGetFramebufferParameteriv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetFramebufferParameteriv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetProgramInterfaceiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetProgramInterfaceiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetProgramResourceIndex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLuint __nb_ret = (GLuint)glGetProgramResourceIndex(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glGetProgramResourceName(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetProgramResourceName(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(void**)(&sp[16]),
        *(void**)(&sp[20])
    );
}
void nb_handle_glGetProgramResourceiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetProgramResourceiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(void**)(&sp[16]),
        *(GLsizei*)(&sp[20]),
        *(void**)(&sp[24]),
        *(void**)(&sp[28])
    );
}
void nb_handle_glGetProgramResourceLocation(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLint __nb_ret = (GLint)glGetProgramResourceLocation(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glUseProgramStages(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glUseProgramStages(
        *(GLuint*)(&sp[0]),
        *(GLbitfield*)(&sp[4]),
        *(GLuint*)(&sp[8])
    );
}
void nb_handle_glActiveShaderProgram(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glActiveShaderProgram(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glCreateShaderProgramv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLuint __nb_ret = (GLuint)glCreateShaderProgramv(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glBindProgramPipeline(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindProgramPipeline(
        *(GLuint*)(&sp[0])
    );
}
void nb_handle_glDeleteProgramPipelines(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteProgramPipelines(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGenProgramPipelines(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenProgramPipelines(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glIsProgramPipeline(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsProgramPipeline(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glGetProgramPipelineiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetProgramPipelineiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glProgramUniform1i(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform1i(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8])
    );
}
void nb_handle_glProgramUniform2i(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform2i(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12])
    );
}
void nb_handle_glProgramUniform3i(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform3i(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16])
    );
}
void nb_handle_glProgramUniform4i(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform4i(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16]),
        *(GLint*)(&sp[20])
    );
}
void nb_handle_glProgramUniform1ui(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform1ui(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLuint*)(&sp[8])
    );
}
void nb_handle_glProgramUniform2ui(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform2ui(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLuint*)(&sp[12])
    );
}
void nb_handle_glProgramUniform3ui(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform3ui(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLuint*)(&sp[12]),
        *(GLuint*)(&sp[16])
    );
}
void nb_handle_glProgramUniform4ui(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform4ui(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLuint*)(&sp[12]),
        *(GLuint*)(&sp[16]),
        *(GLuint*)(&sp[20])
    );
}
void nb_handle_glProgramUniform1f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform1f(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLfloat*)(&sp[8])
    );
}
void nb_handle_glProgramUniform2f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform2f(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12])
    );
}
void nb_handle_glProgramUniform3f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform3f(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12]),
        *(GLfloat*)(&sp[16])
    );
}
void nb_handle_glProgramUniform4f(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform4f(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12]),
        *(GLfloat*)(&sp[16]),
        *(GLfloat*)(&sp[20])
    );
}
void nb_handle_glProgramUniform1iv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform1iv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glProgramUniform2iv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform2iv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glProgramUniform3iv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform3iv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glProgramUniform4iv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform4iv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glProgramUniform1uiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform1uiv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glProgramUniform2uiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform2uiv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glProgramUniform3uiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform3uiv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glProgramUniform4uiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform4uiv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glProgramUniform1fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform1fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glProgramUniform2fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform2fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glProgramUniform3fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform3fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glProgramUniform4fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniform4fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glProgramUniformMatrix2fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniformMatrix2fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glProgramUniformMatrix3fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniformMatrix3fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glProgramUniformMatrix4fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniformMatrix4fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glProgramUniformMatrix2x3fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniformMatrix2x3fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glProgramUniformMatrix3x2fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniformMatrix3x2fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glProgramUniformMatrix2x4fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniformMatrix2x4fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glProgramUniformMatrix4x2fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniformMatrix4x2fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glProgramUniformMatrix3x4fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniformMatrix3x4fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glProgramUniformMatrix4x3fv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glProgramUniformMatrix4x3fv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glValidateProgramPipeline(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glValidateProgramPipeline(
        *(GLuint*)(&sp[0])
    );
}
void nb_handle_glGetProgramPipelineInfoLog(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetProgramPipelineInfoLog(
        *(GLuint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glBindImageTexture(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindImageTexture(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(GLint*)(&sp[16]),
        *(GLenum*)(&sp[20]),
        *(GLenum*)(&sp[24])
    );
}
void nb_handle_glGetBooleani_v(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetBooleani_v(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glMemoryBarrier(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMemoryBarrier(
        *(GLbitfield*)(&sp[0])
    );
}
void nb_handle_glMemoryBarrierByRegion(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMemoryBarrierByRegion(
        *(GLbitfield*)(&sp[0])
    );
}
void nb_handle_glTexStorage2DMultisample(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexStorage2DMultisample(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(GLboolean*)(&sp[20])
    );
}
void nb_handle_glGetMultisamplefv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetMultisamplefv(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glSampleMaski(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSampleMaski(
        *(GLuint*)(&sp[0]),
        *(GLbitfield*)(&sp[4])
    );
}
void nb_handle_glGetTexLevelParameteriv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexLevelParameteriv(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetTexLevelParameterfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexLevelParameterfv(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glBindVertexBuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBindVertexBuffer(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLintptr*)(&sp[8]),
        *(GLsizei*)(&sp[12])
    );
}
void nb_handle_glVertexAttribFormat(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttribFormat(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(GLuint*)(&sp[16])
    );
}
void nb_handle_glVertexAttribIFormat(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttribIFormat(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLuint*)(&sp[12])
    );
}
void nb_handle_glVertexAttribBinding(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexAttribBinding(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glVertexBindingDivisor(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glVertexBindingDivisor(
        *(GLuint*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glBlendBarrier(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendBarrier(
    );
}
void nb_handle_glCopyImageSubData(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCopyImageSubData(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16]),
        *(GLint*)(&sp[20]),
        *(GLuint*)(&sp[24]),
        *(GLenum*)(&sp[28]),
        *(GLint*)(&sp[32]),
        *(GLint*)(&sp[36]),
        *(GLint*)(&sp[40]),
        *(GLint*)(&sp[44]),
        *(GLsizei*)(&sp[48]),
        *(GLsizei*)(&sp[52]),
        *(GLsizei*)(&sp[56])
    );
}
void nb_handle_glDebugMessageControl(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDebugMessageControl(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(void**)(&sp[16]),
        *(GLboolean*)(&sp[20])
    );
}
void nb_handle_glDebugMessageInsert(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDebugMessageInsert(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLenum*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(void**)(&sp[20])
    );
}
void nb_handle_glDebugMessageCallback(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDebugMessageCallback(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glGetDebugMessageLog(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLuint __nb_ret = (GLuint)glGetDebugMessageLog(
        *(GLuint*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16]),
        *(void**)(&sp[20]),
        *(void**)(&sp[24]),
        *(void**)(&sp[28])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glPushDebugGroup(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPushDebugGroup(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glPopDebugGroup(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPopDebugGroup(
    );
}
void nb_handle_glObjectLabel(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glObjectLabel(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetObjectLabel(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetObjectLabel(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16])
    );
}
void nb_handle_glObjectPtrLabel(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glObjectPtrLabel(
        *(void**)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetObjectPtrLabel(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetObjectPtrLabel(
        *(void**)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetPointerv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetPointerv(
        *(GLenum*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glEnablei(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glEnablei(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glDisablei(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDisablei(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glBlendEquationi(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendEquationi(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4])
    );
}
void nb_handle_glBlendEquationSeparatei(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendEquationSeparatei(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8])
    );
}
void nb_handle_glBlendFunci(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendFunci(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8])
    );
}
void nb_handle_glBlendFuncSeparatei(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendFuncSeparatei(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLenum*)(&sp[12]),
        *(GLenum*)(&sp[16])
    );
}
void nb_handle_glColorMaski(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glColorMaski(
        *(GLuint*)(&sp[0]),
        *(GLboolean*)(&sp[4]),
        *(GLboolean*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(GLboolean*)(&sp[16])
    );
}
void nb_handle_glIsEnabledi(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsEnabledi(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glDrawElementsBaseVertex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawElementsBaseVertex(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(void**)(&sp[12]),
        *(GLint*)(&sp[16])
    );
}
void nb_handle_glDrawRangeElementsBaseVertex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawRangeElementsBaseVertex(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLenum*)(&sp[16]),
        *(void**)(&sp[20]),
        *(GLint*)(&sp[24])
    );
}
void nb_handle_glDrawElementsInstancedBaseVertex(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDrawElementsInstancedBaseVertex(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(void**)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(GLint*)(&sp[20])
    );
}
void nb_handle_glFramebufferTexture(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFramebufferTexture(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLint*)(&sp[12])
    );
}
void nb_handle_glPrimitiveBoundingBox(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPrimitiveBoundingBox(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12]),
        *(GLfloat*)(&sp[16]),
        *(GLfloat*)(&sp[20]),
        *(GLfloat*)(&sp[24]),
        *(GLfloat*)(&sp[28])
    );
}
void nb_handle_glGetGraphicsResetStatus(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLenum __nb_ret = (GLenum)glGetGraphicsResetStatus(
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_glReadnPixels(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glReadnPixels(
        *(GLint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLenum*)(&sp[16]),
        *(GLenum*)(&sp[20]),
        *(GLsizei*)(&sp[24]),
        *(void**)(&sp[28])
    );
}
void nb_handle_glGetnUniformfv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetnUniformfv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetnUniformiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetnUniformiv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glGetnUniformuiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetnUniformuiv(
        *(GLuint*)(&sp[0]),
        *(GLint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glMinSampleShading(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMinSampleShading(
        *(GLfloat*)(&sp[0])
    );
}
void nb_handle_glPatchParameteri(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPatchParameteri(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4])
    );
}
void nb_handle_glTexParameterIiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameterIiv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTexParameterIuiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameterIuiv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetTexParameterIiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexParameterIiv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetTexParameterIuiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexParameterIuiv(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glSamplerParameterIiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSamplerParameterIiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glSamplerParameterIuiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSamplerParameterIuiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetSamplerParameterIiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetSamplerParameterIiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetSamplerParameterIuiv(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetSamplerParameterIuiv(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTexBuffer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexBuffer(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLuint*)(&sp[8])
    );
}
void nb_handle_glTexBufferRange(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexBufferRange(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLintptr*)(&sp[12]),
        *(GLsizeiptr*)(&sp[16])
    );
}
void nb_handle_glTexStorage3DMultisample(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexStorage3DMultisample(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(GLsizei*)(&sp[20]),
        *(GLboolean*)(&sp[24])
    );
}
void nb_handle_glBlendBarrierKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendBarrierKHR(
    );
}
void nb_handle_glEnableiEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glEnableiEXT(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glDisableiEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDisableiEXT(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glBlendEquationiEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendEquationiEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4])
    );
}
void nb_handle_glBlendEquationSeparateiEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendEquationSeparateiEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8])
    );
}
void nb_handle_glBlendFunciEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendFunciEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8])
    );
}
void nb_handle_glBlendFuncSeparateiEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBlendFuncSeparateiEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLenum*)(&sp[12]),
        *(GLenum*)(&sp[16])
    );
}
void nb_handle_glColorMaskiEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glColorMaskiEXT(
        *(GLuint*)(&sp[0]),
        *(GLboolean*)(&sp[4]),
        *(GLboolean*)(&sp[8]),
        *(GLboolean*)(&sp[12]),
        *(GLboolean*)(&sp[16])
    );
}
void nb_handle_glIsEnablediEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsEnablediEXT(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glCopyImageSubDataEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glCopyImageSubDataEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLint*)(&sp[8]),
        *(GLint*)(&sp[12]),
        *(GLint*)(&sp[16]),
        *(GLint*)(&sp[20]),
        *(GLuint*)(&sp[24]),
        *(GLenum*)(&sp[28]),
        *(GLint*)(&sp[32]),
        *(GLint*)(&sp[36]),
        *(GLint*)(&sp[40]),
        *(GLint*)(&sp[44]),
        *(GLsizei*)(&sp[48]),
        *(GLsizei*)(&sp[52]),
        *(GLsizei*)(&sp[56])
    );
}
void nb_handle_glDebugMessageControlKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDebugMessageControlKHR(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(void**)(&sp[16]),
        *(GLboolean*)(&sp[20])
    );
}
void nb_handle_glDebugMessageInsertKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDebugMessageInsertKHR(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLenum*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(void**)(&sp[20])
    );
}
void nb_handle_glPushDebugGroupKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPushDebugGroupKHR(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glPopDebugGroupKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPopDebugGroupKHR(
    );
}
void nb_handle_glObjectLabelKHR(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glObjectLabelKHR(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4]),
        *(GLsizei*)(&sp[8]),
        *(void**)(&sp[12])
    );
}
void nb_handle_glFramebufferTextureEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glFramebufferTextureEXT(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLint*)(&sp[12])
    );
}
void nb_handle_glTexParameterIivEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameterIivEXT(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTexParameterIuivEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexParameterIuivEXT(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetTexParameterIivEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexParameterIivEXT(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetTexParameterIuivEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetTexParameterIuivEXT(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glSamplerParameterIivEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSamplerParameterIivEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glSamplerParameterIuivEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glSamplerParameterIuivEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetSamplerParameterIivEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetSamplerParameterIivEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetSamplerParameterIuivEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetSamplerParameterIuivEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glMinSampleShadingOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glMinSampleShadingOES(
        *(GLfloat*)(&sp[0])
    );
}
void nb_handle_glPatchParameteriEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPatchParameteriEXT(
        *(GLenum*)(&sp[0]),
        *(GLint*)(&sp[4])
    );
}
void nb_handle_glPrimitiveBoundingBoxEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glPrimitiveBoundingBoxEXT(
        *(GLfloat*)(&sp[0]),
        *(GLfloat*)(&sp[4]),
        *(GLfloat*)(&sp[8]),
        *(GLfloat*)(&sp[12]),
        *(GLfloat*)(&sp[16]),
        *(GLfloat*)(&sp[20]),
        *(GLfloat*)(&sp[24]),
        *(GLfloat*)(&sp[28])
    );
}
void nb_handle_glTexBufferEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexBufferEXT(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLuint*)(&sp[8])
    );
}
void nb_handle_glTexBufferRangeEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexBufferRangeEXT(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(GLuint*)(&sp[8]),
        *(GLintptr*)(&sp[12]),
        *(GLsizeiptr*)(&sp[16])
    );
}
void nb_handle_glGenQueriesEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGenQueriesEXT(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glDeleteQueriesEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glDeleteQueriesEXT(
        *(GLsizei*)(&sp[0]),
        *(void**)(&sp[4])
    );
}
void nb_handle_glIsQueryEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    GLboolean __nb_ret = (GLboolean)glIsQueryEXT(
        *(GLuint*)(&sp[0])
    );
    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;
}
void nb_handle_glBeginQueryEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glBeginQueryEXT(
        *(GLenum*)(&sp[0]),
        *(GLuint*)(&sp[4])
    );
}
void nb_handle_glEndQueryEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glEndQueryEXT(
        *(GLenum*)(&sp[0])
    );
}
void nb_handle_glQueryCounterEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glQueryCounterEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4])
    );
}
void nb_handle_glGetQueryivEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetQueryivEXT(
        *(GLenum*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetQueryObjectivEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetQueryObjectivEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetQueryObjectuivEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetQueryObjectuivEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetQueryObjecti64vEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetQueryObjecti64vEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glGetQueryObjectui64vEXT(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glGetQueryObjectui64vEXT(
        *(GLuint*)(&sp[0]),
        *(GLenum*)(&sp[4]),
        *(void**)(&sp[8])
    );
}
void nb_handle_glTexStorage3DMultisampleOES(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    glTexStorage3DMultisampleOES(
        *(GLenum*)(&sp[0]),
        *(GLsizei*)(&sp[4]),
        *(GLenum*)(&sp[8]),
        *(GLsizei*)(&sp[12]),
        *(GLsizei*)(&sp[16]),
        *(GLsizei*)(&sp[20]),
        *(GLboolean*)(&sp[24])
    );
}
__attribute__((visibility("default")))
void nb_handle_svc(CPUARMState *env, int svc) {
    switch (svc) {
        case 0x1000: ALOGV("glActiveTexture"); nb_handle_glActiveTexture(env); break;
        case 0x1001: ALOGV("glAttachShader"); nb_handle_glAttachShader(env); break;
        case 0x1002: ALOGV("glBindAttribLocation"); nb_handle_glBindAttribLocation(env); break;
        case 0x1003: ALOGV("glBindBuffer"); nb_handle_glBindBuffer(env); break;
        case 0x1004: ALOGV("glBindFramebuffer"); nb_handle_glBindFramebuffer(env); break;
        case 0x1005: ALOGV("glBindRenderbuffer"); nb_handle_glBindRenderbuffer(env); break;
        case 0x1006: ALOGV("glBindTexture"); nb_handle_glBindTexture(env); break;
        case 0x1007: ALOGV("glBlendColor"); nb_handle_glBlendColor(env); break;
        case 0x1008: ALOGV("glBlendEquation"); nb_handle_glBlendEquation(env); break;
        case 0x1009: ALOGV("glBlendEquationSeparate"); nb_handle_glBlendEquationSeparate(env); break;
        case 0x100a: ALOGV("glBlendFunc"); nb_handle_glBlendFunc(env); break;
        case 0x100b: ALOGV("glBlendFuncSeparate"); nb_handle_glBlendFuncSeparate(env); break;
        case 0x100c: ALOGV("glBufferData"); nb_handle_glBufferData(env); break;
        case 0x100d: ALOGV("glBufferSubData"); nb_handle_glBufferSubData(env); break;
        case 0x100e: ALOGV("glCheckFramebufferStatus"); nb_handle_glCheckFramebufferStatus(env); break;
        case 0x100f: ALOGV("glClear"); nb_handle_glClear(env); break;
        case 0x1010: ALOGV("glClearColor"); nb_handle_glClearColor(env); break;
        case 0x1011: ALOGV("glClearDepthf"); nb_handle_glClearDepthf(env); break;
        case 0x1012: ALOGV("glClearStencil"); nb_handle_glClearStencil(env); break;
        case 0x1013: ALOGV("glColorMask"); nb_handle_glColorMask(env); break;
        case 0x1014: ALOGV("glCompileShader"); nb_handle_glCompileShader(env); break;
        case 0x1015: ALOGV("glCompressedTexImage2D"); nb_handle_glCompressedTexImage2D(env); break;
        case 0x1016: ALOGV("glCompressedTexSubImage2D"); nb_handle_glCompressedTexSubImage2D(env); break;
        case 0x1017: ALOGV("glCopyTexImage2D"); nb_handle_glCopyTexImage2D(env); break;
        case 0x1018: ALOGV("glCopyTexSubImage2D"); nb_handle_glCopyTexSubImage2D(env); break;
        case 0x1019: ALOGV("glCreateProgram"); nb_handle_glCreateProgram(env); break;
        case 0x101a: ALOGV("glCreateShader"); nb_handle_glCreateShader(env); break;
        case 0x101b: ALOGV("glCullFace"); nb_handle_glCullFace(env); break;
        case 0x101c: ALOGV("glDeleteBuffers"); nb_handle_glDeleteBuffers(env); break;
        case 0x101d: ALOGV("glDeleteFramebuffers"); nb_handle_glDeleteFramebuffers(env); break;
        case 0x101e: ALOGV("glDeleteProgram"); nb_handle_glDeleteProgram(env); break;
        case 0x101f: ALOGV("glDeleteRenderbuffers"); nb_handle_glDeleteRenderbuffers(env); break;
        case 0x1020: ALOGV("glDeleteShader"); nb_handle_glDeleteShader(env); break;
        case 0x1021: ALOGV("glDeleteTextures"); nb_handle_glDeleteTextures(env); break;
        case 0x1022: ALOGV("glDepthFunc"); nb_handle_glDepthFunc(env); break;
        case 0x1023: ALOGV("glDepthMask"); nb_handle_glDepthMask(env); break;
        case 0x1024: ALOGV("glDepthRangef"); nb_handle_glDepthRangef(env); break;
        case 0x1025: ALOGV("glDetachShader"); nb_handle_glDetachShader(env); break;
        case 0x1026: ALOGV("glDisable"); nb_handle_glDisable(env); break;
        case 0x1027: ALOGV("glDisableVertexAttribArray"); nb_handle_glDisableVertexAttribArray(env); break;
        case 0x1028: ALOGV("glDrawArrays"); nb_handle_glDrawArrays(env); break;
        case 0x1029: ALOGV("glDrawElements"); nb_handle_glDrawElements(env); break;
        case 0x102a: ALOGV("glEnable"); nb_handle_glEnable(env); break;
        case 0x102b: ALOGV("glEnableVertexAttribArray"); nb_handle_glEnableVertexAttribArray(env); break;
        case 0x102c: ALOGV("glFinish"); nb_handle_glFinish(env); break;
        case 0x102d: ALOGV("glFlush"); nb_handle_glFlush(env); break;
        case 0x102e: ALOGV("glFramebufferRenderbuffer"); nb_handle_glFramebufferRenderbuffer(env); break;
        case 0x102f: ALOGV("glFramebufferTexture2D"); nb_handle_glFramebufferTexture2D(env); break;
        case 0x1030: ALOGV("glFrontFace"); nb_handle_glFrontFace(env); break;
        case 0x1031: ALOGV("glGenBuffers"); nb_handle_glGenBuffers(env); break;
        case 0x1032: ALOGV("glGenerateMipmap"); nb_handle_glGenerateMipmap(env); break;
        case 0x1033: ALOGV("glGenFramebuffers"); nb_handle_glGenFramebuffers(env); break;
        case 0x1034: ALOGV("glGenRenderbuffers"); nb_handle_glGenRenderbuffers(env); break;
        case 0x1035: ALOGV("glGenTextures"); nb_handle_glGenTextures(env); break;
        case 0x1036: ALOGV("glGetActiveAttrib"); nb_handle_glGetActiveAttrib(env); break;
        case 0x1037: ALOGV("glGetActiveUniform"); nb_handle_glGetActiveUniform(env); break;
        case 0x1038: ALOGV("glGetAttachedShaders"); nb_handle_glGetAttachedShaders(env); break;
        case 0x1039: ALOGV("glGetAttribLocation"); nb_handle_glGetAttribLocation(env); break;
        case 0x103a: ALOGV("glGetBooleanv"); nb_handle_glGetBooleanv(env); break;
        case 0x103b: ALOGV("glGetBufferParameteriv"); nb_handle_glGetBufferParameteriv(env); break;
        case 0x103c: ALOGV("glGetError"); nb_handle_glGetError(env); break;
        case 0x103d: ALOGV("glGetFloatv"); nb_handle_glGetFloatv(env); break;
        case 0x103e: ALOGV("glGetFramebufferAttachmentParameteriv"); nb_handle_glGetFramebufferAttachmentParameteriv(env); break;
        case 0x103f: ALOGV("glGetIntegerv"); nb_handle_glGetIntegerv(env); break;
        case 0x1040: ALOGV("glGetProgramiv"); nb_handle_glGetProgramiv(env); break;
        case 0x1041: ALOGV("glGetProgramInfoLog"); nb_handle_glGetProgramInfoLog(env); break;
        case 0x1042: ALOGV("glGetRenderbufferParameteriv"); nb_handle_glGetRenderbufferParameteriv(env); break;
        case 0x1043: ALOGV("glGetShaderiv"); nb_handle_glGetShaderiv(env); break;
        case 0x1044: ALOGV("glGetShaderInfoLog"); nb_handle_glGetShaderInfoLog(env); break;
        case 0x1045: ALOGV("glGetShaderPrecisionFormat"); nb_handle_glGetShaderPrecisionFormat(env); break;
        case 0x1046: ALOGV("glGetShaderSource"); nb_handle_glGetShaderSource(env); break;
        case 0x1047: ALOGV("glGetString"); nb_handle_glGetString(env); break;
        case 0x1048: ALOGV("glGetTexParameterfv"); nb_handle_glGetTexParameterfv(env); break;
        case 0x1049: ALOGV("glGetTexParameteriv"); nb_handle_glGetTexParameteriv(env); break;
        case 0x104a: ALOGV("glGetUniformfv"); nb_handle_glGetUniformfv(env); break;
        case 0x104b: ALOGV("glGetUniformiv"); nb_handle_glGetUniformiv(env); break;
        case 0x104c: ALOGV("glGetUniformLocation"); nb_handle_glGetUniformLocation(env); break;
        case 0x104d: ALOGV("glGetVertexAttribfv"); nb_handle_glGetVertexAttribfv(env); break;
        case 0x104e: ALOGV("glGetVertexAttribiv"); nb_handle_glGetVertexAttribiv(env); break;
        case 0x104f: ALOGV("glGetVertexAttribPointerv"); nb_handle_glGetVertexAttribPointerv(env); break;
        case 0x1050: ALOGV("glHint"); nb_handle_glHint(env); break;
        case 0x1051: ALOGV("glIsBuffer"); nb_handle_glIsBuffer(env); break;
        case 0x1052: ALOGV("glIsEnabled"); nb_handle_glIsEnabled(env); break;
        case 0x1053: ALOGV("glIsFramebuffer"); nb_handle_glIsFramebuffer(env); break;
        case 0x1054: ALOGV("glIsProgram"); nb_handle_glIsProgram(env); break;
        case 0x1055: ALOGV("glIsRenderbuffer"); nb_handle_glIsRenderbuffer(env); break;
        case 0x1056: ALOGV("glIsShader"); nb_handle_glIsShader(env); break;
        case 0x1057: ALOGV("glIsTexture"); nb_handle_glIsTexture(env); break;
        case 0x1058: ALOGV("glLineWidth"); nb_handle_glLineWidth(env); break;
        case 0x1059: ALOGV("glLinkProgram"); nb_handle_glLinkProgram(env); break;
        case 0x105a: ALOGV("glPixelStorei"); nb_handle_glPixelStorei(env); break;
        case 0x105b: ALOGV("glPolygonOffset"); nb_handle_glPolygonOffset(env); break;
        case 0x105c: ALOGV("glReadPixels"); nb_handle_glReadPixels(env); break;
        case 0x105d: ALOGV("glReleaseShaderCompiler"); nb_handle_glReleaseShaderCompiler(env); break;
        case 0x105e: ALOGV("glRenderbufferStorage"); nb_handle_glRenderbufferStorage(env); break;
        case 0x105f: ALOGV("glSampleCoverage"); nb_handle_glSampleCoverage(env); break;
        case 0x1060: ALOGV("glScissor"); nb_handle_glScissor(env); break;
        case 0x1061: ALOGV("glShaderBinary"); nb_handle_glShaderBinary(env); break;
        case 0x1062: ALOGV("glShaderSource"); nb_handle_glShaderSource(env); break;
        case 0x1063: ALOGV("glStencilFunc"); nb_handle_glStencilFunc(env); break;
        case 0x1064: ALOGV("glStencilFuncSeparate"); nb_handle_glStencilFuncSeparate(env); break;
        case 0x1065: ALOGV("glStencilMask"); nb_handle_glStencilMask(env); break;
        case 0x1066: ALOGV("glStencilMaskSeparate"); nb_handle_glStencilMaskSeparate(env); break;
        case 0x1067: ALOGV("glStencilOp"); nb_handle_glStencilOp(env); break;
        case 0x1068: ALOGV("glStencilOpSeparate"); nb_handle_glStencilOpSeparate(env); break;
        case 0x1069: ALOGV("glTexImage2D"); nb_handle_glTexImage2D(env); break;
        case 0x106a: ALOGV("glTexParameterf"); nb_handle_glTexParameterf(env); break;
        case 0x106b: ALOGV("glTexParameterfv"); nb_handle_glTexParameterfv(env); break;
        case 0x106c: ALOGV("glTexParameteri"); nb_handle_glTexParameteri(env); break;
        case 0x106d: ALOGV("glTexParameteriv"); nb_handle_glTexParameteriv(env); break;
        case 0x106e: ALOGV("glTexSubImage2D"); nb_handle_glTexSubImage2D(env); break;
        case 0x106f: ALOGV("glUniform1f"); nb_handle_glUniform1f(env); break;
        case 0x1070: ALOGV("glUniform1fv"); nb_handle_glUniform1fv(env); break;
        case 0x1071: ALOGV("glUniform1i"); nb_handle_glUniform1i(env); break;
        case 0x1072: ALOGV("glUniform1iv"); nb_handle_glUniform1iv(env); break;
        case 0x1073: ALOGV("glUniform2f"); nb_handle_glUniform2f(env); break;
        case 0x1074: ALOGV("glUniform2fv"); nb_handle_glUniform2fv(env); break;
        case 0x1075: ALOGV("glUniform2i"); nb_handle_glUniform2i(env); break;
        case 0x1076: ALOGV("glUniform2iv"); nb_handle_glUniform2iv(env); break;
        case 0x1077: ALOGV("glUniform3f"); nb_handle_glUniform3f(env); break;
        case 0x1078: ALOGV("glUniform3fv"); nb_handle_glUniform3fv(env); break;
        case 0x1079: ALOGV("glUniform3i"); nb_handle_glUniform3i(env); break;
        case 0x107a: ALOGV("glUniform3iv"); nb_handle_glUniform3iv(env); break;
        case 0x107b: ALOGV("glUniform4f"); nb_handle_glUniform4f(env); break;
        case 0x107c: ALOGV("glUniform4fv"); nb_handle_glUniform4fv(env); break;
        case 0x107d: ALOGV("glUniform4i"); nb_handle_glUniform4i(env); break;
        case 0x107e: ALOGV("glUniform4iv"); nb_handle_glUniform4iv(env); break;
        case 0x107f: ALOGV("glUniformMatrix2fv"); nb_handle_glUniformMatrix2fv(env); break;
        case 0x1080: ALOGV("glUniformMatrix3fv"); nb_handle_glUniformMatrix3fv(env); break;
        case 0x1081: ALOGV("glUniformMatrix4fv"); nb_handle_glUniformMatrix4fv(env); break;
        case 0x1082: ALOGV("glUseProgram"); nb_handle_glUseProgram(env); break;
        case 0x1083: ALOGV("glValidateProgram"); nb_handle_glValidateProgram(env); break;
        case 0x1084: ALOGV("glVertexAttrib1f"); nb_handle_glVertexAttrib1f(env); break;
        case 0x1085: ALOGV("glVertexAttrib1fv"); nb_handle_glVertexAttrib1fv(env); break;
        case 0x1086: ALOGV("glVertexAttrib2f"); nb_handle_glVertexAttrib2f(env); break;
        case 0x1087: ALOGV("glVertexAttrib2fv"); nb_handle_glVertexAttrib2fv(env); break;
        case 0x1088: ALOGV("glVertexAttrib3f"); nb_handle_glVertexAttrib3f(env); break;
        case 0x1089: ALOGV("glVertexAttrib3fv"); nb_handle_glVertexAttrib3fv(env); break;
        case 0x108a: ALOGV("glVertexAttrib4f"); nb_handle_glVertexAttrib4f(env); break;
        case 0x108b: ALOGV("glVertexAttrib4fv"); nb_handle_glVertexAttrib4fv(env); break;
        case 0x108c: ALOGV("glVertexAttribPointer"); nb_handle_glVertexAttribPointer(env); break;
        case 0x108d: ALOGV("glViewport"); nb_handle_glViewport(env); break;
        case 0x108e: ALOGV("glReadBuffer"); nb_handle_glReadBuffer(env); break;
        case 0x108f: ALOGV("glDrawRangeElements"); nb_handle_glDrawRangeElements(env); break;
        case 0x1090: ALOGV("glTexImage3D"); nb_handle_glTexImage3D(env); break;
        case 0x1091: ALOGV("glTexSubImage3D"); nb_handle_glTexSubImage3D(env); break;
        case 0x1092: ALOGV("glCopyTexSubImage3D"); nb_handle_glCopyTexSubImage3D(env); break;
        case 0x1093: ALOGV("glCompressedTexImage3D"); nb_handle_glCompressedTexImage3D(env); break;
        case 0x1094: ALOGV("glCompressedTexSubImage3D"); nb_handle_glCompressedTexSubImage3D(env); break;
        case 0x1095: ALOGV("glGenQueries"); nb_handle_glGenQueries(env); break;
        case 0x1096: ALOGV("glDeleteQueries"); nb_handle_glDeleteQueries(env); break;
        case 0x1097: ALOGV("glIsQuery"); nb_handle_glIsQuery(env); break;
        case 0x1098: ALOGV("glBeginQuery"); nb_handle_glBeginQuery(env); break;
        case 0x1099: ALOGV("glEndQuery"); nb_handle_glEndQuery(env); break;
        case 0x109a: ALOGV("glGetQueryiv"); nb_handle_glGetQueryiv(env); break;
        case 0x109b: ALOGV("glGetQueryObjectuiv"); nb_handle_glGetQueryObjectuiv(env); break;
        case 0x109c: ALOGV("glUnmapBuffer"); nb_handle_glUnmapBuffer(env); break;
        case 0x109d: ALOGV("glGetBufferPointerv"); nb_handle_glGetBufferPointerv(env); break;
        case 0x109e: ALOGV("glDrawBuffers"); nb_handle_glDrawBuffers(env); break;
        case 0x109f: ALOGV("glUniformMatrix2x3fv"); nb_handle_glUniformMatrix2x3fv(env); break;
        case 0x10a0: ALOGV("glUniformMatrix3x2fv"); nb_handle_glUniformMatrix3x2fv(env); break;
        case 0x10a1: ALOGV("glUniformMatrix2x4fv"); nb_handle_glUniformMatrix2x4fv(env); break;
        case 0x10a2: ALOGV("glUniformMatrix4x2fv"); nb_handle_glUniformMatrix4x2fv(env); break;
        case 0x10a3: ALOGV("glUniformMatrix3x4fv"); nb_handle_glUniformMatrix3x4fv(env); break;
        case 0x10a4: ALOGV("glUniformMatrix4x3fv"); nb_handle_glUniformMatrix4x3fv(env); break;
        case 0x10a5: ALOGV("glBlitFramebuffer"); nb_handle_glBlitFramebuffer(env); break;
        case 0x10a6: ALOGV("glRenderbufferStorageMultisample"); nb_handle_glRenderbufferStorageMultisample(env); break;
        case 0x10a7: ALOGV("glFramebufferTextureLayer"); nb_handle_glFramebufferTextureLayer(env); break;
        case 0x10a8: ALOGV("glMapBufferRange"); nb_handle_glMapBufferRange(env); break;
        case 0x10a9: ALOGV("glFlushMappedBufferRange"); nb_handle_glFlushMappedBufferRange(env); break;
        case 0x10aa: ALOGV("glBindVertexArray"); nb_handle_glBindVertexArray(env); break;
        case 0x10ab: ALOGV("glDeleteVertexArrays"); nb_handle_glDeleteVertexArrays(env); break;
        case 0x10ac: ALOGV("glGenVertexArrays"); nb_handle_glGenVertexArrays(env); break;
        case 0x10ad: ALOGV("glIsVertexArray"); nb_handle_glIsVertexArray(env); break;
        case 0x10ae: ALOGV("glGetIntegeri_v"); nb_handle_glGetIntegeri_v(env); break;
        case 0x10af: ALOGV("glBeginTransformFeedback"); nb_handle_glBeginTransformFeedback(env); break;
        case 0x10b0: ALOGV("glEndTransformFeedback"); nb_handle_glEndTransformFeedback(env); break;
        case 0x10b1: ALOGV("glBindBufferRange"); nb_handle_glBindBufferRange(env); break;
        case 0x10b2: ALOGV("glBindBufferBase"); nb_handle_glBindBufferBase(env); break;
        case 0x10b3: ALOGV("glTransformFeedbackVaryings"); nb_handle_glTransformFeedbackVaryings(env); break;
        case 0x10b4: ALOGV("glGetTransformFeedbackVarying"); nb_handle_glGetTransformFeedbackVarying(env); break;
        case 0x10b5: ALOGV("glVertexAttribIPointer"); nb_handle_glVertexAttribIPointer(env); break;
        case 0x10b6: ALOGV("glGetVertexAttribIiv"); nb_handle_glGetVertexAttribIiv(env); break;
        case 0x10b7: ALOGV("glGetVertexAttribIuiv"); nb_handle_glGetVertexAttribIuiv(env); break;
        case 0x10b8: ALOGV("glVertexAttribI4i"); nb_handle_glVertexAttribI4i(env); break;
        case 0x10b9: ALOGV("glVertexAttribI4ui"); nb_handle_glVertexAttribI4ui(env); break;
        case 0x10ba: ALOGV("glVertexAttribI4iv"); nb_handle_glVertexAttribI4iv(env); break;
        case 0x10bb: ALOGV("glVertexAttribI4uiv"); nb_handle_glVertexAttribI4uiv(env); break;
        case 0x10bc: ALOGV("glGetUniformuiv"); nb_handle_glGetUniformuiv(env); break;
        case 0x10bd: ALOGV("glGetFragDataLocation"); nb_handle_glGetFragDataLocation(env); break;
        case 0x10be: ALOGV("glUniform1ui"); nb_handle_glUniform1ui(env); break;
        case 0x10bf: ALOGV("glUniform2ui"); nb_handle_glUniform2ui(env); break;
        case 0x10c0: ALOGV("glUniform3ui"); nb_handle_glUniform3ui(env); break;
        case 0x10c1: ALOGV("glUniform4ui"); nb_handle_glUniform4ui(env); break;
        case 0x10c2: ALOGV("glUniform1uiv"); nb_handle_glUniform1uiv(env); break;
        case 0x10c3: ALOGV("glUniform2uiv"); nb_handle_glUniform2uiv(env); break;
        case 0x10c4: ALOGV("glUniform3uiv"); nb_handle_glUniform3uiv(env); break;
        case 0x10c5: ALOGV("glUniform4uiv"); nb_handle_glUniform4uiv(env); break;
        case 0x10c6: ALOGV("glClearBufferiv"); nb_handle_glClearBufferiv(env); break;
        case 0x10c7: ALOGV("glClearBufferuiv"); nb_handle_glClearBufferuiv(env); break;
        case 0x10c8: ALOGV("glClearBufferfv"); nb_handle_glClearBufferfv(env); break;
        case 0x10c9: ALOGV("glClearBufferfi"); nb_handle_glClearBufferfi(env); break;
        case 0x10ca: ALOGV("glGetStringi"); nb_handle_glGetStringi(env); break;
        case 0x10cb: ALOGV("glCopyBufferSubData"); nb_handle_glCopyBufferSubData(env); break;
        case 0x10cc: ALOGV("glGetUniformIndices"); nb_handle_glGetUniformIndices(env); break;
        case 0x10cd: ALOGV("glGetActiveUniformsiv"); nb_handle_glGetActiveUniformsiv(env); break;
        case 0x10ce: ALOGV("glGetUniformBlockIndex"); nb_handle_glGetUniformBlockIndex(env); break;
        case 0x10cf: ALOGV("glGetActiveUniformBlockiv"); nb_handle_glGetActiveUniformBlockiv(env); break;
        case 0x10d0: ALOGV("glGetActiveUniformBlockName"); nb_handle_glGetActiveUniformBlockName(env); break;
        case 0x10d1: ALOGV("glUniformBlockBinding"); nb_handle_glUniformBlockBinding(env); break;
        case 0x10d2: ALOGV("glDrawArraysInstanced"); nb_handle_glDrawArraysInstanced(env); break;
        case 0x10d3: ALOGV("glDrawElementsInstanced"); nb_handle_glDrawElementsInstanced(env); break;
        case 0x10d4: ALOGV("glFenceSync"); nb_handle_glFenceSync(env); break;
        case 0x10d5: ALOGV("glIsSync"); nb_handle_glIsSync(env); break;
        case 0x10d6: ALOGV("glDeleteSync"); nb_handle_glDeleteSync(env); break;
        case 0x10d7: ALOGV("glClientWaitSync"); nb_handle_glClientWaitSync(env); break;
        case 0x10d8: ALOGV("glWaitSync"); nb_handle_glWaitSync(env); break;
        case 0x10d9: ALOGV("glGetInteger64v"); nb_handle_glGetInteger64v(env); break;
        case 0x10da: ALOGV("glGetSynciv"); nb_handle_glGetSynciv(env); break;
        case 0x10db: ALOGV("glGetInteger64i_v"); nb_handle_glGetInteger64i_v(env); break;
        case 0x10dc: ALOGV("glGetBufferParameteri64v"); nb_handle_glGetBufferParameteri64v(env); break;
        case 0x10dd: ALOGV("glGenSamplers"); nb_handle_glGenSamplers(env); break;
        case 0x10de: ALOGV("glDeleteSamplers"); nb_handle_glDeleteSamplers(env); break;
        case 0x10df: ALOGV("glIsSampler"); nb_handle_glIsSampler(env); break;
        case 0x10e0: ALOGV("glBindSampler"); nb_handle_glBindSampler(env); break;
        case 0x10e1: ALOGV("glSamplerParameteri"); nb_handle_glSamplerParameteri(env); break;
        case 0x10e2: ALOGV("glSamplerParameteriv"); nb_handle_glSamplerParameteriv(env); break;
        case 0x10e3: ALOGV("glSamplerParameterf"); nb_handle_glSamplerParameterf(env); break;
        case 0x10e4: ALOGV("glSamplerParameterfv"); nb_handle_glSamplerParameterfv(env); break;
        case 0x10e5: ALOGV("glGetSamplerParameteriv"); nb_handle_glGetSamplerParameteriv(env); break;
        case 0x10e6: ALOGV("glGetSamplerParameterfv"); nb_handle_glGetSamplerParameterfv(env); break;
        case 0x10e7: ALOGV("glVertexAttribDivisor"); nb_handle_glVertexAttribDivisor(env); break;
        case 0x10e8: ALOGV("glBindTransformFeedback"); nb_handle_glBindTransformFeedback(env); break;
        case 0x10e9: ALOGV("glDeleteTransformFeedbacks"); nb_handle_glDeleteTransformFeedbacks(env); break;
        case 0x10ea: ALOGV("glGenTransformFeedbacks"); nb_handle_glGenTransformFeedbacks(env); break;
        case 0x10eb: ALOGV("glIsTransformFeedback"); nb_handle_glIsTransformFeedback(env); break;
        case 0x10ec: ALOGV("glPauseTransformFeedback"); nb_handle_glPauseTransformFeedback(env); break;
        case 0x10ed: ALOGV("glResumeTransformFeedback"); nb_handle_glResumeTransformFeedback(env); break;
        case 0x10ee: ALOGV("glGetProgramBinary"); nb_handle_glGetProgramBinary(env); break;
        case 0x10ef: ALOGV("glProgramBinary"); nb_handle_glProgramBinary(env); break;
        case 0x10f0: ALOGV("glProgramParameteri"); nb_handle_glProgramParameteri(env); break;
        case 0x10f1: ALOGV("glInvalidateFramebuffer"); nb_handle_glInvalidateFramebuffer(env); break;
        case 0x10f2: ALOGV("glInvalidateSubFramebuffer"); nb_handle_glInvalidateSubFramebuffer(env); break;
        case 0x10f3: ALOGV("glTexStorage2D"); nb_handle_glTexStorage2D(env); break;
        case 0x10f4: ALOGV("glTexStorage3D"); nb_handle_glTexStorage3D(env); break;
        case 0x10f5: ALOGV("glGetInternalformativ"); nb_handle_glGetInternalformativ(env); break;
        case 0x10f6: ALOGV("glDispatchCompute"); nb_handle_glDispatchCompute(env); break;
        case 0x10f7: ALOGV("glDispatchComputeIndirect"); nb_handle_glDispatchComputeIndirect(env); break;
        case 0x10f8: ALOGV("glDrawArraysIndirect"); nb_handle_glDrawArraysIndirect(env); break;
        case 0x10f9: ALOGV("glDrawElementsIndirect"); nb_handle_glDrawElementsIndirect(env); break;
        case 0x10fa: ALOGV("glFramebufferParameteri"); nb_handle_glFramebufferParameteri(env); break;
        case 0x10fb: ALOGV("glGetFramebufferParameteriv"); nb_handle_glGetFramebufferParameteriv(env); break;
        case 0x10fc: ALOGV("glGetProgramInterfaceiv"); nb_handle_glGetProgramInterfaceiv(env); break;
        case 0x10fd: ALOGV("glGetProgramResourceIndex"); nb_handle_glGetProgramResourceIndex(env); break;
        case 0x10fe: ALOGV("glGetProgramResourceName"); nb_handle_glGetProgramResourceName(env); break;
        case 0x10ff: ALOGV("glGetProgramResourceiv"); nb_handle_glGetProgramResourceiv(env); break;
        case 0x1100: ALOGV("glGetProgramResourceLocation"); nb_handle_glGetProgramResourceLocation(env); break;
        case 0x1101: ALOGV("glUseProgramStages"); nb_handle_glUseProgramStages(env); break;
        case 0x1102: ALOGV("glActiveShaderProgram"); nb_handle_glActiveShaderProgram(env); break;
        case 0x1103: ALOGV("glCreateShaderProgramv"); nb_handle_glCreateShaderProgramv(env); break;
        case 0x1104: ALOGV("glBindProgramPipeline"); nb_handle_glBindProgramPipeline(env); break;
        case 0x1105: ALOGV("glDeleteProgramPipelines"); nb_handle_glDeleteProgramPipelines(env); break;
        case 0x1106: ALOGV("glGenProgramPipelines"); nb_handle_glGenProgramPipelines(env); break;
        case 0x1107: ALOGV("glIsProgramPipeline"); nb_handle_glIsProgramPipeline(env); break;
        case 0x1108: ALOGV("glGetProgramPipelineiv"); nb_handle_glGetProgramPipelineiv(env); break;
        case 0x1109: ALOGV("glProgramUniform1i"); nb_handle_glProgramUniform1i(env); break;
        case 0x110a: ALOGV("glProgramUniform2i"); nb_handle_glProgramUniform2i(env); break;
        case 0x110b: ALOGV("glProgramUniform3i"); nb_handle_glProgramUniform3i(env); break;
        case 0x110c: ALOGV("glProgramUniform4i"); nb_handle_glProgramUniform4i(env); break;
        case 0x110d: ALOGV("glProgramUniform1ui"); nb_handle_glProgramUniform1ui(env); break;
        case 0x110e: ALOGV("glProgramUniform2ui"); nb_handle_glProgramUniform2ui(env); break;
        case 0x110f: ALOGV("glProgramUniform3ui"); nb_handle_glProgramUniform3ui(env); break;
        case 0x1110: ALOGV("glProgramUniform4ui"); nb_handle_glProgramUniform4ui(env); break;
        case 0x1111: ALOGV("glProgramUniform1f"); nb_handle_glProgramUniform1f(env); break;
        case 0x1112: ALOGV("glProgramUniform2f"); nb_handle_glProgramUniform2f(env); break;
        case 0x1113: ALOGV("glProgramUniform3f"); nb_handle_glProgramUniform3f(env); break;
        case 0x1114: ALOGV("glProgramUniform4f"); nb_handle_glProgramUniform4f(env); break;
        case 0x1115: ALOGV("glProgramUniform1iv"); nb_handle_glProgramUniform1iv(env); break;
        case 0x1116: ALOGV("glProgramUniform2iv"); nb_handle_glProgramUniform2iv(env); break;
        case 0x1117: ALOGV("glProgramUniform3iv"); nb_handle_glProgramUniform3iv(env); break;
        case 0x1118: ALOGV("glProgramUniform4iv"); nb_handle_glProgramUniform4iv(env); break;
        case 0x1119: ALOGV("glProgramUniform1uiv"); nb_handle_glProgramUniform1uiv(env); break;
        case 0x111a: ALOGV("glProgramUniform2uiv"); nb_handle_glProgramUniform2uiv(env); break;
        case 0x111b: ALOGV("glProgramUniform3uiv"); nb_handle_glProgramUniform3uiv(env); break;
        case 0x111c: ALOGV("glProgramUniform4uiv"); nb_handle_glProgramUniform4uiv(env); break;
        case 0x111d: ALOGV("glProgramUniform1fv"); nb_handle_glProgramUniform1fv(env); break;
        case 0x111e: ALOGV("glProgramUniform2fv"); nb_handle_glProgramUniform2fv(env); break;
        case 0x111f: ALOGV("glProgramUniform3fv"); nb_handle_glProgramUniform3fv(env); break;
        case 0x1120: ALOGV("glProgramUniform4fv"); nb_handle_glProgramUniform4fv(env); break;
        case 0x1121: ALOGV("glProgramUniformMatrix2fv"); nb_handle_glProgramUniformMatrix2fv(env); break;
        case 0x1122: ALOGV("glProgramUniformMatrix3fv"); nb_handle_glProgramUniformMatrix3fv(env); break;
        case 0x1123: ALOGV("glProgramUniformMatrix4fv"); nb_handle_glProgramUniformMatrix4fv(env); break;
        case 0x1124: ALOGV("glProgramUniformMatrix2x3fv"); nb_handle_glProgramUniformMatrix2x3fv(env); break;
        case 0x1125: ALOGV("glProgramUniformMatrix3x2fv"); nb_handle_glProgramUniformMatrix3x2fv(env); break;
        case 0x1126: ALOGV("glProgramUniformMatrix2x4fv"); nb_handle_glProgramUniformMatrix2x4fv(env); break;
        case 0x1127: ALOGV("glProgramUniformMatrix4x2fv"); nb_handle_glProgramUniformMatrix4x2fv(env); break;
        case 0x1128: ALOGV("glProgramUniformMatrix3x4fv"); nb_handle_glProgramUniformMatrix3x4fv(env); break;
        case 0x1129: ALOGV("glProgramUniformMatrix4x3fv"); nb_handle_glProgramUniformMatrix4x3fv(env); break;
        case 0x112a: ALOGV("glValidateProgramPipeline"); nb_handle_glValidateProgramPipeline(env); break;
        case 0x112b: ALOGV("glGetProgramPipelineInfoLog"); nb_handle_glGetProgramPipelineInfoLog(env); break;
        case 0x112c: ALOGV("glBindImageTexture"); nb_handle_glBindImageTexture(env); break;
        case 0x112d: ALOGV("glGetBooleani_v"); nb_handle_glGetBooleani_v(env); break;
        case 0x112e: ALOGV("glMemoryBarrier"); nb_handle_glMemoryBarrier(env); break;
        case 0x112f: ALOGV("glMemoryBarrierByRegion"); nb_handle_glMemoryBarrierByRegion(env); break;
        case 0x1130: ALOGV("glTexStorage2DMultisample"); nb_handle_glTexStorage2DMultisample(env); break;
        case 0x1131: ALOGV("glGetMultisamplefv"); nb_handle_glGetMultisamplefv(env); break;
        case 0x1132: ALOGV("glSampleMaski"); nb_handle_glSampleMaski(env); break;
        case 0x1133: ALOGV("glGetTexLevelParameteriv"); nb_handle_glGetTexLevelParameteriv(env); break;
        case 0x1134: ALOGV("glGetTexLevelParameterfv"); nb_handle_glGetTexLevelParameterfv(env); break;
        case 0x1135: ALOGV("glBindVertexBuffer"); nb_handle_glBindVertexBuffer(env); break;
        case 0x1136: ALOGV("glVertexAttribFormat"); nb_handle_glVertexAttribFormat(env); break;
        case 0x1137: ALOGV("glVertexAttribIFormat"); nb_handle_glVertexAttribIFormat(env); break;
        case 0x1138: ALOGV("glVertexAttribBinding"); nb_handle_glVertexAttribBinding(env); break;
        case 0x1139: ALOGV("glVertexBindingDivisor"); nb_handle_glVertexBindingDivisor(env); break;
        case 0x113a: ALOGV("glBlendBarrier"); nb_handle_glBlendBarrier(env); break;
        case 0x113b: ALOGV("glCopyImageSubData"); nb_handle_glCopyImageSubData(env); break;
        case 0x113c: ALOGV("glDebugMessageControl"); nb_handle_glDebugMessageControl(env); break;
        case 0x113d: ALOGV("glDebugMessageInsert"); nb_handle_glDebugMessageInsert(env); break;
        case 0x113e: ALOGV("glDebugMessageCallback"); nb_handle_glDebugMessageCallback(env); break;
        case 0x113f: ALOGV("glGetDebugMessageLog"); nb_handle_glGetDebugMessageLog(env); break;
        case 0x1140: ALOGV("glPushDebugGroup"); nb_handle_glPushDebugGroup(env); break;
        case 0x1141: ALOGV("glPopDebugGroup"); nb_handle_glPopDebugGroup(env); break;
        case 0x1142: ALOGV("glObjectLabel"); nb_handle_glObjectLabel(env); break;
        case 0x1143: ALOGV("glGetObjectLabel"); nb_handle_glGetObjectLabel(env); break;
        case 0x1144: ALOGV("glObjectPtrLabel"); nb_handle_glObjectPtrLabel(env); break;
        case 0x1145: ALOGV("glGetObjectPtrLabel"); nb_handle_glGetObjectPtrLabel(env); break;
        case 0x1146: ALOGV("glGetPointerv"); nb_handle_glGetPointerv(env); break;
        case 0x1147: ALOGV("glEnablei"); nb_handle_glEnablei(env); break;
        case 0x1148: ALOGV("glDisablei"); nb_handle_glDisablei(env); break;
        case 0x1149: ALOGV("glBlendEquationi"); nb_handle_glBlendEquationi(env); break;
        case 0x114a: ALOGV("glBlendEquationSeparatei"); nb_handle_glBlendEquationSeparatei(env); break;
        case 0x114b: ALOGV("glBlendFunci"); nb_handle_glBlendFunci(env); break;
        case 0x114c: ALOGV("glBlendFuncSeparatei"); nb_handle_glBlendFuncSeparatei(env); break;
        case 0x114d: ALOGV("glColorMaski"); nb_handle_glColorMaski(env); break;
        case 0x114e: ALOGV("glIsEnabledi"); nb_handle_glIsEnabledi(env); break;
        case 0x114f: ALOGV("glDrawElementsBaseVertex"); nb_handle_glDrawElementsBaseVertex(env); break;
        case 0x1150: ALOGV("glDrawRangeElementsBaseVertex"); nb_handle_glDrawRangeElementsBaseVertex(env); break;
        case 0x1151: ALOGV("glDrawElementsInstancedBaseVertex"); nb_handle_glDrawElementsInstancedBaseVertex(env); break;
        case 0x1152: ALOGV("glFramebufferTexture"); nb_handle_glFramebufferTexture(env); break;
        case 0x1153: ALOGV("glPrimitiveBoundingBox"); nb_handle_glPrimitiveBoundingBox(env); break;
        case 0x1154: ALOGV("glGetGraphicsResetStatus"); nb_handle_glGetGraphicsResetStatus(env); break;
        case 0x1155: ALOGV("glReadnPixels"); nb_handle_glReadnPixels(env); break;
        case 0x1156: ALOGV("glGetnUniformfv"); nb_handle_glGetnUniformfv(env); break;
        case 0x1157: ALOGV("glGetnUniformiv"); nb_handle_glGetnUniformiv(env); break;
        case 0x1158: ALOGV("glGetnUniformuiv"); nb_handle_glGetnUniformuiv(env); break;
        case 0x1159: ALOGV("glMinSampleShading"); nb_handle_glMinSampleShading(env); break;
        case 0x115a: ALOGV("glPatchParameteri"); nb_handle_glPatchParameteri(env); break;
        case 0x115b: ALOGV("glTexParameterIiv"); nb_handle_glTexParameterIiv(env); break;
        case 0x115c: ALOGV("glTexParameterIuiv"); nb_handle_glTexParameterIuiv(env); break;
        case 0x115d: ALOGV("glGetTexParameterIiv"); nb_handle_glGetTexParameterIiv(env); break;
        case 0x115e: ALOGV("glGetTexParameterIuiv"); nb_handle_glGetTexParameterIuiv(env); break;
        case 0x115f: ALOGV("glSamplerParameterIiv"); nb_handle_glSamplerParameterIiv(env); break;
        case 0x1160: ALOGV("glSamplerParameterIuiv"); nb_handle_glSamplerParameterIuiv(env); break;
        case 0x1161: ALOGV("glGetSamplerParameterIiv"); nb_handle_glGetSamplerParameterIiv(env); break;
        case 0x1162: ALOGV("glGetSamplerParameterIuiv"); nb_handle_glGetSamplerParameterIuiv(env); break;
        case 0x1163: ALOGV("glTexBuffer"); nb_handle_glTexBuffer(env); break;
        case 0x1164: ALOGV("glTexBufferRange"); nb_handle_glTexBufferRange(env); break;
        case 0x1165: ALOGV("glTexStorage3DMultisample"); nb_handle_glTexStorage3DMultisample(env); break;
        case 0x1166: ALOGV("glBlendBarrierKHR"); nb_handle_glBlendBarrierKHR(env); break;
        case 0x1167: ALOGV("glEnableiEXT"); nb_handle_glEnableiEXT(env); break;
        case 0x1168: ALOGV("glDisableiEXT"); nb_handle_glDisableiEXT(env); break;
        case 0x1169: ALOGV("glBlendEquationiEXT"); nb_handle_glBlendEquationiEXT(env); break;
        case 0x116a: ALOGV("glBlendEquationSeparateiEXT"); nb_handle_glBlendEquationSeparateiEXT(env); break;
        case 0x116b: ALOGV("glBlendFunciEXT"); nb_handle_glBlendFunciEXT(env); break;
        case 0x116c: ALOGV("glBlendFuncSeparateiEXT"); nb_handle_glBlendFuncSeparateiEXT(env); break;
        case 0x116d: ALOGV("glColorMaskiEXT"); nb_handle_glColorMaskiEXT(env); break;
        case 0x116e: ALOGV("glIsEnablediEXT"); nb_handle_glIsEnablediEXT(env); break;
        case 0x116f: ALOGV("glCopyImageSubDataEXT"); nb_handle_glCopyImageSubDataEXT(env); break;
        case 0x1170: ALOGV("glDebugMessageControlKHR"); nb_handle_glDebugMessageControlKHR(env); break;
        case 0x1171: ALOGV("glDebugMessageInsertKHR"); nb_handle_glDebugMessageInsertKHR(env); break;
        case 0x1172: ALOGV("glPushDebugGroupKHR"); nb_handle_glPushDebugGroupKHR(env); break;
        case 0x1173: ALOGV("glPopDebugGroupKHR"); nb_handle_glPopDebugGroupKHR(env); break;
        case 0x1174: ALOGV("glObjectLabelKHR"); nb_handle_glObjectLabelKHR(env); break;
        case 0x1175: ALOGV("glFramebufferTextureEXT"); nb_handle_glFramebufferTextureEXT(env); break;
        case 0x1176: ALOGV("glTexParameterIivEXT"); nb_handle_glTexParameterIivEXT(env); break;
        case 0x1177: ALOGV("glTexParameterIuivEXT"); nb_handle_glTexParameterIuivEXT(env); break;
        case 0x1178: ALOGV("glGetTexParameterIivEXT"); nb_handle_glGetTexParameterIivEXT(env); break;
        case 0x1179: ALOGV("glGetTexParameterIuivEXT"); nb_handle_glGetTexParameterIuivEXT(env); break;
        case 0x117a: ALOGV("glSamplerParameterIivEXT"); nb_handle_glSamplerParameterIivEXT(env); break;
        case 0x117b: ALOGV("glSamplerParameterIuivEXT"); nb_handle_glSamplerParameterIuivEXT(env); break;
        case 0x117c: ALOGV("glGetSamplerParameterIivEXT"); nb_handle_glGetSamplerParameterIivEXT(env); break;
        case 0x117d: ALOGV("glGetSamplerParameterIuivEXT"); nb_handle_glGetSamplerParameterIuivEXT(env); break;
        case 0x117e: ALOGV("glMinSampleShadingOES"); nb_handle_glMinSampleShadingOES(env); break;
        case 0x117f: ALOGV("glPatchParameteriEXT"); nb_handle_glPatchParameteriEXT(env); break;
        case 0x1180: ALOGV("glPrimitiveBoundingBoxEXT"); nb_handle_glPrimitiveBoundingBoxEXT(env); break;
        case 0x1181: ALOGV("glTexBufferEXT"); nb_handle_glTexBufferEXT(env); break;
        case 0x1182: ALOGV("glTexBufferRangeEXT"); nb_handle_glTexBufferRangeEXT(env); break;
        case 0x1183: ALOGV("glGenQueriesEXT"); nb_handle_glGenQueriesEXT(env); break;
        case 0x1184: ALOGV("glDeleteQueriesEXT"); nb_handle_glDeleteQueriesEXT(env); break;
        case 0x1185: ALOGV("glIsQueryEXT"); nb_handle_glIsQueryEXT(env); break;
        case 0x1186: ALOGV("glBeginQueryEXT"); nb_handle_glBeginQueryEXT(env); break;
        case 0x1187: ALOGV("glEndQueryEXT"); nb_handle_glEndQueryEXT(env); break;
        case 0x1188: ALOGV("glQueryCounterEXT"); nb_handle_glQueryCounterEXT(env); break;
        case 0x1189: ALOGV("glGetQueryivEXT"); nb_handle_glGetQueryivEXT(env); break;
        case 0x118a: ALOGV("glGetQueryObjectivEXT"); nb_handle_glGetQueryObjectivEXT(env); break;
        case 0x118b: ALOGV("glGetQueryObjectuivEXT"); nb_handle_glGetQueryObjectuivEXT(env); break;
        case 0x118c: ALOGV("glGetQueryObjecti64vEXT"); nb_handle_glGetQueryObjecti64vEXT(env); break;
        case 0x118d: ALOGV("glGetQueryObjectui64vEXT"); nb_handle_glGetQueryObjectui64vEXT(env); break;
        case 0x118e: ALOGV("glTexStorage3DMultisampleOES"); nb_handle_glTexStorage3DMultisampleOES(env); break;
        default: LOG_ALWAYS_FATAL("Unknown SVC %08x", svc); break;
    }
}
