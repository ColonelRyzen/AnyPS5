#include "prx/libSceVrHand_nosubmission/libSceVrHand_nosubmission.hpp"
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
    RequireThrows(sceVrHandDebugGetConfig, "sceVrHandDebugGetConfig");
    RequireThrows(sceVrHandDebugGetInternalResult, "sceVrHandDebugGetInternalResult");
    RequireThrows(sceVrHandDebugSetConfig, "sceVrHandDebugSetConfig");
    RequireThrows(sceVrHandSetDebugInterface, "sceVrHandSetDebugInterface");
    return failures == 0 ? 0 : 1;
}
