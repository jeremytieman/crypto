#include <vigenere.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>

namespace cryptoTest
{
  TEST_CASE("Verify Vigenere cipher encrypts and decrypts correctly", "[vigenere]")
  {
    REQUIRE(waves::vigenereEncrypt("CRYPTO", "DUH") == std::string("FLFSNV"));
  }
}
