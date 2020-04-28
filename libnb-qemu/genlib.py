#!/usr/bin/env python3

import argparse
import re
import sys

parser = argparse.ArgumentParser()
parser.add_argument('file', nargs=1)
parser.add_argument('-b', metavar='base', type=lambda x: int(x, 0), default=0x0100)
parser.add_argument('-g', action='store_true')
parser.add_argument('-d', action='store_true')
parser.add_argument('-i', metavar='include', action='append', default=[])
parser.add_argument('-a', metavar='include_after', action='append', default=[])
parser.add_argument('-p', metavar='prefix')
parsed_args = parser.parse_args()

base = parsed_args.b
guest = parsed_args.g
debug = parsed_args.d
includes = parsed_args.i
includes_after = parsed_args.a
prefix = parsed_args.p or ''
functions = []

with open(parsed_args.file[0]) as f:
    for idx, line in enumerate(f):
        line = line.strip()
        if line.startswith('%'):
            cmdmode = None
            cmd, cmdarg = line[1:].split(maxsplit=1)
            if ':' in cmd:
                cmdmode, cmd = cmd.split(':', maxsplit=1)
                if cmdmode not in ['host', 'guest']:
                    raise ValueError('unknown command mode: %s' % cmdmode)
            if cmdmode is None or (cmdmode == 'host' and not guest) or (cmdmode == 'guest' and guest):
                if cmd == 'base':
                    base = int(cmdarg, 0)
                elif cmd == 'include':
                    includes.append(cmdarg)
                elif cmd == 'include_after':
                    includes_after.append(cmdarg)
                elif cmd == 'prefix':
                    prefix = cmdarg
                else:
                    raise ValueError('unknown command: %s' % cmd)
        elif line:
            if line.startswith('host:'):
                if guest:
                    continue
                line = line[5:].strip()
            elif line.startswith('guest:'):
                if not guest:
                    continue
                line = line[6:].strip()
            ret, name, sig = line.split(maxsplit=2)
            sig = sig[1:-1].strip()
            args = [x.split(maxsplit=1) for x in re.split(r', *', sig)] if sig != 'void' else []
            functions.append({
                'name': name,
                'return': ret,
                'arguments': args,
                'lineno': idx + 1
            })

def isPointerType(type):
    return type.startswith('ptr:') or \
            type in ['GLsync', 'EGLDisplay', 'EGLConfig', 'EGLSurface', 'EGLContext', 'EGLSync', 'EGLImage',
                     'EGLNativePixmapType', 'EGLNativeWindowType', 'EGLNativeDisplayType', 'EGLClientBuffer',
                     'EGLSyncKHR', 'EGLImageKHR', 'EGLStreamKHR', 'GLeglImageOES']

def getArgumentTypeAndSize(type, lineno=0):
    if type in ['int', 'int32_t', 'ssize_t', 'off_t', 'float',
                'GLint', 'GLenum', 'GLfloat', 'GLintptr', 'GLfixed', 'GLclampx', 'GLclampf',
                'EGLint', 'EGLenum', 'EGLNativeFileDescriptorKHR']:
        return type, 4
    elif type in ['uint32_t', 'size_t',
                  'GLuint', 'GLbitfield', 'GLsizei', 'GLsizeiptr']:
        return type, 4
    elif type in ['int16_t', 'GLshort']:
        return type, 2
    elif type in ['int8_t', 'uint8_t', 'GLboolean', 'GLubyte', 'EGLBoolean']:
        return type, 1
    elif isPointerType(type):
        return 'void*', 4
    elif type in ['int64_t', 'uint64_t', 'double', 'off64_t',
                  'GLint64', 'GLuint64', 'EGLTime', 'EGLTimeKHR', 'EGLnsecsANDROID', 'EGLuint64KHR', 'EGLuint64NV']:
        return type, 8
    elif type == 'void':
        return 'void', 0
    else:
        raise NotImplementedError('line %d: unsupported type: %s' % (lineno, type))

def genHostLib():
    print('''#define LOG_TAG "libnb-qemu"
%s
#include <stdint.h>
#include <log/log.h>
#include "QemuInclude.h"''' % ("#define LOG_NDEBUG 0\n" if debug else ''))

    if includes:
        for inc in includes:
            print('#include %s' % inc)

    print('')
    print('extern void* unwrap_jni_env(void* env);')
    print('')

    for i, func in enumerate(functions):
        print('void nb_handle_%s(CPUARMState *env) {' % func['name'])
        print('    char *sp = g2h(env->regs[13]);')
        ret_type, ret_size = getArgumentTypeAndSize(func['return'], lineno=func['lineno'])
        if ret_size:
            print('    %s __nb_ret = (%s)%s(' % (ret_type, ret_type, func['name']))
        else:
            print('    %s(' % func['name'])
        nargs = len(func['arguments'])
        offset = 0
        for j, arg in enumerate(func['arguments']):
            if len(arg) > 1 and arg[1].startswith('*'):
                raise NotImplementedError('line %d: unsupported pointer type' % func['lineno'])
            arg_type, arg_size = getArgumentTypeAndSize(arg[0], lineno=func['lineno'])
            if arg_size == 8:
                offset = (offset+7)&(~7)
            if arg[0] == 'ptr:JNIEnv':
                print('        unwrap_jni_env(*(%s*)(&sp[%d]))%s' % (arg_type, offset, ',' if j < (nargs-1) else ''))
            else:
                print('        *(%s*)(&sp[%d])%s' % (arg_type, offset, ',' if j < (nargs-1) else ''))
            offset += ((arg_size+3)&(~3))
        print('    );')
        if ret_size:
            if ret_size <= 4:
                if isPointerType(func['return']):
                    print('    env->regs[0] = h2g_nocheck(__nb_ret);')
                elif ret_size == 4:
                    print('    env->regs[0] = *(abi_ulong*)(&__nb_ret);')
                elif ret_size == 2:
                    print('    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xffff;')
                else:
                    print('    env->regs[0] = (*(abi_ulong*)(&__nb_ret)) & 0xff;')
            elif ret_size == 8:
                print('    env->regs[0] = __nb_ret & 0xffffffff;')
                print('    env->regs[1] = (__nb_ret >> 32) & 0xffffffff;')
            else:
                raise NotImplementedError('line %d: unsupported return type: %s' % (func['lineno'], ret_type))
        print('}')

    print('__attribute__((visibility("default")))')
    print('void nb_handle_svc(CPUARMState *env, int svc) {')
    print('    switch (svc) {')
    for i, func in enumerate(functions):
        debug_line = ''
        if debug:
            debug_line = 'ALOGV("%s"); ' % func['name']
        print('        case 0x%04x: %snb_handle_%s(env); break;' % ((base + i), debug_line, func['name']))
    print('        default: LOG_ALWAYS_FATAL("Unknown SVC %08x", svc); break;')
    print('    }')
    print('}')

    if includes_after:
        print('')
        for inc in includes_after:
            print('#include %s' % inc)

def genGuestLib():
    if includes:
        for inc in includes:
            print('#include %s' % inc)
        print('')
    for i, func in enumerate(functions):
        print('''__attribute__((naked,noinline)) void %s%s() {
    __asm__ volatile(
        "push {r0, r1, r2, r3}\\n"
        "svc #0x%04x\\n"
        "add sp, sp, #16\\n" 
        "bx lr"
    );
}''' % (prefix, func['name'], (base + i)))
    if includes_after:
        print('')
        for inc in includes_after:
            print('#include %s' % inc)

if guest:
    genGuestLib()
else:
    genHostLib()
