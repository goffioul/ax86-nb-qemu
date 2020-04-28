#
# nb-qemu
#
# Copyright (c) 2019 Michael Goffioul
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; if not, see <http://www.gnu.org/licenses/>.
#

LOCAL_PATH := $(call my-dir)

LOCAL_QEMU_CFLAGS := \
	-Wno-unused-parameter -Wno-unused-variable -Wno-writable-strings \
	-Wno-pointer-arith

include $(CLEAR_VARS)
LOCAL_MODULE := libnb-qemu
LOCAL_SRC_FILES := \
	JavaBridge.cpp \
	Library.cpp \
	OsBridge.cpp \
	QemuAndroid.c \
	QemuBridge.cpp \
	QemuCpu.cpp \
	Trampoline.cpp \
	libnb-qemu.cpp
LOCAL_SHARED_LIBRARIES := libnativehelper liblog libz libbase libdl
LOCAL_STATIC_LIBRARIES := libqemu-core libqemu-target libqemu-glib libqemu-capstone libffi
LOCAL_CFLAGS := $(LOCAL_QEMU_CFLAGS)
LOCAL_C_INCLUDES := system/core/libnativebridge/include
LOCAL_EXPORT_STATIC_LIBRARY_HEADERS := libqemu-core libqemu-target libqemu-glib libffi
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libnb-qemu-EGL
LOCAL_SRC_FILES := libEGL.c
LOCAL_CFLAGS := \
	-fvisibility=hidden $(LOCAL_QEMU_CFLAGS) \
	-DGL_GLEXT_PROTOTYPES -DEGL_EGLEXT_PROTOTYPES
LOCAL_SHARED_LIBRARIES := libnb-qemu liblog libEGL
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libnb-qemu-GLESv3
LOCAL_SRC_FILES := libGLESv3.c
LOCAL_CFLAGS := \
	-fvisibility=hidden $(LOCAL_QEMU_CFLAGS) \
	-DGL_GLEXT_PROTOTYPES -DEGL_EGLEXT_PROTOTYPES
LOCAL_SHARED_LIBRARIES := libnb-qemu liblog libGLESv3
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libnb-qemu-GLESv1_CM
LOCAL_SRC_FILES := libGLESv1_CM.c
LOCAL_CFLAGS := \
	-fvisibility=hidden $(LOCAL_QEMU_CFLAGS) \
	-DGL_GLEXT_PROTOTYPES -DEGL_EGLEXT_PROTOTYPES
LOCAL_SHARED_LIBRARIES := libnb-qemu liblog libGLESv1_CM
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libnb-qemu-OpenSLES
LOCAL_SRC_FILES := libOpenSLES.c libOpenSLES.itf.cpp
LOCAL_CFLAGS := \
	-fvisibility=hidden $(LOCAL_QEMU_CFLAGS)
LOCAL_SHARED_LIBRARIES := libnb-qemu liblog libOpenSLES
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := libnb-qemu-android
LOCAL_SRC_FILES := libandroid.c libandroid.itf.cpp
LOCAL_CFLAGS := \
	-fvisibility=hidden $(LOCAL_QEMU_CFLAGS)
LOCAL_SHARED_LIBRARIES := libnb-qemu liblog libandroid
include $(BUILD_SHARED_LIBRARY)
