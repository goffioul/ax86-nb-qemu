#define LOG_TAG "libnb-qemu"
#define LOG_NDEBUG 0

#include <stdint.h>
#include <log/log.h>
#include "QemuInclude.h"
#include "libOpenSLES.itf.h"

void nb_handle_slCreateEngine(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)slCreateEngine(
        *(void**)(&sp[0]),
        *(int*)(&sp[4]),
        *(void**)(&sp[8]),
        *(int*)(&sp[12]),
        *(void**)(&sp[16]),
        *(void**)(&sp[20])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLBufferQueueItf_Enqueue(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLBufferQueueItf_Enqueue(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(uint32_t*)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLBufferQueueItf_Clear(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLBufferQueueItf_Clear(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLBufferQueueItf_RegisterCallback(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLBufferQueueItf_RegisterCallback(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLEffectSendItf_EnableEffectSend(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLEffectSendItf_EnableEffectSend(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(uint32_t*)(&sp[8]),
        *(int16_t*)(&sp[12])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLEngineItf_CreateAudioPlayer(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLEngineItf_CreateAudioPlayer(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12]),
        *(uint32_t*)(&sp[16]),
        *(void**)(&sp[20]),
        *(void**)(&sp[24])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLEngineItf_CreateOutputMix(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLEngineItf_CreateOutputMix(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(uint32_t*)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLEnvironmentalReverbItf_SetEnvironmentalReverbProperties(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLEnvironmentalReverbItf_SetEnvironmentalReverbProperties(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLMuteSoloItf_SetChannelMute(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLMuteSoloItf_SetChannelMute(
        *(void**)(&sp[0]),
        *(uint8_t*)(&sp[4]),
        *(uint32_t*)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLMuteSoloItf_GetChannelMute(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLMuteSoloItf_GetChannelMute(
        *(void**)(&sp[0]),
        *(uint8_t*)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLMuteSoloItf_SetChannelSolo(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLMuteSoloItf_SetChannelSolo(
        *(void**)(&sp[0]),
        *(uint8_t*)(&sp[4]),
        *(uint32_t*)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLMuteSoloItf_GetChannelSolo(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLMuteSoloItf_GetChannelSolo(
        *(void**)(&sp[0]),
        *(uint8_t*)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLMuteSoloItf_GetNumChannels(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLMuteSoloItf_GetNumChannels(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLObjectItf_Realize(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLObjectItf_Realize(
        *(void**)(&sp[0]),
        *(uint32_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLObjectItf_Resume(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLObjectItf_Resume(
        *(void**)(&sp[0]),
        *(uint32_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLObjectItf_GetState(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLObjectItf_GetState(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLObjectItf_GetInterface(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLObjectItf_GetInterface(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLObjectItf_RegisterCallback(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLObjectItf_RegisterCallback(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLObjectItf_AbortAsyncOperation(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    SLObjectItf_AbortAsyncOperation(
        *(void**)(&sp[0])
    );
}
void nb_handle_SLObjectItf_Destroy(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    SLObjectItf_Destroy(
        *(void**)(&sp[0])
    );
}
void nb_handle_SLObjectItf_SetPriority(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLObjectItf_SetPriority(
        *(void**)(&sp[0]),
        *(int32_t*)(&sp[4]),
        *(uint32_t*)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLObjectItf_GetPriority(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLObjectItf_GetPriority(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLObjectItf_SetLossOfControlInterfaces(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLObjectItf_SetLossOfControlInterfaces(
        *(void**)(&sp[0]),
        *(int16_t*)(&sp[4]),
        *(void**)(&sp[8]),
        *(uint32_t*)(&sp[12])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlayItf_SetPlayState(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlayItf_SetPlayState(
        *(void**)(&sp[0]),
        *(uint32_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlayItf_GetPlayState(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlayItf_GetPlayState(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlayItf_GetDuration(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlayItf_GetDuration(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlayItf_GetPosition(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlayItf_GetPosition(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlayItf_RegisterCallback(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlayItf_RegisterCallback(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlayItf_SetCallbackEventsMask(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlayItf_SetCallbackEventsMask(
        *(void**)(&sp[0]),
        *(uint32_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlayItf_GetCallbackEventsMask(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlayItf_GetCallbackEventsMask(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlayItf_SetMarkerPosition(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlayItf_SetMarkerPosition(
        *(void**)(&sp[0]),
        *(uint32_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlayItf_ClearMarkerPosition(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlayItf_ClearMarkerPosition(
        *(void**)(&sp[0])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlayItf_GetMarkerPosition(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlayItf_GetMarkerPosition(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlayItf_SetPositionUpdatePeriod(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlayItf_SetPositionUpdatePeriod(
        *(void**)(&sp[0]),
        *(uint32_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlayItf_GetPositionUpdatePeriod(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlayItf_GetPositionUpdatePeriod(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlaybackRateItf_SetRate(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlaybackRateItf_SetRate(
        *(void**)(&sp[0]),
        *(int16_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlaybackRateItf_GetRate(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlaybackRateItf_GetRate(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlaybackRateItf_SetPropertyConstraints(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlaybackRateItf_SetPropertyConstraints(
        *(void**)(&sp[0]),
        *(uint32_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlaybackRateItf_GetProperties(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlaybackRateItf_GetProperties(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlaybackRateItf_GetCapabilitiesOfRate(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlaybackRateItf_GetCapabilitiesOfRate(
        *(void**)(&sp[0]),
        *(int16_t*)(&sp[4]),
        *(void**)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLPlaybackRateItf_GetRateRange(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLPlaybackRateItf_GetRateRange(
        *(void**)(&sp[0]),
        *(uint8_t*)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12]),
        *(void**)(&sp[16]),
        *(void**)(&sp[20])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLSeekItf_SetPosition(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLSeekItf_SetPosition(
        *(void**)(&sp[0]),
        *(uint32_t*)(&sp[4]),
        *(uint32_t*)(&sp[8])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLSeekItf_SetLoop(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLSeekItf_SetLoop(
        *(void**)(&sp[0]),
        *(uint32_t*)(&sp[4]),
        *(uint32_t*)(&sp[8]),
        *(uint32_t*)(&sp[12])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLSeekItf_GetLoop(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLSeekItf_GetLoop(
        *(void**)(&sp[0]),
        *(void**)(&sp[4]),
        *(void**)(&sp[8]),
        *(void**)(&sp[12])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLVolumeItf_SetVolumeLevel(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLVolumeItf_SetVolumeLevel(
        *(void**)(&sp[0]),
        *(int16_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLVolumeItf_GetVolumeLevel(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLVolumeItf_GetVolumeLevel(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLVolumeItf_GetMaxVolumeLevel(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLVolumeItf_GetMaxVolumeLevel(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLVolumeItf_SetMute(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLVolumeItf_SetMute(
        *(void**)(&sp[0]),
        *(uint32_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLVolumeItf_GetMute(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLVolumeItf_GetMute(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLVolumeItf_EnableStereoPosition(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLVolumeItf_EnableStereoPosition(
        *(void**)(&sp[0]),
        *(uint32_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLVolumeItf_IsEnabledStereoPosition(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLVolumeItf_IsEnabledStereoPosition(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLVolumeItf_SetStereoPosition(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLVolumeItf_SetStereoPosition(
        *(void**)(&sp[0]),
        *(int16_t*)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
void nb_handle_SLVolumeItf_GetStereoPosition(CPUARMState *env) {
    char *sp = g2h(env->regs[13]);
    uint32_t __nb_ret = (uint32_t)SLVolumeItf_GetStereoPosition(
        *(void**)(&sp[0]),
        *(void**)(&sp[4])
    );
    env->regs[0] = *(abi_ulong*)(&__nb_ret);
}
__attribute__((visibility("default")))
void nb_handle_svc(CPUARMState *env, int svc) {
    switch (svc) {
        case 0x0600: ALOGV("slCreateEngine"); nb_handle_slCreateEngine(env); break;
        case 0x0601: ALOGV("SLBufferQueueItf_Enqueue"); nb_handle_SLBufferQueueItf_Enqueue(env); break;
        case 0x0602: ALOGV("SLBufferQueueItf_Clear"); nb_handle_SLBufferQueueItf_Clear(env); break;
        case 0x0603: ALOGV("SLBufferQueueItf_RegisterCallback"); nb_handle_SLBufferQueueItf_RegisterCallback(env); break;
        case 0x0604: ALOGV("SLEffectSendItf_EnableEffectSend"); nb_handle_SLEffectSendItf_EnableEffectSend(env); break;
        case 0x0605: ALOGV("SLEngineItf_CreateAudioPlayer"); nb_handle_SLEngineItf_CreateAudioPlayer(env); break;
        case 0x0606: ALOGV("SLEngineItf_CreateOutputMix"); nb_handle_SLEngineItf_CreateOutputMix(env); break;
        case 0x0607: ALOGV("SLEnvironmentalReverbItf_SetEnvironmentalReverbProperties"); nb_handle_SLEnvironmentalReverbItf_SetEnvironmentalReverbProperties(env); break;
        case 0x0608: ALOGV("SLMuteSoloItf_SetChannelMute"); nb_handle_SLMuteSoloItf_SetChannelMute(env); break;
        case 0x0609: ALOGV("SLMuteSoloItf_GetChannelMute"); nb_handle_SLMuteSoloItf_GetChannelMute(env); break;
        case 0x060a: ALOGV("SLMuteSoloItf_SetChannelSolo"); nb_handle_SLMuteSoloItf_SetChannelSolo(env); break;
        case 0x060b: ALOGV("SLMuteSoloItf_GetChannelSolo"); nb_handle_SLMuteSoloItf_GetChannelSolo(env); break;
        case 0x060c: ALOGV("SLMuteSoloItf_GetNumChannels"); nb_handle_SLMuteSoloItf_GetNumChannels(env); break;
        case 0x060d: ALOGV("SLObjectItf_Realize"); nb_handle_SLObjectItf_Realize(env); break;
        case 0x060e: ALOGV("SLObjectItf_Resume"); nb_handle_SLObjectItf_Resume(env); break;
        case 0x060f: ALOGV("SLObjectItf_GetState"); nb_handle_SLObjectItf_GetState(env); break;
        case 0x0610: ALOGV("SLObjectItf_GetInterface"); nb_handle_SLObjectItf_GetInterface(env); break;
        case 0x0611: ALOGV("SLObjectItf_RegisterCallback"); nb_handle_SLObjectItf_RegisterCallback(env); break;
        case 0x0612: ALOGV("SLObjectItf_AbortAsyncOperation"); nb_handle_SLObjectItf_AbortAsyncOperation(env); break;
        case 0x0613: ALOGV("SLObjectItf_Destroy"); nb_handle_SLObjectItf_Destroy(env); break;
        case 0x0614: ALOGV("SLObjectItf_SetPriority"); nb_handle_SLObjectItf_SetPriority(env); break;
        case 0x0615: ALOGV("SLObjectItf_GetPriority"); nb_handle_SLObjectItf_GetPriority(env); break;
        case 0x0616: ALOGV("SLObjectItf_SetLossOfControlInterfaces"); nb_handle_SLObjectItf_SetLossOfControlInterfaces(env); break;
        case 0x0617: ALOGV("SLPlayItf_SetPlayState"); nb_handle_SLPlayItf_SetPlayState(env); break;
        case 0x0618: ALOGV("SLPlayItf_GetPlayState"); nb_handle_SLPlayItf_GetPlayState(env); break;
        case 0x0619: ALOGV("SLPlayItf_GetDuration"); nb_handle_SLPlayItf_GetDuration(env); break;
        case 0x061a: ALOGV("SLPlayItf_GetPosition"); nb_handle_SLPlayItf_GetPosition(env); break;
        case 0x061b: ALOGV("SLPlayItf_RegisterCallback"); nb_handle_SLPlayItf_RegisterCallback(env); break;
        case 0x061c: ALOGV("SLPlayItf_SetCallbackEventsMask"); nb_handle_SLPlayItf_SetCallbackEventsMask(env); break;
        case 0x061d: ALOGV("SLPlayItf_GetCallbackEventsMask"); nb_handle_SLPlayItf_GetCallbackEventsMask(env); break;
        case 0x061e: ALOGV("SLPlayItf_SetMarkerPosition"); nb_handle_SLPlayItf_SetMarkerPosition(env); break;
        case 0x061f: ALOGV("SLPlayItf_ClearMarkerPosition"); nb_handle_SLPlayItf_ClearMarkerPosition(env); break;
        case 0x0620: ALOGV("SLPlayItf_GetMarkerPosition"); nb_handle_SLPlayItf_GetMarkerPosition(env); break;
        case 0x0621: ALOGV("SLPlayItf_SetPositionUpdatePeriod"); nb_handle_SLPlayItf_SetPositionUpdatePeriod(env); break;
        case 0x0622: ALOGV("SLPlayItf_GetPositionUpdatePeriod"); nb_handle_SLPlayItf_GetPositionUpdatePeriod(env); break;
        case 0x0623: ALOGV("SLPlaybackRateItf_SetRate"); nb_handle_SLPlaybackRateItf_SetRate(env); break;
        case 0x0624: ALOGV("SLPlaybackRateItf_GetRate"); nb_handle_SLPlaybackRateItf_GetRate(env); break;
        case 0x0625: ALOGV("SLPlaybackRateItf_SetPropertyConstraints"); nb_handle_SLPlaybackRateItf_SetPropertyConstraints(env); break;
        case 0x0626: ALOGV("SLPlaybackRateItf_GetProperties"); nb_handle_SLPlaybackRateItf_GetProperties(env); break;
        case 0x0627: ALOGV("SLPlaybackRateItf_GetCapabilitiesOfRate"); nb_handle_SLPlaybackRateItf_GetCapabilitiesOfRate(env); break;
        case 0x0628: ALOGV("SLPlaybackRateItf_GetRateRange"); nb_handle_SLPlaybackRateItf_GetRateRange(env); break;
        case 0x0629: ALOGV("SLSeekItf_SetPosition"); nb_handle_SLSeekItf_SetPosition(env); break;
        case 0x062a: ALOGV("SLSeekItf_SetLoop"); nb_handle_SLSeekItf_SetLoop(env); break;
        case 0x062b: ALOGV("SLSeekItf_GetLoop"); nb_handle_SLSeekItf_GetLoop(env); break;
        case 0x062c: ALOGV("SLVolumeItf_SetVolumeLevel"); nb_handle_SLVolumeItf_SetVolumeLevel(env); break;
        case 0x062d: ALOGV("SLVolumeItf_GetVolumeLevel"); nb_handle_SLVolumeItf_GetVolumeLevel(env); break;
        case 0x062e: ALOGV("SLVolumeItf_GetMaxVolumeLevel"); nb_handle_SLVolumeItf_GetMaxVolumeLevel(env); break;
        case 0x062f: ALOGV("SLVolumeItf_SetMute"); nb_handle_SLVolumeItf_SetMute(env); break;
        case 0x0630: ALOGV("SLVolumeItf_GetMute"); nb_handle_SLVolumeItf_GetMute(env); break;
        case 0x0631: ALOGV("SLVolumeItf_EnableStereoPosition"); nb_handle_SLVolumeItf_EnableStereoPosition(env); break;
        case 0x0632: ALOGV("SLVolumeItf_IsEnabledStereoPosition"); nb_handle_SLVolumeItf_IsEnabledStereoPosition(env); break;
        case 0x0633: ALOGV("SLVolumeItf_SetStereoPosition"); nb_handle_SLVolumeItf_SetStereoPosition(env); break;
        case 0x0634: ALOGV("SLVolumeItf_GetStereoPosition"); nb_handle_SLVolumeItf_GetStereoPosition(env); break;
        default: LOG_ALWAYS_FATAL("Unknown SVC %08x", svc); break;
    }
}
