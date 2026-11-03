#include "prx/libc/include/general/VabiMacros.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <source_location>
#include <stdexcept>

struct PthreadMutex;

extern "C" {
int APS5_VABI scePthreadMutexGetprioceiling(PthreadMutex*, std::int32_t*);
int APS5_VABI scePthreadMutexSetprioceiling(PthreadMutex*, std::int32_t, std::int32_t*);
}

namespace {

void RequireThrows(auto function, std::source_location location = std::source_location::current()) {
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
    alignas(8) unsigned char storage[16] {};
    std::int32_t value = 0;
    RequireThrows([&] { return scePthreadMutexGetprioceiling(reinterpret_cast<PthreadMutex*>(storage), &value); });
    RequireThrows([] { return scePthreadMutexGetprioceiling(nullptr, nullptr); });
    RequireThrows([&] { return scePthreadMutexSetprioceiling(reinterpret_cast<PthreadMutex*>(storage), 0, &value); });
    RequireThrows([] { return scePthreadMutexSetprioceiling(nullptr, 0, nullptr); });
    return 0;
}