#include <map>
#include <memory>
#include "libOpenSLES.itf.h"
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

extern "C" {

SLresult SLBufferQueueItf_RegisterCallback (SLBufferQueueItf self, void *callback, void *pContext)
{
  slBufferQueueCallback nativeCallback = (slBufferQueueCallback) get_trampoline(callback, "SLBufferQueue_Callback", "vpp");
  return (*self)->RegisterCallback(self, nativeCallback, pContext);
}

SLresult SLObjectItf_RegisterCallback (SLObjectItf self, void *callback, void *pContext)
{
  slObjectCallback nativeCallback = (slObjectCallback) get_trampoline(callback, "SLObjectItf_Callback", "vppIIIp");
  return (*self)->RegisterCallback(self, nativeCallback, pContext);
}

SLresult SLPlayItf_RegisterCallback (SLPlayItf self, void *callback, void *pContext)
{
  slPlayCallback nativeCallback = (slPlayCallback) get_trampoline(callback, "SLPlayItf_Callback", "vppI");
  return (*self)->RegisterCallback(self, nativeCallback, pContext);
}

SLresult SLAndroidSimpleBufferQueueItf_RegisterCallback (SLAndroidSimpleBufferQueueItf self, void *callback, void *pContext)
{
  slAndroidSimpleBufferQueueCallback nativeCallback = (slAndroidSimpleBufferQueueCallback) get_trampoline(callback, "SLAndroidSimpleBufferQueue_Callback", "vpp");
  return (*self)->RegisterCallback(self, nativeCallback, pContext);
}

};
