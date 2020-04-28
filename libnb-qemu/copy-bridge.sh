#!/bin/bash

TARGET_OUT="$ANDROID_PRODUCT_OUT/system/lib"
BRIDGE_ENVIRONMENT="$BRIDGE_ENVIRONMENT $TARGET_OUT/libnb-qemu.so"
BRIDGE_ENVIRONMENT="$BRIDGE_ENVIRONMENT $TARGET_OUT/libnb-qemu-EGL.so"
BRIDGE_ENVIRONMENT="$BRIDGE_ENVIRONMENT $TARGET_OUT/libnb-qemu-GLESv1_CM.so"
BRIDGE_ENVIRONMENT="$BRIDGE_ENVIRONMENT $TARGET_OUT/libnb-qemu-GLESv3.so"
BRIDGE_ENVIRONMENT="$BRIDGE_ENVIRONMENT $TARGET_OUT/libnb-qemu-OpenSLES.so"
BRIDGE_ENVIRONMENT="$BRIDGE_ENVIRONMENT $TARGET_OUT/libnb-qemu-android.so"

adb shell umount /system/lib/libhoudini.so
adb shell mount -o rw,remount /

trap 'adb shell mount -o ro,remount /' EXIT

for f in $BRIDGE_ENVIRONMENT; do
        adb push $f /system/lib/`basename $f`
done

adb shell mount --bind /system/lib/libnb-qemu.so /system/lib/libhoudini.so
