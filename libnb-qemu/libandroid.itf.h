#ifndef LIBANDROID_ITF_H_
#define LIBANDROID_ITF_H_

#include <android/input.h>
#include <android/looper.h>
#include <android/sensor.h>

#ifdef __cplusplus
extern "C" {
#endif

int libandroid_ALooper_addFd (ALooper* looper, int fd, int ident, int events, ALooper_callbackFunc callback, void* data);
ASensorEventQueue* libandroid_ASensorManager_createEventQueue (ASensorManager* manager, ALooper* looper, int ident,
                                                               ALooper_callbackFunc callback, void* data);
void libandroid_AInputQueue_attachLooper (AInputQueue* queue, ALooper* looper, int ident, ALooper_callbackFunc callback, void* data);

#ifdef __cplusplus
}
#endif

#endif
