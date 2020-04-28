#include <SLES/OpenSLES.h>

#ifdef __cplusplus
extern "C" {
#endif

inline SLresult SLBufferQueueItf_Enqueue (SLBufferQueueItf self, const void *pBuffer, SLuint32 size)
  { return (*self)->Enqueue(self, pBuffer, size); }
inline SLresult SLBufferQueueItf_Clear (SLBufferQueueItf self)
  { return (*self)->Clear(self); }
extern SLresult SLBufferQueueItf_RegisterCallback (SLBufferQueueItf self, void *callback, void *pContext);

inline SLresult SLEffectSendItf_EnableEffectSend (SLEffectSendItf self, const void *pAuxEffect, SLboolean enable, SLmillibel initialLevel)
  { return (*self)->EnableEffectSend(self, pAuxEffect, enable, initialLevel); }

inline SLresult SLEngineItf_CreateAudioPlayer (SLEngineItf self, SLObjectItf *pPlayer, SLDataSource *pAudioSrc, SLDataSink *pAudioSnk,
                                               SLuint32 numInterfaces, const SLInterfaceID *pInterfaces, const SLboolean *pInterfaceRequired)
  { return (*self)->CreateAudioPlayer(self, pPlayer, pAudioSrc, pAudioSnk, numInterfaces, pInterfaces, pInterfaceRequired); }
inline SLresult SLEngineItf_CreateOutputMix (SLEngineItf self, SLObjectItf *pMix, SLuint32 numInterfaces, const SLInterfaceID *pInterfaces,
                                             const SLboolean *pInterfaceRequired)
  { return (*self)->CreateOutputMix(self, pMix, numInterfaces, pInterfaces, pInterfaceRequired); }

inline SLresult SLEnvironmentalReverbItf_SetEnvironmentalReverbProperties (SLEnvironmentalReverbItf self, const SLEnvironmentalReverbSettings *pProperties)
  { return (*self)->SetEnvironmentalReverbProperties(self, pProperties); }

inline SLresult SLMuteSoloItf_SetChannelMute (SLMuteSoloItf self, SLuint8 chan, SLboolean enable)
  { return (*self)->SetChannelMute(self, chan, enable); }
inline SLresult SLMuteSoloItf_GetChannelMute (SLMuteSoloItf self, SLuint8 chan, SLboolean *pEnable)
  { return (*self)->GetChannelMute(self, chan, pEnable); }
inline SLresult SLMuteSoloItf_SetChannelSolo (SLMuteSoloItf self, SLuint8 chan, SLboolean solo)
  { return (*self)->SetChannelSolo(self, chan, solo); }
inline SLresult SLMuteSoloItf_GetChannelSolo (SLMuteSoloItf self, SLuint8 chan, SLboolean *pSolo)
  { return (*self)->GetChannelSolo(self, chan, pSolo); }
inline SLresult SLMuteSoloItf_GetNumChannels (SLMuteSoloItf self, SLuint8 *pNumChannels)
  { return (*self)->GetNumChannels(self, pNumChannels); }

inline SLresult SLObjectItf_Realize (SLObjectItf self, SLboolean async)
  { return (*self)->Realize(self, async); }
inline SLresult SLObjectItf_Resume (SLObjectItf self, SLboolean async)
  { return (*self)->Resume(self, async); }
inline SLresult SLObjectItf_GetState (SLObjectItf self, SLuint32 *pState)
  { return (*self)->GetState(self, pState); }
inline SLresult SLObjectItf_GetInterface (SLObjectItf self, const SLInterfaceID iid, void *pInterface)
  { return (*self)->GetInterface(self, iid, pInterface); }
extern SLresult SLObjectItf_RegisterCallback (SLObjectItf self, void *callback, void *pContext);
inline void SLObjectItf_AbortAsyncOperation (SLObjectItf self)
  { (*self)->AbortAsyncOperation(self); }
inline void SLObjectItf_Destroy (SLObjectItf self)
  { (*self)->Destroy(self); }
inline SLresult SLObjectItf_SetPriority (SLObjectItf self, SLint32 priority, SLboolean preemptable)
  { return (*self)->SetPriority(self, priority, preemptable); }
inline SLresult SLObjectItf_GetPriority (SLObjectItf self, SLint32 *pPriority, SLboolean *pPreemptable)
  { return (*self)->GetPriority(self, pPriority, pPreemptable); }
inline SLresult SLObjectItf_SetLossOfControlInterfaces (SLObjectItf self, SLint16 numInterface, SLInterfaceID *pInterfaces, SLboolean enabled)
  { return (*self)->SetLossOfControlInterfaces(self, numInterface, pInterfaces, enabled); }

inline SLresult SLPlayItf_SetPlayState (SLPlayItf self, SLuint32 state)
  { return (*self)->SetPlayState(self, state); }
inline SLresult SLPlayItf_GetPlayState (SLPlayItf self, SLuint32 *pState)
  { return (*self)->GetPlayState(self, pState); }
inline SLresult SLPlayItf_GetDuration (SLPlayItf self, SLmillisecond *pMsec)
  { return (*self)->GetDuration(self, pMsec); }
inline SLresult SLPlayItf_GetPosition (SLPlayItf self, SLmillisecond *pMsec)
  { return (*self)->GetPosition(self, pMsec); }
extern SLresult SLPlayItf_RegisterCallback (SLPlayItf self, void *callback, void *pContext);
inline SLresult SLPlayItf_SetCallbackEventsMask (SLPlayItf self, SLuint32 eventFlags)
  { return (*self)->SetCallbackEventsMask(self, eventFlags); }
inline SLresult SLPlayItf_GetCallbackEventsMask (SLPlayItf self, SLuint32 *pEventFlags)
  { return (*self)->GetCallbackEventsMask(self, pEventFlags); }
inline SLresult SLPlayItf_SetMarkerPosition (SLPlayItf self, SLmillisecond mSec)
  { return (*self)->SetMarkerPosition(self, mSec); }
inline SLresult SLPlayItf_ClearMarkerPosition (SLPlayItf self)
  { return (*self)->ClearMarkerPosition(self); }
inline SLresult SLPlayItf_GetMarkerPosition (SLPlayItf self, SLmillisecond *pMsec)
  { return (*self)->GetMarkerPosition(self, pMsec); }
inline SLresult SLPlayItf_SetPositionUpdatePeriod (SLPlayItf self, SLmillisecond mSec)
  { return (*self)->SetPositionUpdatePeriod(self, mSec); }
inline SLresult SLPlayItf_GetPositionUpdatePeriod (SLPlayItf self, SLmillisecond *pMsec)
  { return (*self)->GetPositionUpdatePeriod(self, pMsec); }

inline SLresult SLPlaybackRateItf_SetRate (SLPlaybackRateItf self, SLpermille rate)
  { return (*self)->SetRate(self, rate); }
inline SLresult SLPlaybackRateItf_GetRate (SLPlaybackRateItf self, SLpermille *pRate)
  { return (*self)->GetRate(self, pRate); }
inline SLresult SLPlaybackRateItf_SetPropertyConstraints (SLPlaybackRateItf self, SLuint32 constraints)
  { return (*self)->SetPropertyConstraints(self, constraints); }
inline SLresult SLPlaybackRateItf_GetProperties (SLPlaybackRateItf self, SLuint32 * pProperties)
  { return (*self)->GetProperties(self, pProperties); }
inline SLresult SLPlaybackRateItf_GetCapabilitiesOfRate (SLPlaybackRateItf self, SLpermille rate, SLuint32 *pCapabilities)
  { return (*self)->GetCapabilitiesOfRate(self, rate, pCapabilities); }
inline SLresult SLPlaybackRateItf_GetRateRange (SLPlaybackRateItf self, SLuint8 index, SLpermille *pMinRate, SLpermille *pMaxRate,
                                                SLpermille *pStepSize, SLuint32 *pCapabilities)
  { return (*self)->GetRateRange(self, index, pMinRate, pMaxRate, pStepSize, pCapabilities); }

inline SLresult SLSeekItf_SetPosition (SLSeekItf self, SLmillisecond pos, SLuint32 seekMode)
  { return (*self)->SetPosition(self, pos, seekMode); }
inline SLresult SLSeekItf_SetLoop (SLSeekItf self, SLboolean enable, SLmillisecond startPos, SLmillisecond endPos)
  { return (*self)->SetLoop(self, enable, startPos, endPos); }
inline SLresult SLSeekItf_GetLoop (SLSeekItf self, SLboolean *pEnable, SLmillisecond *pStartPos, SLmillisecond *pEndPos)
  { return (*self)->GetLoop(self, pEnable, pStartPos, pEndPos); }

inline SLresult SLVolumeItf_SetVolumeLevel (SLVolumeItf self, SLmillibel level)
  { return (*self)->SetVolumeLevel(self, level); }
inline SLresult SLVolumeItf_GetVolumeLevel (SLVolumeItf self, SLmillibel *pLevel)
  { return (*self)->GetVolumeLevel(self, pLevel); }
inline SLresult SLVolumeItf_GetMaxVolumeLevel (SLVolumeItf self, SLmillibel *pMaxLevel)
  { return (*self)->GetMaxVolumeLevel(self, pMaxLevel); }
inline SLresult SLVolumeItf_SetMute (SLVolumeItf self, SLboolean mute)
  { return (*self)->SetMute(self, mute); }
inline SLresult SLVolumeItf_GetMute (SLVolumeItf self, SLboolean *pMute)
  { return (*self)->GetMute(self, pMute); }
inline SLresult SLVolumeItf_EnableStereoPosition (SLVolumeItf self, SLboolean enable)
  { return (*self)->EnableStereoPosition(self, enable); }
inline SLresult SLVolumeItf_IsEnabledStereoPosition (SLVolumeItf self, SLboolean *pEnable)
  { return (*self)->IsEnabledStereoPosition(self, pEnable); }
inline SLresult SLVolumeItf_SetStereoPosition (SLVolumeItf self, SLpermille stereoPosition)
  { return (*self)->SetStereoPosition(self, stereoPosition); }
inline SLresult SLVolumeItf_GetStereoPosition (SLVolumeItf self, SLpermille *pStereoPosition)
  { return (*self)->GetStereoPosition(self, pStereoPosition); }

#ifdef __cplusplus
}
#endif
