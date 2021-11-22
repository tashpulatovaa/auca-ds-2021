#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "BigInt.hpp"
#include <iosfwd>
#include <stdexcept>

using namespace std;

TEST_CASE("BigInt default constructor")
{
    ostringstream out;
    BigInt x;

    out << x;
    REQUIRE(out.str() == "0");
}

TEST_CASE("BigInt with string constructor")
{
    ostringstream out;
    SUBCASE("Case 1: Check initialization with proper string parameter")
    {
        BigInt x("123");
        out << x;

        REQUIRE(out.str() == "123");
    }

    SUBCASE("Case 2: Check BigInt with sign")
    {
        BigInt x("-12323535344");
        out << x;

        REQUIRE(out.str() == "-12323535344");
    }

    SUBCASE("Case 3: Check initialization with some non-digits string parameter")
    {
        BigInt x("1o3d34534436a");
        //  out << x;

        REQUIRE_THROWS_AS(BigInt x("1o3d34534436a"), std::runtime_error);
    }
}