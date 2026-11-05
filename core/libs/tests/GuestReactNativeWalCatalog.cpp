#include "prx/libReactNative.Modules.Vsh.WebAppLauncher/libReactNative.Modules.Vsh.WebAppLauncher.hpp"
#include <cstdio>

namespace {

int failures = 0;

template <typename TFn>
void RequireThrows(TFn fn, const char *name) {
    try {
        fn();
    } catch (...) {
        return;
    }
    std::fprintf(stderr, "%s did not throw\n", name);
    ++failures;
}

}

int main() {
    RequireThrows(AdIdDialogOpen, "AdIdDialogOpen");
    RequireThrows(AuthorizedAppDialogOpen, "AuthorizedAppDialogOpen");
    RequireThrows(ConnectAccountDialogInit, "ConnectAccountDialogInit");
    RequireThrows(ConnectAccountDialogOpen, "ConnectAccountDialogOpen");
    RequireThrows(GetAccessibilitySettings, "GetAccessibilitySettings");
    RequireThrows(GetAppSessionId, "GetAppSessionId");
    RequireThrows(GetAuthorizedAppCode, "GetAuthorizedAppCode");
    RequireThrows(GetClosedCaptionAllSettings, "GetClosedCaptionAllSettings");
    RequireThrows(GetMessage, "GetMessage");
    RequireThrows(GetNpEnvironment, "GetNpEnvironment");
    RequireThrows(GetOpenPsIdForSystem, "GetOpenPsIdForSystem");
    RequireThrows(GetUniversalEsvmDebugSetting, "GetUniversalEsvmDebugSetting");
    RequireThrows(IsSupportedAudioOutputMode, "IsSupportedAudioOutputMode");
    RequireThrows(IsSupportedVideoOutputMode, "IsSupportedVideoOutputMode");
    RequireThrows(MusicCoreAbortMessage, "MusicCoreAbortMessage");
    RequireThrows(MusicCoreAddSrc, "MusicCoreAddSrc");
    RequireThrows(MusicCoreGetCapability, "MusicCoreGetCapability");
    RequireThrows(MusicCoreGetCurrentTime, "MusicCoreGetCurrentTime");
    RequireThrows(MusicCoreGetDuration, "MusicCoreGetDuration");
    RequireThrows(MusicCoreGetLoop, "MusicCoreGetLoop");
    RequireThrows(MusicCoreGetMusicInfo, "MusicCoreGetMusicInfo");
    RequireThrows(MusicCoreGetMuted, "MusicCoreGetMuted");
    RequireThrows(MusicCoreGetNetworkState, "MusicCoreGetNetworkState");
    RequireThrows(MusicCoreGetShuffle, "MusicCoreGetShuffle");
    RequireThrows(MusicCoreGetVolume, "MusicCoreGetVolume");
    RequireThrows(MusicCoreInitialize, "MusicCoreInitialize");
    RequireThrows(MusicCoreIsEnded, "MusicCoreIsEnded");
    RequireThrows(MusicCoreIsPaused, "MusicCoreIsPaused");
    RequireThrows(MusicCoreIsPlaying, "MusicCoreIsPlaying");
    RequireThrows(MusicCoreIsSeeking, "MusicCoreIsSeeking");
    RequireThrows(MusicCoreIsStopped, "MusicCoreIsStopped");
    RequireThrows(MusicCoreLoad, "MusicCoreLoad");
    RequireThrows(MusicCorePause, "MusicCorePause");
    RequireThrows(MusicCorePlay, "MusicCorePlay");
    RequireThrows(MusicCoreRegisterCallback, "MusicCoreRegisterCallback");
    RequireThrows(MusicCoreRegisterNotify, "MusicCoreRegisterNotify");
    RequireThrows(MusicCoreRemoveSrc, "MusicCoreRemoveSrc");
    RequireThrows(MusicCoreSendMessageAsync, "MusicCoreSendMessageAsync");
    RequireThrows(MusicCoreSendMessageSync, "MusicCoreSendMessageSync");
    RequireThrows(MusicCoreSetCurrentTime, "MusicCoreSetCurrentTime");
    RequireThrows(MusicCoreSetLoop, "MusicCoreSetLoop");
    RequireThrows(MusicCoreSetMuted, "MusicCoreSetMuted");
    RequireThrows(MusicCoreSetShuffle, "MusicCoreSetShuffle");
    RequireThrows(MusicCoreSetVolume, "MusicCoreSetVolume");
    RequireThrows(MusicCoreSkipNext, "MusicCoreSkipNext");
    RequireThrows(MusicCoreSkipPrevious, "MusicCoreSkipPrevious");
    RequireThrows(MusicCoreStop, "MusicCoreStop");
    RequireThrows(MusicCoreTerminate, "MusicCoreTerminate");
    RequireThrows(MusicCoreUnregisterCallback, "MusicCoreUnregisterCallback");
    RequireThrows(MusicCoreUnregisterNotify, "MusicCoreUnregisterNotify");
    RequireThrows(NpWebGetPushContextId, "NpWebGetPushContextId");
    RequireThrows(NpWebSetAdditionalScope, "NpWebSetAdditionalScope");
    RequireThrows(OpenApp, "OpenApp");
    RequireThrows(OpenVRApp, "OpenVRApp");
    RequireThrows(PartnerModuleInitialize, "PartnerModuleInitialize");
    RequireThrows(PartnerModuleTerminate, "PartnerModuleTerminate");
    RequireThrows(PostMessage, "PostMessage");
    RequireThrows(SaveDataCommit, "SaveDataCommit");
    RequireThrows(SaveDataInitialize, "SaveDataInitialize");
    RequireThrows(SaveDataMount, "SaveDataMount");
    RequireThrows(SaveDataPrepare, "SaveDataPrepare");
    RequireThrows(SaveDataReadFile, "SaveDataReadFile");
    RequireThrows(SaveDataReadFileSize, "SaveDataReadFileSize");
    RequireThrows(SaveDataTerminate, "SaveDataTerminate");
    RequireThrows(SaveDataUnmount, "SaveDataUnmount");
    RequireThrows(SaveDataWriteFile, "SaveDataWriteFile");
    RequireThrows(SendNativeTelemetryCrashEvent, "SendNativeTelemetryCrashEvent");
    RequireThrows(SetAudioTagFeature, "SetAudioTagFeature");
    RequireThrows(SetUniversalEsvm, "SetUniversalEsvm");
    RequireThrows(SetVideoOutputMode, "SetVideoOutputMode");
    RequireThrows(ShareFeaturePermit, "ShareFeaturePermit");
    RequireThrows(ShareFeatureProhibit, "ShareFeatureProhibit");
    RequireThrows(ShareGetCurrentStatus, "ShareGetCurrentStatus");
    RequireThrows(ShareInitialize, "ShareInitialize");
    RequireThrows(ShareTerminate, "ShareTerminate");
    return failures == 0 ? 0 : 1;
}
