#include "prx/libc/include/general/VabiMacros.hpp"
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

extern "C" {
int APS5_VABI sceMediaFwAddEsvmDecoder2_nid_no_patch(void);
int APS5_VABI sceMediaFwAudioSyncFlush_nid_no_patch(void);
int APS5_VABI sceMediaFwChangeVideoOutputMode_nid_no_patch(void);
int APS5_VABI sceMediaFwChangeVideoOutputMode2_nid_no_patch(void);
int APS5_VABI sceMediaFwInitializeCdm_nid_no_patch(void);
int APS5_VABI sceMediaFwMediaKeySystemAccessCreateMediaKeys2_nid_no_patch(void);
int APS5_VABI sceMediaFwMediaKeysSetServerCertificate2_nid_no_patch(void);
int APS5_VABI sceMediaFwRegisterSrcAllocateStateChangeCallback_nid_no_patch(void);
int APS5_VABI sceMediaFwReleaseVideoFrame_nid_no_patch(void);
int APS5_VABI sceMediaFwRequestMediaKeySystemAccess2_nid_no_patch(void);
int APS5_VABI sceMediaFwSetAudioTagFeature_nid_no_patch(void);
int APS5_VABI sceMediaFwSetUniversalEsvm_nid_no_patch(void);
int APS5_VABI sceMediaFwSourceBufferCanSwitchToType_nid_no_patch(void);
int APS5_VABI sceMediaFwSyncVideo_nid_no_patch(void);
}

namespace {

using ThrowingStub = int (*)(void);

const ThrowingStub kStubs[] = {
    sceMediaFwAddEsvmDecoder2_nid_no_patch,
    sceMediaFwAudioSyncFlush_nid_no_patch,
    sceMediaFwChangeVideoOutputMode_nid_no_patch,
    sceMediaFwChangeVideoOutputMode2_nid_no_patch,
    sceMediaFwInitializeCdm_nid_no_patch,
    sceMediaFwMediaKeySystemAccessCreateMediaKeys2_nid_no_patch,
    sceMediaFwMediaKeysSetServerCertificate2_nid_no_patch,
    sceMediaFwRegisterSrcAllocateStateChangeCallback_nid_no_patch,
    sceMediaFwReleaseVideoFrame_nid_no_patch,
    sceMediaFwRequestMediaKeySystemAccess2_nid_no_patch,
    sceMediaFwSetAudioTagFeature_nid_no_patch,
    sceMediaFwSetUniversalEsvm_nid_no_patch,
    sceMediaFwSourceBufferCanSwitchToType_nid_no_patch,
    sceMediaFwSyncVideo_nid_no_patch,
};

const char* kStubNames[] = {
    "sceMediaFwAddEsvmDecoder2",
    "sceMediaFwAudioSyncFlush",
    "sceMediaFwChangeVideoOutputMode",
    "sceMediaFwChangeVideoOutputMode2",
    "sceMediaFwInitializeCdm",
    "sceMediaFwMediaKeySystemAccessCreateMediaKeys2",
    "sceMediaFwMediaKeysSetServerCertificate2",
    "sceMediaFwRegisterSrcAllocateStateChangeCallback",
    "sceMediaFwReleaseVideoFrame",
    "sceMediaFwRequestMediaKeySystemAccess2",
    "sceMediaFwSetAudioTagFeature",
    "sceMediaFwSetUniversalEsvm",
    "sceMediaFwSourceBufferCanSwitchToType",
    "sceMediaFwSyncVideo"
};

void RequireThrowsStub(ThrowingStub stub, const char* name, unsigned line) {
    try {
        stub();
    } catch (const std::runtime_error&) {
        return;
    }
    std::fprintf(stderr, "libSceMediaFrameworkInterface stub did not throw: %s (line %u)\n", name, line);
    std::abort();
}

}

int main() {
    static_assert(sizeof(kStubs) / sizeof(kStubs[0]) == 14, "catalog declaration count changed");
    for (unsigned i = 0; i < sizeof(kStubs) / sizeof(kStubs[0]); ++i) {
        RequireThrowsStub(kStubs[i], kStubNames[i], __LINE__);
    }
    return 0;
}
