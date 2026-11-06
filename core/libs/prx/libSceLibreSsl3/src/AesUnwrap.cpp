#include "prx/libSceLibreSsl3/include/Api.hpp"
#include "prx/libSceLibreSsl/libSceLibreSsl.hpp"
#include <cstdint>
#include <cstring>
#include <stdexcept>
#include <string>
#include <vector>

namespace {

constexpr unsigned char DefaultIv[8] = {0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6, 0xA6};

}

extern "C" {

int APS5_VABI AES_unwrap_key_nid_postfix(AesKey* key, const unsigned char* iv, unsigned char* out, const unsigned char* in, std::uint32_t inlen) {
    if (!key || !out || !in) throw std::invalid_argument(std::string(__func__) + ": null argument");
    if (inlen < 16 || (inlen & 7) != 0) return -1;
    const std::uint32_t blocks = inlen / 8;
    const std::uint32_t n = blocks - 1;
    unsigned char a[8];
    std::memcpy(a, in, sizeof(a));
    std::vector<unsigned char> r(in + 8, in + inlen);
    for (std::uint32_t round = 0; round < 6; ++round) {
        for (std::uint32_t index = n; index >= 1; --index) {
            unsigned char block[16];
            std::memcpy(block, a, 8);
            const std::uint64_t counter = static_cast<std::uint64_t>(n) * (5 - round) + index;
            for (std::uint32_t byte = 0; byte < 8; ++byte) {
                block[7 - byte] ^= static_cast<unsigned char>(counter >> (8 * byte));
            }
            std::memcpy(block + 8, r.data() + (index - 1) * 8, 8);
            unsigned char decrypted[16];
            AES_decrypt_nid_postfix(block, decrypted, key);
            std::memcpy(a, decrypted, 8);
            std::memcpy(r.data() + (index - 1) * 8, decrypted + 8, 8);
        }
    }
    if (CRYPTO_memcmp_nid_postfix(a, iv ? iv : DefaultIv, sizeof(a)) != 0) return -1;
    std::memcpy(out, r.data(), inlen - 8);
    return static_cast<int>(inlen - 8);
}

}
