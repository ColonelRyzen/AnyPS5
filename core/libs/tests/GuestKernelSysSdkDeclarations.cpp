#include "prx/libc/include/general/VabiMacros.hpp"
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <source_location>
#include <stdexcept>

namespace {
struct KernelProcStats;
struct PthreadMutexPrivate;
using PthreadMutex = PthreadMutexPrivate*;
}

extern "C" {
int APS5_VABI sceKernelGetCpuUsage(KernelProcStats* out, int* size);
void APS5_VABI sceKernelGetIdPs(void* idPs);
int APS5_VABI sceKernelGetThreadName(std::uint32_t threadId, char* name);
int APS5_VABI sceKernelIccSetBuzzer(int mode);
int APS5_VABI sceKernelLwfsAllocateBlock(int fd, std::int64_t size);
int APS5_VABI sceKernelLwfsLseek(int fd, std::int64_t offset, int whence);
int APS5_VABI sceKernelLwfsSetAttribute(int fd, int attribute);
int APS5_VABI sceKernelLwfsWrite(int fd, const void* buffer, std::size_t length);
int APS5_VABI sceKernelSetCompressionAttribute(int fd, int attribute);
int APS5_VABI sceKernelSetFsstParam(int fd, void* param);
int APS5_VABI scePthreadMutexGetprioceiling(PthreadMutex* mutex, int* prioceiling);
int APS5_VABI scePthreadMutexSetprioceiling(PthreadMutex* mutex, int prioceiling, int* previous);
}

namespace {

void Require(bool condition, std::source_location location = std::source_location::current()) {
    if (condition) return;
    std::fprintf(stderr, "libkernel_sys declaration check failed at line %u\n", location.line());
    std::abort();
}

template <typename TFunction>
void RequireThrows(TFunction function, std::source_location location = std::source_location::current()) {
    try {
        function();
    } catch (const std::runtime_error&) {
        return;
    }
    std::fprintf(stderr, "libkernel_sys declaration did not throw at line %u\n", location.line());
    std::abort();
}

}

int main() {
    alignas(16) unsigned char storage[64] {};
    int value = 0;
    auto* stats = reinterpret_cast<KernelProcStats*>(storage);
    auto* mutex = reinterpret_cast<PthreadMutex*>(storage);

    RequireThrows([&] { return sceKernelGetCpuUsage(stats, &value); });
    RequireThrows([&] { return sceKernelGetCpuUsage(nullptr, nullptr); });
    RequireThrows([&] { return sceKernelGetIdPs(static_cast<void*>(storage)); });
    RequireThrows([&] { return sceKernelGetIdPs(nullptr); });
    RequireThrows([&] { return sceKernelGetThreadName(0, reinterpret_cast<char*>(storage)); });
    RequireThrows([&] { return sceKernelGetThreadName(1, nullptr); });
    RequireThrows([&] { return sceKernelIccSetBuzzer(0); });
    RequireThrows([&] { return sceKernelIccSetBuzzer(1); });
    RequireThrows([&] { return sceKernelLwfsAllocateBlock(3, 4096); });
    RequireThrows([&] { return sceKernelLwfsAllocateBlock(-1, 0); });
    RequireThrows([&] { return sceKernelLwfsLseek(3, 0, 0); });
    RequireThrows([&] { return sceKernelLwfsLseek(0, -1, 2); });
    RequireThrows([&] { return sceKernelLwfsSetAttribute(3, 1); });
    RequireThrows([&] { return sceKernelLwfsWrite(3, storage, sizeof(storage)); });
    RequireThrows([&] { return sceKernelLwfsWrite(0, nullptr, 0); });
    RequireThrows([&] { return sceKernelSetCompressionAttribute(3, 0); });
    RequireThrows([&] { return sceKernelSetFsstParam(3, static_cast<void*>(storage)); });
    RequireThrows([&] { return sceKernelSetFsstParam(0, nullptr); });
    RequireThrows([&] { return scePthreadMutexGetprioceiling(mutex, &value); });
    RequireThrows([&] { return scePthreadMutexGetprioceiling(nullptr, nullptr); });
    RequireThrows([&] { return scePthreadMutexSetprioceiling(mutex, 0, &value); });
    RequireThrows([&] { return scePthreadMutexSetprioceiling(nullptr, 3, nullptr); });
    return 0;
}
