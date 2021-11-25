#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "BigInt.hpp"
#include <iosfwd>
#include <stdexcept>
#include <vector>

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

TEST_CASE("Check constructor with integer parameter")
{
    std::ostringstream sout;
    SUBCASE("Case 1: Proper integer parameter")
    {
        int n = 1234;
        BigInt x(n);

        sout << x;

        REQUIRE(sout.str() == "1234");
    }

    // Come to this CASE later
    // In this case 0000013 is equal to 11, int converts to octal.That is why the result of sout.str() is not 13.

    // SUBCASE("Case 1: 0000013")
    // {
    //     int n = 0000013;
    //     BigInt x(n);
    //     sout << x;

    //     REQUIRE(sout.str() == "13");
    // }

    SUBCASE("Case 2: Negative int value")
    {
        int n = -1234;
        BigInt x(n);

        sout << x;

        REQUIRE(sout.str() == "-1234");
    }

    SUBCASE("Case 3: int = 0 case")
    {
        int n = 0;
        BigInt x(n);

        sout << x;

        REQUIRE(sout.str() == "0");
    }
    SUBCASE("Case 4: int = -0 case")
    {
        int n = -0;
        BigInt x(n);

        sout << x;

        REQUIRE(sout.str() == "0");
    }
    SUBCASE("Case 5: int = +0 case")
    {
        int n = -0;
        BigInt x(n);

        sout << x;

        REQUIRE(sout.str() == "0");
    }
    SUBCASE("Case 6: int = 0000 case")
    {
        int n = 0000;
        BigInt x(n);

        sout << x;

        REQUIRE(sout.str() == "0");
    }
}

TEST_CASE("BigInt: '+' operator")
{
    std::ostringstream sout;
    SUBCASE("Case 1: Summing simple BigInts without signs")
    {
        BigInt x("123");
        BigInt y("12");

        BigInt sum = x + y;

        sout << sum;

        REQUIRE(sout.str() == "135");
    }
    SUBCASE("Case 2: Summing BigInts with equal size")
    {
        BigInt x("123");
        BigInt y("123");

        BigInt sum = x + y;

        sout << sum;

        REQUIRE(sout.str() == "246");
    }
    SUBCASE("Case 3: Summing simple 2 negative BigInts")
    {
        BigInt x("-123");
        BigInt y("-123");

        BigInt sum = x + y;

        sout << sum;

        REQUIRE(sout.str() == "-246");
    }
    SUBCASE("Case 4: Summing BigInts that creat BigInt with bigger size")
    {
        BigInt x("923");
        BigInt y("123");

        BigInt sum = x + y;

        sout << sum;

        REQUIRE(sout.str() == "1046");
    }
    SUBCASE("Case 5: Summing BigInts with signs that creat BigInt with bigger size")
    {
        BigInt x("-923");
        BigInt y("-123");

        BigInt sum = x + y;

        sout << sum;

        REQUIRE(sout.str() == "-1046");
    }
    // SUBCASE("Case 6: Summing BigInts with signs that creat BigInt with bigger size")
    // {
    //     BigInt x("998986678");
    //     BigInt y("1457474");

    //     BigInt sum = x + y;

    //     sout << sum;

    //     REQUIRE(sout.str() == "1000444152");
    // }
}