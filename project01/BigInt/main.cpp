#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "BigInt.hpp"
#include <iosfwd>
#include <stdexcept>

using namespace std;

// TESTING CONSTRUCTORS

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

    SUBCASE("Case 2: Check BigInt with '-' sign")
    {
        BigInt x("-12323535344");
        out << x;

        REQUIRE(out.str() == "-12323535344");
    }

    SUBCASE("Case 2: Check BigInt with '+' sign")
    {
        BigInt x("+12323535344");
        out << x;

        REQUIRE(out.str() == "12323535344");
    }

    SUBCASE("Case 3: Check initialization with some non-digits string parameter")
    {
        REQUIRE_THROWS_AS(BigInt x("1o3d34534436a"), runtime_error);
    }

    SUBCASE("Case 4: Only sign is given case")
    {
        REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    }

    SUBCASE("Case 5: Zeros in the beginning")
    {
        BigInt x("0000123");
        out << x;

        REQUIRE(out.str() == "123");
    }

    SUBCASE("Case 5: Zeros in the beginning with minus sign")
    {
        BigInt x("-0000123");
        out << x;

        REQUIRE(out.str() == "-123");
    }

    SUBCASE("Case 6: Zeros in the beginning with plus sign")
    {
        BigInt x("+0000123");
        out << x;

        REQUIRE(out.str() == "123");
    }

    SUBCASE("Case 7: Many zeros")
    {
        BigInt x("0000");
        out << x;

        REQUIRE(out.str() == "0");
    }

    SUBCASE("Case 7: -0 situation")
    {
        BigInt x("-0");
        out << x;

        REQUIRE(out.str() == "0");
    }
    SUBCASE("Case 7: 1_000_000_000 situation")
    {
        BigInt x("1_000_000_000");
        out << x;

        REQUIRE(out.str() == "1000000000");
    }
}

// TESTING INPUT CASES

TEST_CASE("BigInt: Input ceses")
{
    std::ostringstream sout;
    SUBCASE("Case 1: Proper input")
    {
        BigInt x;
        std::istringstream sin("12345");

        sin >> x;
        sout << x;

        REQUIRE(sout.str() == "12345");
    }

    SUBCASE("Case 2: input with plus sign")
    {
        std::istringstream sin("+1234");
        BigInt x;
        sin >> x;
        sout << x;

        REQUIRE(sout.str() == "1234");
    }

    SUBCASE("Case 2: input with minus sign")
    {
        std::istringstream sin("-1234");
        BigInt x;
        sin >> x;
        sout << x;

        REQUIRE(sout.str() == "-1234");
    }

    SUBCASE("Case 2: input with other signs")
    {
        std::istringstream sin("&1234");
        BigInt y;
        REQUIRE_THROWS_AS(sin >> y, runtime_error);
    }

    SUBCASE("Case 3: 00000123")
    {
        std::istringstream sin("00000123");
        BigInt x;
        sin >> x;
        sout << x;

        REQUIRE(sout.str() == "123");
    }

    SUBCASE("Case 4: 0000000")
    {
        std::istringstream sin("00000");
        BigInt x;
        sin >> x;
        sout << x;

        REQUIRE(sout.str() == "0");
    }

    SUBCASE("Case 5: -0")
    {
        std::istringstream sin("-0");
        BigInt x;
        sin >> x;
        sout << x;

        REQUIRE(sout.str() == "0");
    }
}

