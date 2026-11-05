#include "prx/libSceEsvmWidevine/include/Api.hpp"
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
    RequireThrows(sceEsvmCreateMediaKeys2, "sceEsvmCreateMediaKeys2");
    RequireThrows(sceEsvmGetMetrics, "sceEsvmGetMetrics");
    RequireThrows(sceEsvmGetProvisioningRequest, "sceEsvmGetProvisioningRequest");
    RequireThrows(sceEsvmGetServiceCertificateRequest, "sceEsvmGetServiceCertificateRequest");
    RequireThrows(sceEsvmHandleProvisioningResponse, "sceEsvmHandleProvisioningResponse");
    RequireThrows(sceEsvmIsProvisioned, "sceEsvmIsProvisioned");
    RequireThrows(sceEsvmMediaKeysDecryptAudioData, "sceEsvmMediaKeysDecryptAudioData");
    RequireThrows(sceEsvmParseAndLoadServiceCertificateResponse, "sceEsvmParseAndLoadServiceCertificateResponse");
    RequireThrows(sceEsvmSetMediaKeys, "sceEsvmSetMediaKeys");
    RequireThrows(sceEsvmSetServiceCertificate, "sceEsvmSetServiceCertificate");
    return failures == 0 ? 0 : 1;
}
