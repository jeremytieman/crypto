#include <caesar.hpp>
#include <catch2/catch_test_macros.hpp>
#include <string>

namespace cryptoTest
{
  TEST_CASE("Verify Caesar Shift encrypts and decrypts correctly", "[caesar shift]")
  {
    REQUIRE(waves::caesar_shift("CAESAR", 3) == std::string("FDHVDU"));
    REQUIRE(waves::caesar_shift("FDHVDU", -3) == std::string("CAESAR"));
    REQUIRE(waves::caesar_shift("caesar", 3) == std::string("fdhvdu"));
    REQUIRE(waves::caesar_shift("fdhvdu", -3) == std::string("caesar"));
    REQUIRE(waves::caesar_shift("CAEsar", 3) == std::string("FDHvdu"));
    REQUIRE(waves::caesar_shift("XYZABC", 3) == std::string("ABCDEF"));
    REQUIRE(waves::caesar_shift("ABCDEF", -3) == std::string("XYZABC"));
  }
}
