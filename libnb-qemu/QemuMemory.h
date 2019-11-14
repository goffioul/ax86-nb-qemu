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

#ifndef QEMU_MEMORY_H_
#define QEMU_MEMORY_H_

#include "QemuAndroid.h"

namespace QemuMemory {

inline uint32_t malloc(size_t size) { return qemu_android_malloc(size); }
inline void free(uint32_t addr) { qemu_android_free(addr); }
inline void memcpy(uint32_t dest, const void *src, size_t size) { qemu_android_memcpy(dest, src, size); }

class Malloc
{
public:
    Malloc(size_t size)
        : addr_(qemu_android_malloc(size)) {
    }
    ~Malloc() {
        if (addr_) {
            qemu_android_free(addr_);
        }
    }

    uint32_t get_address() const { return addr_; }
    operator bool() const { return addr_ != 0; }

    void memcpy(const void *src, size_t size) {
        qemu_android_memcpy(addr_, src, size);
    }

private:
    uint32_t addr_;
};

class String
{
public:
    String(uint32_t addr)
        : addr_(addr),
          s_(reinterpret_cast<const char *>(qemu_android_get_string(addr))) {
    }
    ~String() {
        if (s_) {
            qemu_android_release_string(s_, addr_);
        }
    }

    const char *c_str() const { return s_; }

private:
    uint32_t addr_;
    const char *s_;
};

template<class T>
class Region
{
public:
    Region(uint32_t addr, size_t num = 1)
        : addr_(addr),
          size_(sizeof(T) * num),
          p_(reinterpret_cast<T *>(qemu_android_get_memory(addr_, size_))) {
    }
    ~Region() {
        if (p_) {
            qemu_android_release_memory(p_, addr_, size_);
        }
    }

    T *get() const { return p_; }
    const T& operator[] (int index) const { return p_[index]; }

private:
    uint32_t addr_;
    size_t size_;
    T *p_;
};

}

#endif
