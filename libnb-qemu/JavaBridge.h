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

#ifndef JAVA_BRIDGE_H_
#define JAVA_BRIDGE_H_

#include <jni.h>
#include <nativebridge/native_bridge.h>

namespace JavaBridge {
    using android::NativeBridgeRuntimeCallbacks;
    void initialize(const NativeBridgeRuntimeCallbacks *runtime);
    uint32_t wrap_jni_env(JNIEnv *env);
    uint32_t wrap_java_vm(JavaVM *vm);
}

#endif
