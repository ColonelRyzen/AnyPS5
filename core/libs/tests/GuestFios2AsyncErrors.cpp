#include "prx/libSceFios2/include/Api.hpp"
#include <cstdint>
#include <cstdio>
#include <cstdlib>

namespace {

void Require(bool condition, int line) {
    if (!condition) {
        std::fprintf(stderr, "guest_fios2_async_errors check failed at line %d\n", line);
        std::abort();
    }
}

#define REQUIRE(condition) Require((condition), __LINE__)

constexpr SceFiosFH kNoHandle = 0x5a5a;

int WaitError(SceFiosOp op) {
    REQUIRE(op != 0);
    return sceFiosOpSyncWait(op);
}

}

int main() {
    const SceFiosOpAttr attr {};
    std::uint8_t storage[16] {};
    SceFiosStat status {};
    bool exists = true;

    REQUIRE(WaitError(sceFiosFHRead(&attr, kNoHandle, storage, sizeof(storage))) == SCE_FIOS_ERROR_BAD_FH);
    REQUIRE(WaitError(sceFiosFHWrite(&attr, kNoHandle, storage, sizeof(storage))) == SCE_FIOS_ERROR_BAD_FH);
    REQUIRE(WaitError(sceFiosFHStat(&attr, kNoHandle, &status)) == SCE_FIOS_ERROR_BAD_FH);
    REQUIRE(WaitError(sceFiosFHSync(&attr, kNoHandle)) == SCE_FIOS_ERROR_BAD_FH);
    REQUIRE(WaitError(sceFiosDHClose(&attr, kNoHandle)) == SCE_FIOS_ERROR_BAD_DH);

    REQUIRE(WaitError(sceFiosFHRead(&attr, kNoHandle, nullptr, 4)) == SCE_FIOS_ERROR_BAD_PTR);
    REQUIRE(WaitError(sceFiosFHWrite(&attr, kNoHandle, storage, -1)) == SCE_FIOS_ERROR_BAD_SIZE);
    REQUIRE(WaitError(sceFiosFHPwrite(&attr, kNoHandle, storage, 4, -1)) == SCE_FIOS_ERROR_BAD_OFFSET);
    REQUIRE(WaitError(sceFiosFHTruncate(&attr, kNoHandle, -1)) == SCE_FIOS_ERROR_BAD_SIZE);
    REQUIRE(WaitError(sceFiosFHTruncate(&attr, kNoHandle, 0)) == SCE_FIOS_ERROR_BAD_FH);

    const SceFiosBuffer vectors[] {
        SceFiosBuffer {storage, 4},
        SceFiosBuffer {storage + 4, 4},
    };
    const SceFiosBuffer emptyBase[] {
        SceFiosBuffer {nullptr, 4},
    };

    REQUIRE(WaitError(sceFiosFHReadv(&attr, kNoHandle, vectors, 0)) == SCE_FIOS_ERROR_BAD_IOVCNT);
    REQUIRE(WaitError(sceFiosFHReadv(&attr, kNoHandle, vectors, 1025)) == SCE_FIOS_ERROR_BAD_IOVCNT);
    REQUIRE(WaitError(sceFiosFHReadv(&attr, kNoHandle, nullptr, 1)) == SCE_FIOS_ERROR_BAD_PTR);
    REQUIRE(WaitError(sceFiosFHWritev(&attr, kNoHandle, emptyBase, 1)) == SCE_FIOS_ERROR_BAD_PTR);
    REQUIRE(WaitError(sceFiosFHPreadv(&attr, kNoHandle, vectors, 1, -1)) == SCE_FIOS_ERROR_BAD_OFFSET);

    REQUIRE(WaitError(sceFiosStat(&attr, nullptr, &status)) == SCE_FIOS_ERROR_BAD_PTR);
    REQUIRE(WaitError(sceFiosDirectoryExists(&attr, "", &exists)) == SCE_FIOS_ERROR_BAD_PATH);
    REQUIRE(WaitError(sceFiosFileDelete(&attr, nullptr)) == SCE_FIOS_ERROR_BAD_PTR);
    REQUIRE(WaitError(sceFiosRename(&attr, "/tmp/anyps5-async-errors-old", nullptr)) == SCE_FIOS_ERROR_BAD_PTR);

    return 0;
}
