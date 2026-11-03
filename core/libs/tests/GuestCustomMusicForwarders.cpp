#include "prx/libc/include/general/VabiMacros.hpp"
#include "SceTypes.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <source_location>
#include <stdexcept>

extern "C" {
int APS5_VABI sceCustomMusicAudiodecClearContext(int32_t handle);
int APS5_VABI sceCustomMusicFileOpenRead(const char* path, int flags, std::uint16_t mode);
int APS5_VABI sceCustomMusicKernelGettimeofday(KernelTimeval* tp);
int APS5_VABI sceCustomMusicNetPoolCreate(const char* name, int size, int flags);
int APS5_VABI sceCustomMusicPthreadMutexLock(PthreadMutex* mutex);
}

namespace {

void RequireThrows(auto function, std::source_location location = std::source_location::current()) {
    try {
        function();
    } catch (const std::runtime_error&) {
        return;
    }
    std::fprintf(stderr, "libSceCustomMusicSysCallWrapper did not throw at line %u\n", location.line());
    std::abort();
}

}

int main() {
    KernelTimeval tv {};
    PthreadMutex mutex {};
    RequireThrows([] { return sceCustomMusicAudiodecClearContext(1); });
    RequireThrows([] { return sceCustomMusicAudiodecClearContext(0); });
    RequireThrows([] { return sceCustomMusicFileOpenRead("/custom_music/song.bin", 0, 0); });
    RequireThrows([] { return sceCustomMusicFileOpenRead(nullptr, 0, 0); });
    RequireThrows([&] { return sceCustomMusicKernelGettimeofday(&tv); });
    RequireThrows([] { return sceCustomMusicKernelGettimeofday(nullptr); });
    RequireThrows([] { return sceCustomMusicNetPoolCreate("pool", 4096, 0); });
    RequireThrows([] { return sceCustomMusicNetPoolCreate(nullptr, 0, 0); });
    RequireThrows([&] { return sceCustomMusicPthreadMutexLock(&mutex); });
    RequireThrows([] { return sceCustomMusicPthreadMutexLock(nullptr); });
    return 0;
}
