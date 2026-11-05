#include "prx/libSceEsvmPlayReady/include/Api.hpp"
#include "prx/libSceEsvmDecodeModeEx/include/Api.hpp"
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
    RequireThrows(sceEsvmProcessAckResponse, "sceEsvmProcessAckResponse");
    RequireThrows(sceEsvmUseCustomMusicCoreForDecoderMode, "sceEsvmUseCustomMusicCoreForDecoderMode");
    return failures == 0 ? 0 : 1;
}
