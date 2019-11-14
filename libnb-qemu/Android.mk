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

include $(CLEAR_VARS)
LOCAL_MODULE := libnb-qemu
LOCAL_SRC_FILES := \
	JavaBridge.cpp \
	Library.cpp \
	QemuAndroid.c \
	QemuBridge.cpp \
	QemuCpu.cpp \
	Trampoline.cpp \
	libnb-qemu.cpp
LOCAL_SHARED_LIBRARIES := liblog libz libbase
LOCAL_STATIC_LIBRARIES := libqemu-core libqemu-target libqemu-glib libqemu-capstone libffi
LOCAL_CFLAGS := \
	-Wno-unused-parameter -Wno-unused-variable -Wno-writable-strings \
	-Wno-pointer-arith
LOCAL_C_INCLUDES := system/core/libnativebridge/include
include $(BUILD_SHARED_LIBRARY)
