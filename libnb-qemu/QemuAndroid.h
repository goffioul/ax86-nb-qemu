/*
 * nb-qemu
 * 
 * Copyright (c) 2019 Michael Goffioul
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef QEMU_ANDROID_H_
#define QEMU_ANDROID_H_

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int qemu_android_initialize();
uint32_t qemu_android_lookup_symbol(const char *name);
uint32_t qemu_android_malloc(size_t size);
void qemu_android_free(uint32_t addr);
void qemu_android_memcpy(uint32_t dest, const void *src, size_t length);
const char *qemu_android_get_string(uint32_t addr);
void qemu_android_release_string(const char *s, uint32_t addr);
void *qemu_android_get_memory(uint32_t addr, size_t length);
void qemu_android_release_memory(void *ptr, uint32_t addr, size_t length);
#define qemu_android_call0(c, x) qemu_android_call5(c, x, 0, 0, 0, 0, 0, 0)
#define qemu_android_call1(c, x, a1) qemu_android_call5(c, x, a1, 0, 0, 0, 0, 0)
#define qemu_android_call2(c, x, a1, a2) qemu_android_call5(c, x, a1, a2, 0, 0, 0, 0)
#define qemu_android_call3(c, x, a1, a2, a3) qemu_android_call5(c, x, a1, a2, a3, 0, 0, 0)
#define qemu_android_call4(c, x, a1, a2, a3, a4) qemu_android_call5(c, x, a1, a2, a3, a4, 0, 0)
uint32_t qemu_android_call5(void *cpu, uint32_t addr, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, char *stack, int stack_size);
uint64_t qemu_android_call5_ll(void *cpu, uint32_t addr, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, char *stack, int stack_size);
typedef int32_t(*qemu_android_syscall_handler_t)(
    void *cpu_env, int num,
    uint32_t arg1, uint32_t arg2, uint32_t arg3,
    uint32_t arg4, uint32_t arg5, uint32_t arg6);
void qemu_android_register_syscall_handler(qemu_android_syscall_handler_t func);
void *qemu_android_get_cpu();
void *qemu_android_new_cpu();
void qemu_android_delete_cpu(void *cpu);

#ifdef __cplusplus
};
#endif

#endif
