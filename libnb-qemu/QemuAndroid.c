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

#define LOG_TAG "libnb-qemu"
#define LOG_NDEBUG 0

#include <log/log.h>
#include "QemuAndroid.h"

#define NEED_CPU_H
#undef NDEBUG

#include <qemu/osdep.h>
#include <qemu/guest-random.h>
#include <disas/disas.h>
#include <elf.h>
#include <qemu.h>
#include <cpu_loop-common.h>

static uint32_t thread_allocate_;
static uint32_t thread_deallocate_;

int qemu_android_initialize()
{
    char *argv[] = { LOG_TAG, "-d", "page,unimp", "-E", "LD_DEBUG=1", "/system/lib/libnb-qemu-guest.so" };
    int result = qemu_main(sizeof(argv)/sizeof(char*), argv, NULL);
    if (result == 0) {
        thread_allocate_ = qemu_android_lookup_symbol("nb_qemu_allocateThread");
        ALOGV("QemuAndroid::thread_allocate_: %p", (void *)thread_allocate_);
        thread_deallocate_ = qemu_android_lookup_symbol("nb_qemu_deallocateThread");
        ALOGV("QemuAndroid::thread_deallocate_: %p", (void *)thread_deallocate_);
    }
    return result;
}

uint32_t qemu_android_lookup_symbol(const char *name)
{
    if (syminfos) {
        struct syminfo *s = syminfos;

        while (s) {
            struct elf32_sym *syms = s->disas_symtab.elf32;

            for (int i = 0; i < s->disas_num_syms; i++) {
                if (strcmp(s->disas_strtab + syms[i].st_name, name) == 0) {
                    return syms[i].st_value;
                }
            }
            s = s->next;
        }
    }

    return 0;
}

uint32_t qemu_android_malloc(size_t size)
{
    uint32_t guest_addr;

    guest_addr = target_mmap(0, size + sizeof(size), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (guest_addr == -1)
      return 0;
    copy_to_user(guest_addr, &size, sizeof(size));
    return guest_addr + sizeof(size);
}

void qemu_android_free(uint32_t addr)
{
    size_t size;
    uint32_t guest_addr = addr - sizeof(size);

    if (copy_from_user(&size, guest_addr, sizeof(size)) == 0) {
        target_munmap(guest_addr, size);
    }
}

void qemu_android_memcpy(uint32_t dest, const void *src, size_t length)
{
    copy_to_user(dest, (void *)src, length);
}

const char *qemu_android_get_string(uint32_t addr)
{
    return (const char *)lock_user_string(addr);
}

void qemu_android_release_string(const char *s, uint32_t addr)
{
    unlock_user((void *)s, addr, 0);
}

void *qemu_android_get_memory(uint32_t addr, size_t length)
{
    return lock_user(VERIFY_READ, addr, length, 1);
}

void qemu_android_release_memory(void *ptr, uint32_t addr, size_t length)
{
    unlock_user(ptr, addr, length);
}

void qemu_android_register_syscall_handler(qemu_android_syscall_handler_t func)
{
    syscall_handler = func;
}

static void qemu_android_call_internal(CPUState *cpu, uint32_t addr, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, char *stack, int stack_size)
{
    CPUArchState *env = cpu->env_ptr;
    uint32_t saved_lr = env->regs[14];
    uint32_t saved_pc = env->regs[15];
    uint32_t saved_thumb = env->thumb;

    ALOGV("calling: 0x%08x (0x%08x, 0x%08x, 0x%08x, 0x%08x, #%d)\n", addr, arg1, arg2, arg3, arg4, stack_size);
#ifdef LOG_NDEBUG
    if (stack) {
        ALOGV("  stack:");
        for (int i = 0; i < stack_size && i < 16; i += 4) ALOGV("    %08x\n", *(uint32_t*)&stack[i]);
    }
#endif
    env->regs[15] = addr & ~(target_ulong)1;
    env->regs[14] = info->start_code;
    env->regs[0] = arg1;
    env->regs[1] = arg2;
    env->regs[2] = arg3;
    env->regs[3] = arg4;
    if (stack) {
        env->regs[13] -= stack_size;
        memcpy_to_target(env->regs[13], stack, stack_size);
    }
    env->thumb = addr & 1;
    cpu->exception_index = -1;
    cpu_loop(env);

    if (stack) {
        env->regs[13] += stack_size;
    }

    env->regs[14] = saved_lr;
    env->regs[15] = saved_pc;
    env->thumb = saved_thumb;
    cpu->exception_index = -1;
}

uint32_t qemu_android_call5(void *_cpu, uint32_t addr, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, char *stack, int stack_size)
{
    CPUState *cpu = (CPUState *)_cpu;
    CPUArchState *env = cpu->env_ptr;
    qemu_android_call_internal(cpu, addr, arg1, arg2, arg3, arg4, stack, stack_size);
    return env->regs[0];
}

uint64_t qemu_android_call5_ll(void *_cpu, uint32_t addr, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, char *stack, int stack_size)
{
    CPUState *cpu = (CPUState *)_cpu;
    CPUArchState *env = cpu->env_ptr;
    qemu_android_call_internal(cpu, addr, arg1, arg2, arg3, arg4, stack, stack_size);
    uint64_t ret = env->regs[1];
    ret <<= 32;
    ret |= env->regs[0];
    return ret;
}

void *qemu_android_get_cpu()
{
    return thread_cpu;
}

void *qemu_android_new_cpu()
{
    if (! thread_cpu && thread_allocate_) {
        CPUState *cpu;
        CPUArchState *env;
        struct target_pt_regs regs1, *regs = &regs1;
        TaskState *ts;
        abi_long sp, stackp, tlsp, thrp, retp;
        struct {
            abi_long prev, next;
            pid_t tid, pid;
        } thr;
        abi_long *alloc_result;

        ALOGV("Creating new CPU");

        cpu = cpu_create(cpu_type);
        env = cpu->env_ptr;
        cpu_reset(cpu);

        ts = g_new0(TaskState, 1);
        init_task_state(ts);
        ts->info = info;
        ts->bprm = bprm;
        cpu->opaque = ts;
        task_settid(ts);

#define NEW_STACK_SIZE (4 * TARGET_PAGE_SIZE)
#define TLS_SIZE (sizeof(abi_long) * 8)

        sp = target_mmap(0, NEW_STACK_SIZE, PROT_READ | PROT_WRITE,
                         MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        LOG_ALWAYS_FATAL_IF(sp == -1, "Failed to allocate temporary");

        tlsp = sp + NEW_STACK_SIZE - TLS_SIZE;
        thrp = tlsp - sizeof(thr);
        retp = thrp - 2 * sizeof(abi_long);
        stackp = (retp & ~7);

        thr.tid = ts->ts_tid;
        thr.pid = getppid();
        memcpy_to_target(thrp, &thr, sizeof(thr));
        memcpy_to_target(tlsp + sizeof(abi_long), &thrp, sizeof(abi_long));

        rcu_register_thread();
        tcg_register_thread();

        cpu->random_seed = qemu_guest_random_seed_thread_part1();
        qemu_guest_random_seed_thread_part2(cpu->random_seed);

        do_init_thread(regs, info);
        target_cpu_copy_regs(env, regs);
        env->regs[13] = stackp;
        cpu_set_tls(env, tlsp);
        env->pc_stop = info->start_code;

        ALOGV("Allocating new CPU thread");
        env->regs[0] = retp;
        env->regs[1] = retp + sizeof(abi_long);
        env->regs[2] = env->regs[3] = 0;
        env->regs[14] = info->start_code;
        env->regs[15] = thread_allocate_ & ~(target_ulong)1;
        env->thumb = thread_allocate_ & 1;
        cpu_loop(env);
        if (env->regs[0] == 0) {
            alloc_result = (abi_long *) qemu_android_get_memory(retp, 2 * sizeof(abi_long));
            ALOGV("New CPU thread allocated: stack=%08x, tls=%08x", alloc_result[0], alloc_result[1]);
            env->regs[13] = alloc_result[0];
            cpu_set_tls(env, alloc_result[1]);
            qemu_android_release_memory(alloc_result, retp, 2 * sizeof(abi_long));
            target_munmap(sp, NEW_STACK_SIZE);
        }
        else {
            ALOGE("CPU thread allocation failed: %d", env->regs[0]);
        }

        thread_cpu = cpu;

        ALOGV("New CPU created = %p", thread_cpu);
    }

    return thread_cpu;
}

void qemu_android_delete_cpu(void *_cpu)
{
    CPUState *cpu = (CPUState *)_cpu;
    CPUArchState *env = cpu->env_ptr;
    TaskState *ts;

    ALOGV("Deleting CPU = %p", cpu);

    if (thread_deallocate_) {
        abi_long tp, stackp, sizep;
        abi_long *dealloc_result;

        tp = target_mmap(0, sizeof(abi_long) * 2, PROT_READ | PROT_WRITE,
                         MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
        LOG_ALWAYS_FATAL_IF(tp == -1, "Failed to allocate temporary stack");

        stackp = tp;
        sizep = tp + sizeof(abi_long);

        dealloc_result = (abi_long *) qemu_android_get_memory(tp, sizeof(abi_long) * 2);
        memset(dealloc_result, 0, sizeof(abi_long) * 2);
        qemu_android_release_memory(dealloc_result, tp, sizeof(abi_long) * 2);

        ALOGV("Deallocating CPU thread");
        env->regs[0] = stackp;
        env->regs[1] = sizep;
        env->regs[2] = env->regs[3] = 0;
        env->regs[14] = info->start_code;
        env->regs[15] = thread_deallocate_ & ~(target_ulong)1;
        env->thumb = thread_deallocate_ & 1;
        cpu_loop(env);

        dealloc_result = (abi_long *) qemu_android_get_memory(tp, sizeof(abi_long) * 2);
        ALOGV("CPU thread deallocation result: stack=%08x, size=%08x", dealloc_result[0], dealloc_result[1]);
        target_munmap(dealloc_result[0], dealloc_result[1]);
        qemu_android_release_memory(dealloc_result, tp, sizeof(abi_long) * 2);
        target_munmap(tp, sizeof(abi_long) * 2);
    }

    cpu_list_lock();
    QTAILQ_REMOVE_RCU(&cpus, cpu, node);
    cpu_list_unlock();

    ts = cpu->opaque;
    thread_cpu = NULL;
    object_unref(OBJECT(cpu));
    g_free(ts);
    rcu_unregister_thread();

    ALOGV("CPU deleted = %p", cpu);
}
