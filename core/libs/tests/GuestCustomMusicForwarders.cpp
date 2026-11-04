#include "prx/libc/include/general/VabiMacros.hpp"
#include "SceTypes.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

extern "C" {
int APS5_VABI sceCustomMusicAudiodecClearContext(int32_t handle);
int APS5_VABI sceCustomMusicFileOpenRead(const char* path, int flags, std::uint16_t mode);
int APS5_VABI sceCustomMusicKernelGettimeofday(KernelTimeval* tp);
int APS5_VABI sceCustomMusicNetPoolCreate(const char* name, int size, int flags);
int APS5_VABI sceCustomMusicPthreadMutexLock(PthreadMutex* mutex);
Pthread APS5_VABI sceCustomMusicPthreadSelf();
void APS5_VABI sceCustomMusicPthreadYield();
int APS5_VABI sceCustomMusicNetCtlInit();
void APS5_VABI sceCustomMusicNetCtlTerm();

int32_t APS5_VABI sceAudiodecClearContext(int32_t handle);
int APS5_VABI sceKernelOpen(const char* path, int flags, std::uint16_t mode);
int APS5_VABI sceKernelGettimeofday(KernelTimeval* tp);
int APS5_VABI sceNetPoolCreate(const char* name, int size, int flags);
int APS5_VABI scePthreadMutexLock(PthreadMutex* mutex);
Pthread APS5_VABI scePthreadSelf();
void APS5_VABI scePthreadYield();
int APS5_VABI sceNetCtlInit(void);
void APS5_VABI sceNetCtlTerm(void);
}

namespace {

void Require(bool value, unsigned line) {
    if (!value) {
        std::fprintf(stderr, "libSceCustomMusicSysCallWrapper mismatch at line %u\n", line);
        std::abort();
    }
}

void RequireEqual(auto wrapper, auto callee, unsigned line) {
    Require(wrapper == callee, line);
}

}

#define RequireEq(a, b) RequireEqual(a, b, __LINE__)

int main() {
    KernelTimeval wrapper_tv {};
    KernelTimeval callee_tv {};
    RequireEq(sceCustomMusicAudiodecClearContext(1), sceAudiodecClearContext(1));
    RequireEq(sceCustomMusicAudiodecClearContext(0), sceAudiodecClearContext(0));
    RequireEq(sceCustomMusicFileOpenRead("/custom_music_forwarder_missing_file", 0, 0),
              sceKernelOpen("/custom_music_forwarder_missing_file", 0, 0));
    RequireEq(sceCustomMusicFileOpenRead(nullptr, 0, 0), sceKernelOpen(nullptr, 0, 0));
    Require(sceCustomMusicKernelGettimeofday(&wrapper_tv) == sceKernelGettimeofday(&callee_tv), __LINE__);
    RequireEq(sceCustomMusicKernelGettimeofday(nullptr), sceKernelGettimeofday(nullptr));
    const int pool_a = sceCustomMusicNetPoolCreate("anyps5-music-pool", 0, 0);
    const int pool_b = sceNetPoolCreate("anyps5-music-pool", 0, 0);
    Require((pool_a < 0) == (pool_b < 0) && (pool_a < 0 ? pool_a == pool_b : true), __LINE__);
    {
        bool wrapper_threw = false;
        bool callee_threw = false;
        try { sceCustomMusicPthreadMutexLock(nullptr); } catch (const std::invalid_argument&) { wrapper_threw = true; }
        try { scePthreadMutexLock(nullptr); } catch (const std::invalid_argument&) { callee_threw = true; }
        Require(wrapper_threw && callee_threw, __LINE__);
    }
    {
        Pthread wrapper_self = sceCustomMusicPthreadSelf();
        Pthread callee_self = scePthreadSelf();
        Require(wrapper_self != nullptr && callee_self != nullptr && wrapper_self == callee_self, __LINE__);
    }
    sceCustomMusicPthreadYield();
    scePthreadYield();
    Require(sceCustomMusicNetCtlInit() == sceNetCtlInit(), __LINE__);
    sceCustomMusicNetCtlTerm();
    Require(sceCustomMusicNetCtlInit() == 0, __LINE__);
    return 0;
}
