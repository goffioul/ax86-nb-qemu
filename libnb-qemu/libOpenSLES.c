#define LOG_TAG "libnb-qemu"

#include <stdint.h>
#include <log/log.h>
#include "QemuInclude.h"
#include <SLES/OpenSLES.h>
#include <SLES/OpenSLES_Android.h>
#include <libOpenSLES.common.c>

void nb_handle_slCreateEngine(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)slCreateEngine(
        *(void**)(&sp[0]),
        *(int*)(&sp[4]),
        *(void**)(&sp[8]),
        *(int*)(&sp[12]),
        *(void**)(&sp[16]),
        *(void**)(&sp[20])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLObjectItf_Realize(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLObjectItf_Realize(
        *(void**)(&sp[0]),
        *(uint32_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
__attribute__((visibility("default")))
void nb_handle_svc(CPUARMState *env, int svc) {
    switch (svc) {
        case 0x0600: nb_handle_slCreateEngine(env); break;
        case 0x0601: nb_handle_SLObjectItf_Realize(env); break;
        default: LOG_ALWAYS_FATAL("Unknown SVC %08x", svc); break;
    }
}
