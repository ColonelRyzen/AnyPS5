#include "prx/libSceAgcVsh/include/Api.hpp"
#include "prx/libc/include/general/VabiMacros.hpp"
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>

namespace {

using ThrowingStub = int (*)();

constexpr ThrowingStub kStubs[] = {
    sceAgcGetRegisterDefaultsInternal_0090,
    sceAgcGetRegisterDefaults_0090,
};

constexpr const char* kNames[] = {
    "sceAgcGetRegisterDefaultsInternal_0090",
    "sceAgcGetRegisterDefaults_0090",
};

}

int main() {
    static_assert(sizeof(kStubs) / sizeof(kStubs[0]) == 2, "catalog declaration count changed");
    static_assert(sizeof(kNames) / sizeof(kNames[0]) == sizeof(kStubs) / sizeof(kStubs[0]), "name table size differs from stub table");
    for (std::size_t i = 0; i < sizeof(kStubs) / sizeof(kStubs[0]); ++i) {
        try {
            kStubs[i]();
        } catch (const std::runtime_error&) {
            continue;
        }
        std::fprintf(stderr, "libSceAgcVsh catalog stub did not throw: %s\n", kNames[i]);
        std::abort();
    }
    return 0;
}
