#include <cstdint>
#include <cstdio>
#include <cstring>
#include <functional>
#include <string>
#include <vector>
#include "prx/libSceLibreSsl/include/Api.hpp"
#include "prx/libSceLibreSsl3/include/Api.hpp"

namespace {

int failures = 0;

void Require(bool condition, const char* what) {
    if (!condition) {
        std::printf("FAIL: %s\n", what);
        ++failures;
    }
}

bool ExpectThrow(const std::function<void()>& call, const char* what) {
    try {
        call();
    } catch (...) {
        return true;
    }
    std::printf("FAIL: %s did not throw\n", what);
    ++failures;
    return false;
}

std::vector<unsigned char> FromHex(const char* hex) {
    Require(strlen(hex) % 2 == 0, "hex vector literal has odd length");
    std::vector<unsigned char> bytes;
    for (std::size_t index = 0; hex[index] != '\0'; index += 2) {
        bytes.push_back(static_cast<unsigned char>(std::stoul(std::string(hex + index, 2), nullptr, 16)));
    }
    return bytes;
}

AesKey MakeKey(const char* hex) {
    const auto key = FromHex(hex);
    AesKey schedule;
    AES_set_decrypt_key_nid_postfix(key.data(), static_cast<int>(key.size()) * 8, &schedule);
    return schedule;
}

}

int main() {
    auto kek128 = MakeKey("000102030405060708090a0b0c0d0e0f");
    const auto wrapped = FromHex("1fa68b0a8112b447aef34bd8fb5a7b829d3e862371d2cfe5");
    const auto expected = FromHex("00112233445566778899aabbccddeeff");

    std::vector<unsigned char> plain(16);
    Require(AES_unwrap_key_nid_postfix(&kek128, nullptr, plain.data(), wrapped.data(), 24) == 16, "RFC 3394 vector 4.1 unwraps");
    Require(std::memcmp(plain.data(), expected.data(), 16) == 0, "RFC 3394 vector 4.1 plaintext");

    const unsigned char altIv[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    {
        auto kek192 = MakeKey("000102030405060708090a0b0c0d0e0f1011121314151617");
        const auto wrapped192 = FromHex("96778b25ae6ca435f92b5b97c050aed2468ab8a17ad84e5d");
        std::vector<unsigned char> plain16b(16);
        Require(AES_unwrap_key_nid_postfix(&kek192, nullptr, plain16b.data(), wrapped192.data(), 24) == 16 &&
                std::memcmp(plain16b.data(), expected.data(), 16) == 0, "RFC 3394 vector 4.2 unwraps with 192-bit KEK");
        const auto wrapped192b = FromHex("031d33264e15d33268f24ec260743edce1c6c7ddee725a936ba814915c6762d2");
        std::vector<unsigned char> plain24(24);
        Require(AES_unwrap_key_nid_postfix(&kek192, nullptr, plain24.data(), wrapped192b.data(), 32) == 24 &&
                std::memcmp(plain24.data(), expected.data(), 16) == 0 && plain24[23] == 0x07, "RFC 3394 vector 4.4 unwraps with n=3");
        auto kek256 = MakeKey("000102030405060708090a0b0c0d0e0f101112131415161718191a1b1c1d1e1f");
        const auto wrapped256 = FromHex("28c9f404c4b810f4cbccb35cfb87f8263f5786e2d80ed326cbc7f0e71a99f43bfb988b9b7a02dd21");
        std::vector<unsigned char> plain32(32);
        Require(AES_unwrap_key_nid_postfix(&kek256, nullptr, plain32.data(), wrapped256.data(), 40) == 32, "RFC 3394 vector 4.6 unwraps");
        Require(std::memcmp(plain32.data(), expected.data(), 16) == 0 &&
                plain32[16] == 0x00 && plain32[31] == 0x0f, "RFC 3394 vector 4.6 plaintext");
        auto tamperedMulti = wrapped256;
        tamperedMulti[39] ^= 0x01;
        Require(AES_unwrap_key_nid_postfix(&kek256, nullptr, plain32.data(), tamperedMulti.data(), 40) == -1, "tampered multi-block returns -1");
        std::vector<unsigned char> tiny(16, 0x5a);
        std::vector<unsigned char> out8(8);
        const int tinyResult = AES_unwrap_key_nid_postfix(&kek256, nullptr, out8.data(), tiny.data(), 16);
        Require(tinyResult == 8 || tinyResult == -1, "16-byte input stays on a defined path");
    }
    Require(AES_unwrap_key_nid_postfix(&kek128, altIv, plain.data(), wrapped.data(), 24) == -1, "custom IV mismatch returns -1");
    Require(AES_unwrap_key_nid_postfix(&kek128, nullptr, plain.data(), wrapped.data(), 8) == -1, "8-byte input returns -1");
    Require(AES_unwrap_key_nid_postfix(&kek128, nullptr, plain.data(), wrapped.data(), 15) == -1, "unaligned input returns -1");

    auto tampered = wrapped;
    tampered[16] ^= 0x80;
    Require(AES_unwrap_key_nid_postfix(&kek128, nullptr, plain.data(), tampered.data(), 24) == -1, "tampered ciphertext returns -1");
    tampered = wrapped;
    tampered[0] ^= 0x01;
    Require(AES_unwrap_key_nid_postfix(&kek128, nullptr, plain.data(), tampered.data(), 24) == -1, "tampered integrity check value returns -1");

    ExpectThrow([&] { AES_unwrap_key_nid_postfix(nullptr, nullptr, plain.data(), wrapped.data(), 24); }, "null key throws");
    ExpectThrow([&] { AES_unwrap_key_nid_postfix(&kek128, nullptr, nullptr, wrapped.data(), 24); }, "null output throws");
    ExpectThrow([&] { AES_unwrap_key_nid_postfix(&kek128, nullptr, plain.data(), nullptr, 24); }, "null input throws");

    if (failures == 0) std::printf("all AES_unwrap_key checks passed\n");
    return failures == 0 ? 0 : 1;
}
