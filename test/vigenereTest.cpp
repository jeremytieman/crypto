#include <vigenere.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>

namespace cryptoTest
{
  TEST_CASE("Verify Vigenere cipher encrypts and decrypts correctly", "[vigenere]")
  {
    REQUIRE(waves::vigenereEncrypt("CRYPTO", "DUH") == std::string("FLFSNV"));
    REQUIRE(waves::vigenereDecrypt("FLFSNV", "DUH") == std::string("CRYPTO"));
    REQUIRE(waves::vigenereEncrypt("THEY DRINK THE TEA", "DUH") == std::string("WBLBXYLHRWBLWYH"));
    REQUIRE(waves::vigenereDecrypt("WBLB XYLHR WBL WYH", "DUH") == std::string("THEYDRINKTHETEA"));
  }
}
