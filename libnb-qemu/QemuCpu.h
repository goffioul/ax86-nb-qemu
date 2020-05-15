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

#ifndef QEMU_CPU_H_
#define QEMU_CPU_H_

class QemuCpu
{
public:
    static QemuCpu* get();

    QemuCpu();
    ~QemuCpu();

    uint32_t call(uint32_t addr) const { return call(addr, 0, 0, 0, 0, nullptr, 0); }
    uint32_t call(uint32_t addr, uint32_t arg1) const { return call(addr, arg1, 0, 0, 0, nullptr, 0); }
    uint32_t call(uint32_t addr, uint32_t arg1, uint32_t arg2) const { return call(addr, arg1, arg2, 0, 0, nullptr, 0); }
    uint32_t call(uint32_t addr, uint32_t arg1, uint32_t arg2, uint32_t arg3) const { return call(addr, arg1, arg2, arg3, 0, nullptr, 0); }
    uint32_t call(uint32_t addr, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4) const { return call(addr, arg1, arg2, arg3, arg4, nullptr, 0); }
    uint32_t call(uint32_t addr, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, char *stack, int stack_size) const;
    uint64_t call64(uint32_t addr, uint32_t arg1, uint32_t arg2, uint32_t arg3, uint32_t arg4, char *stack, int stack_size) const;

private:
    static thread_local QemuCpu local_cpu_;

private:
    void *cpu_;
    bool managed_;
};

#endif
