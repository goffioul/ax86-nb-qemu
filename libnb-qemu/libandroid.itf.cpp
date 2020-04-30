#include <map>
#include <memory>
#include "libandroid.itf.h"
#include "Trampoline.h"

static std::map<void*, std::shared_ptr<Trampoline>> sCallbacks;

static void* get_trampoline(void *callback, const char *name, const char *sig)
{
  std::map<void*, std::shared_ptr<Trampoline>>::const_iterator it = sCallbacks.find(callback);
  std::shared_ptr<Trampoline> nativeCallback;

  if (it != sCallbacks.end())
    nativeCallback = it->second;
  else {
      nativeCallback.reset(new Trampoline(name, (uint32_t) callback, sig));
      sCallbacks[callback] = nativeCallback;
  }

  return nativeCallback->get_handle();
}

// FIXME: This is leaky, trampolines are never removed

int libandroid_ALooper_addFd(ALooper* looper, int fd, int ident, int events, ALooper_callbackFunc callback, void* data)
{
  ALooper_callbackFunc nativeCallback = (ALooper_callbackFunc) get_trampoline((void *) callback, "ALooper_Callback", "iiip");
  return ALooper_addFd(looper, fd, ident, events, nativeCallback, data);
}

ASensorEventQueue* libandroid_ASensorManager_createEventQueue(ASensorManager* manager, ALooper* looper, int ident,
                                                              ALooper_callbackFunc callback, void* data)
{
  ALooper_callbackFunc nativeCallback = (ALooper_callbackFunc) get_trampoline((void *) callback, "ASensorEventQueue_Callback", "iiip");
  return ASensorManager_createEventQueue(manager, looper, ident, nativeCallback, data);
}
