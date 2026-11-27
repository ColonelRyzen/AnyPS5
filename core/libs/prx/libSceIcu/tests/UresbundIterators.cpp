// Test for the seven uresbund accessors and iterators implemented through the guest-memory contract.
#include <cstdint>
#include <cstring>
#include <functional>
#include <stdexcept>
#include <string>
#include <string_view>
#include <vector>

#ifdef _WIN32
#include <windows.h>
#else
#include <sys/mman.h>
#include <unistd.h>
#endif

#include "unicode/utypes.h"
#include "unicode/udata.h"
#include "unicode/ures.h"
#include "unicode/urename.h"
#include "unicode/resbund.h"
#include "uresdata.h"
#include "uresimp.h"
#include "prx/libc/include/general/ExportMacros.hpp"
#include "prx/libSceIcu/include/LegacyExports.hpp"

#include "prx/libSceIcu/include/Availability.hpp"

static_assert(std::is_same_v<
    decltype(&ures_getByKeyWithFallback_nid_postfix),
    UResourceBundle* (APS5_VABI*)(const UResourceBundle*, const char*, UResourceBundle*, std::int32_t*)>);
static_assert(std::is_same_v<
    decltype(&ures_getValueWithFallback_nid_postfix),
    void (APS5_VABI*)(const UResourceBundle*, const char*, UResourceBundle*, void*, std::int32_t*)>);
static_assert(std::is_same_v<
    decltype(&ures_getNextResource_nid_postfix),
    UResourceBundle* (APS5_VABI*)(UResourceBundle*, UResourceBundle*, std::int32_t*)>);
static_assert(std::is_same_v<
    decltype(&ures_getNextString_nid_postfix),
    const char16_t* (APS5_VABI*)(UResourceBundle*, std::int32_t*, const char**, std::int32_t*)>);
static_assert(std::is_same_v<
    decltype(&ures_getVersion_nid_postfix),
    void (APS5_VABI*)(const UResourceBundle*, std::uint8_t*)>);
static_assert(std::is_same_v<
    decltype(&ures_getVersionNumber_nid_postfix),
    const char* (APS5_VABI*)(const UResourceBundle*)>);
static_assert(std::is_same_v<
    decltype(&ures_resetIterator_nid_postfix),
    void (APS5_VABI*)(UResourceBundle*)>);

namespace {

void Require(bool condition, const std::string& message) {
    if (!condition) {
        fflush(stdout);
        throw std::runtime_error("icu uresbund iterators: " + message);
    }
}

bool Throws(const std::function<void()>& body) {
    try {
        body();
        return false;
    } catch (const std::exception&) {
        return true;
    }
}

constexpr std::size_t HeaderSize = 32;
constexpr std::uint32_t TableType = 2;
constexpr std::uint32_t TypeShift = 28;

constexpr std::int32_t IllegalArgument = 1;
constexpr std::int32_t IteratorExhausted = 8;

void Put16(std::vector<std::uint8_t>& bytes, std::size_t offset, std::uint16_t value) {
    std::memcpy(bytes.data() + offset, &value, sizeof(value));
}

void Put32(std::vector<std::uint8_t>& bytes, std::size_t offset, std::uint32_t value) {
    std::memcpy(bytes.data() + offset, &value, sizeof(value));
}

void PutHeader(std::vector<std::uint8_t>& bytes, std::size_t offset, std::string_view format) {
    Put16(bytes, offset, HeaderSize);
    bytes[offset + 2] = 0xda;
    bytes[offset + 3] = 0x27;
    Put16(bytes, offset + 4, 20);
    bytes[offset + 8] = U_IS_BIG_ENDIAN;
    bytes[offset + 9] = U_CHARSET_FAMILY;
    bytes[offset + 10] = U_SIZEOF_UCHAR;
    std::memcpy(bytes.data() + offset + 12, format.data(), 4);
    bytes[offset + 16] = 1;
}

std::size_t PutKey(std::vector<std::uint8_t>& bytes, std::size_t root, std::size_t& cursor, std::string_view key) {
    const auto offset = cursor - root;
    std::memcpy(bytes.data() + cursor, key.data(), key.size());
    cursor += key.size() + 1;
    return offset;
}

std::vector<std::uint8_t> TestIndex(const std::vector<std::string_view>& locales) {
    const std::string name = U_ICUDATA_NAME "/coll/res_index.res";
    std::vector<std::uint8_t> bytes(1024);
    PutHeader(bytes, 0, "CmnD");
    const std::size_t toc = HeaderSize;
    const std::size_t item = (toc + 12 + name.size() + 1 + 15) / 16 * 16;
    Put32(bytes, toc, 1);
    Put32(bytes, toc + 4, 12);
    Put32(bytes, toc + 8, static_cast<std::uint32_t>(item - toc));
    std::memcpy(bytes.data() + toc + 12, name.data(), name.size());
    PutHeader(bytes, item, "ResB");
    const std::size_t root = item + HeaderSize;
    std::size_t cursor = root + 4;
    const auto installedKey = PutKey(bytes, root, cursor, "InstalledLocales");
    std::vector<std::size_t> keys;
    for (const auto locale : locales) keys.push_back(PutKey(bytes, root, cursor, locale));
    cursor = (cursor + 3) / 4 * 4;
    const auto installed = cursor;
    Put16(bytes, cursor, static_cast<std::uint16_t>(locales.size()));
    cursor += 2;
    for (const auto key : keys) {
        Put16(bytes, cursor, static_cast<std::uint16_t>(key));
        cursor += 2;
    }
    cursor = (cursor + 3) / 4 * 4 + 4 * locales.size();
    const auto top = cursor;
    Put16(bytes, cursor, 1);
    Put16(bytes, cursor + 2, static_cast<std::uint16_t>(installedKey));
    Put32(bytes, cursor + 4, (TableType << TypeShift) | static_cast<std::uint32_t>((installed - root) / 4));
    Put32(bytes, root, (TableType << TypeShift) | static_cast<std::uint32_t>((top - root) / 4));
    Require(cursor + 8 <= bytes.size(), "the test data does not fit its buffer");
    return bytes;
}

void* GuestPages = nullptr;
std::size_t PageSize = 0;

void SetUpPages() {
#ifdef _WIN32
    PageSize = 4096;
    GuestPages = VirtualAlloc(nullptr, PageSize * 2, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
    Require(GuestPages != nullptr, "reserve guest pages");
    DWORD oldProtection = 0;
    Require(VirtualProtect(static_cast<char*>(GuestPages) + PageSize, PageSize, PAGE_NOACCESS, &oldProtection) != 0, "protect the guard page");
#else
    PageSize = static_cast<std::size_t>(sysconf(_SC_PAGESIZE) > 0 ? sysconf(_SC_PAGESIZE) : 4096);
    GuestPages = mmap(nullptr, PageSize * 2, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    Require(GuestPages != MAP_FAILED, "map guest pages");
    Require(mprotect(static_cast<char*>(GuestPages) + PageSize, PageSize, PROT_NONE) == 0, "protect the guard page");
#endif
}

void* GuestBuffer(std::size_t bytes) {
    return static_cast<std::uint8_t*>(GuestPages) + PageSize - bytes;
}

std::size_t GuestCursor = 0;

char* GuestString(const char* text) {
    auto* buffer = static_cast<char*>(GuestPages) + GuestCursor;
    std::strcpy(buffer, text);
    GuestCursor += std::strlen(buffer) + 1;
    return buffer;
}

void GuardAxis() {
    Require(Throws([&] {
        ures_getByKeyWithFallback_nid_postfix(nullptr, nullptr,
            static_cast<UResourceBundle*>(GuestBuffer(sizeof(UResourceBundle))),
            static_cast<std::int32_t*>(GuestBuffer(4)));
    }),
        "getByKeyWithFallback throws on a null key (bundled ICU dereferences it)");

    {
        UResourceBundle fill{};
        ures_initStackObject(&fill);
        std::int32_t status = 0;
        icu::ResourceDataValue value;
        Require(Throws([&] {
            ures_getValueWithFallback_nid_postfix(&fill, "InstalledLocales", &fill, nullptr, &status);
        }),
            "getValueWithFallback throws on a null value (bundled ICU writes through it unconditionally)");
        Require(Throws([&] {
            icu::ResourceDataValue value;
            ures_getValueWithFallback_nid_postfix(&fill, "InstalledLocales", &fill, &value, nullptr);
        }),
            "getValueWithFallback throws on a null error (bundled ICU reads the reference unconditionally)");
    }

    Require(Throws([&] {
        UResourceBundle fill{};
        ures_initStackObject(&fill);
        ures_getVersion_nid_postfix(&fill, nullptr);
    }),
        "getVersion throws on a null version buffer (bundled ICU writes through it unconditionally)");
}

} // namespace

int main(int argc, char** argv) {
    Require(argc == 2, "expected one argument: empty or data");
    const bool installed = std::string_view(argv[1]) == "data";
    SetUpPages();

    alignas(16) static std::uint8_t storage[1024];
    if (installed) {
        auto image = TestIndex({"de", "en_US"});
        std::memcpy(storage, image.data(), image.size());
        std::int32_t oursInstall = 0;
        udata_setCommonData_nid_postfix(storage, &oursInstall);
        Require(oursInstall == 0, "install through the export, status " + std::to_string(oursInstall));
        UErrorCode controlInstall = U_ZERO_ERROR;
        udata_setCommonData(storage, &controlInstall);
        Require(static_cast<int>(controlInstall) == 0, "install through bundled ICU, status " + std::to_string(static_cast<int>(controlInstall)));
    }

    GuardAxis();


    {
        std::int32_t oursStatus = 0;
        UErrorCode controlStatus = U_ZERO_ERROR;
        auto* ours = ures_getByKeyWithFallback_nid_postfix(nullptr, "InstalledLocales", nullptr, &oursStatus);
        auto* control = ures_getByKeyWithFallback(nullptr, "InstalledLocales", nullptr, &controlStatus);
        Require(ours == nullptr && control == nullptr, "the null-bundle lookup returns nothing on either side");
        Require(oursStatus == IllegalArgument && static_cast<int>(controlStatus) == IllegalArgument, "the null-bundle lookup reports illegal argument on both sides");
    }
    {
        UResourceBundle oursFill{}, controlFill{};
        ures_initStackObject(&oursFill);
        ures_initStackObject(&controlFill);
        std::int32_t oursStatus = 2;
        UErrorCode controlStatus = static_cast<UErrorCode>(2);
        auto* ours = ures_getNextResource_nid_postfix(nullptr, &oursFill, &oursStatus);
        auto* control = ures_getNextResource(nullptr, &controlFill, &controlStatus);
        Require(ours == &oursFill && control == &controlFill, "a failing status returns the fill-in untouched on both sides");
        Require(oursStatus == 2 && static_cast<int>(controlStatus) == 2, "a failing status stays untouched on both sides");
    }
    {
        std::int32_t oursStatus = 0;
        UErrorCode controlStatus = U_ZERO_ERROR;
        auto* ours = ures_getNextString_nid_postfix(nullptr, nullptr, nullptr, &oursStatus);
        const char16_t* control = ures_getNextString(nullptr, nullptr, nullptr, &controlStatus);
        Require(ours == nullptr && control == nullptr, "a null bundle yields no string on either side");
        Require(oursStatus == IllegalArgument && static_cast<int>(controlStatus) == IllegalArgument,
            "the null-bundle string iteration reports illegal argument on both sides");
    }
    {
        std::int32_t oursStatus = 0;
        UErrorCode controlStatus = U_ZERO_ERROR;
        icu::ResourceDataValue ourValue, controlValue;
        Require(Throws([&] { ures_getValueWithFallback_nid_postfix(nullptr, "x", nullptr, &ourValue, &oursStatus); }),
            "the export refuses a null bundle outright");
        ures_getValueWithFallback(nullptr, "x", nullptr, controlValue, controlStatus);
        Require(static_cast<int>(controlStatus) == IllegalArgument, "bundled ICU reports the null bundle through a failing status instead");
        (void)ourValue;
        (void)controlValue;
    }
    printf("AX getVersionNumber null: ours %p theirs %p\n", (void*)ures_getVersionNumber_nid_postfix(nullptr), (void*)ures_getVersionNumber(nullptr));
    ures_resetIterator_nid_postfix(nullptr);
    ures_resetIterator(nullptr);
    Require(true, "a null bundle survives the iterator reset on both sides");

    if (installed) {
        {
            UResourceBundle oursBundle{}, controlBundle{};
            ures_initStackObject(&oursBundle);
            ures_initStackObject(&controlBundle);
            UErrorCode oursOpen = U_ZERO_ERROR;
            UErrorCode controlOpen = U_ZERO_ERROR;
            ures_openDirectFillIn(&oursBundle, U_ICUDATA_NAME, "coll/res_index", &oursOpen);
            ures_openDirectFillIn(&controlBundle, U_ICUDATA_NAME, "coll/res_index", &controlOpen);
            Require(oursOpen == controlOpen, "a null fill-in open reports the same status on both sides, ours " + std::to_string(static_cast<int>(oursOpen)) + " theirs " + std::to_string(static_cast<int>(controlOpen)));
            {
                std::int32_t oursLookup = 0;
                auto* ours = ures_getByKeyWithFallback_nid_postfix(&oursBundle, "InstalledLocales", nullptr, &oursLookup);
                auto* control = ures_getByKeyWithFallback(&controlBundle, "InstalledLocales", nullptr, &controlOpen);
                Require(ours == nullptr && control == nullptr, "the table-key lookup returns nothing on either side");
                Require(oursLookup == 17 && static_cast<int>(controlOpen) == 2,
                    "the measured split stands: the export lands on resource-type-mismatch where bundled ICU lands on missing-resource");
            }
            {
                UResourceBundle ourFill{}, theirFill{};
                ures_initStackObject(&ourFill);
                ures_initStackObject(&theirFill);
                std::int32_t os = 0;
                UErrorCode ts = U_ZERO_ERROR;
                auto* nr = ures_getNextResource_nid_postfix(&oursBundle, &ourFill, &os);
                auto* nrT = ures_getNextResource(&controlBundle, &theirFill, &ts);
                Require(nr == &ourFill && nrT == &theirFill, "the iterator fills the fill-in on both sides");
                Require(os == 0 && static_cast<int>(ts) == 0, "the first iterator step succeeds on both sides");
                auto* s1 = ures_getNextString_nid_postfix(&oursBundle, nullptr, nullptr, &os);
                const char16_t* s2 = ures_getNextString(&controlBundle, nullptr, nullptr, &ts);
                Require((s1 == nullptr) == (s2 == nullptr), "the string iterator agrees on both sides");
                Require(os == static_cast<std::int32_t>(ts), "the string iterator agrees on the status on both sides");
                ures_resetIterator_nid_postfix(&oursBundle);
                ures_resetIterator(&controlBundle);
                auto* nr2 = ures_getNextResource_nid_postfix(&oursBundle, &ourFill, &os);
                auto* nr2T = ures_getNextResource(&controlBundle, &theirFill, &ts);
                Require(nr2 == &ourFill && nr2T == &theirFill, "the reset iterator fills the fill-in on both sides");
                Require(os == static_cast<std::int32_t>(ts), "the reset iterator agrees on the status on both sides");
            }
            {
                std::uint8_t vOur[4] = {9, 9, 9, 9};
                std::uint8_t vTheirs[4] = {9, 9, 9, 9};
                std::int32_t os = 0;
                UErrorCode ts = U_ZERO_ERROR;
                ures_getVersion_nid_postfix(&oursBundle, vOur);
                ures_getVersion(&controlBundle, vTheirs);
                Require(std::memcmp(vOur, vTheirs, sizeof(vOur)) == 0, "the version info agrees on both sides");
                Require(std::string_view(ures_getVersionNumber_nid_postfix(&oursBundle)) ==
                    std::string_view(ures_getVersionNumber(&controlBundle)), "the version number agrees on both sides");
            }
            {
                icu::ResourceDataValue vOur, vTheirs;
                std::int32_t os = 0;
                UErrorCode ts = U_ZERO_ERROR;
                ures_getValueWithFallback_nid_postfix(&oursBundle, "InstalledLocales", nullptr, &vOur, &os);
                ures_getValueWithFallback(&controlBundle, "InstalledLocales", nullptr, vTheirs, ts);
                Require(static_cast<int>(os) == static_cast<int>(ts), "the path lookup lands on the same status on both sides");
            }
        }
    }

    printf("PASS\n");
    return 0;
}
