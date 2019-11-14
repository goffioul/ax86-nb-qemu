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

#include "QemuAndroid.h"
#include "QemuCpu.h"

thread_local QemuCpu QemuCpu::local_cpu_;

QemuCpu* QemuCpu::get()
{
    if (! local_cpu_.cpu_) {
        void *cpu = qemu_android_get_cpu();
        if (! cpu) {
            local_cpu_.cpu_ = qemu_android_new_cpu();
            local_cpu_.managed_ = true;
        }
        else {
            local_cpu_.cpu_ = cpu;
            local_cpu_.managed_ = false;
        }
    }
    return &local_cpu_;
}

QemuCpu::QemuCpu()
     : cpu_(nullptr), managed_(false)
{
}

QemuCpu::~QemuCpu()
{
    if (managed_) {
        qemu_android_delete_cpu(cpu_);
    }
}

uint32_t QemuCpu::call(uint32_t addr, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, char *stack, int stack_size) const
{
    return qemu_android_call5(cpu_, addr, arg1, arg2, arg3, arg4, stack, stack_size);
}

uint64_t QemuCpu::call64(uint32_t addr, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, char *stack, int stack_size) const
{
    return qemu_android_call5_ll(cpu_, addr, arg1, arg2, arg3, arg4, stack, stack_size);
}
