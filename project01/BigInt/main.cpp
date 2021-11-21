#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "BigInt.hpp"
#include <iosfwd>

TEST_CASE("BigInt default constructor")
{
    std::ostringstream out;
    BigInt x;

    out << x;
    REQUIRE(out.str() == "0");
}

TEST_CASE("BigInt with string constructor")
{
    std::ostringstream out;
    BigInt x("123");

    out << x;

    REQUIRE(out.str() == "123");
}