#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "BigInt.hpp"
#include <iosfwd>
#include <stdexcept>
#include <vector>
#include <limits>

using namespace std;

// TESTING CONSTRUCTORS

TEST_CASE("BigInt: default constructor")
{
    ostringstream out;
    BigInt x;

    out << x;
    REQUIRE(out.str() == "0");
}

TEST_CASE("BigInt: Constructor with string")
{
    ostringstream out;

    SUBCASE("Case 1: 123")
    {
        BigInt x("123");
        out << x;

        REQUIRE(out.str() == "123");
    }

    SUBCASE("Case 2: -12323535344")
    {
        BigInt x("-12323535344");
        out << x;

        REQUIRE(out.str() == "-12323535344");
    }

    SUBCASE("Case 3: +12323535344")
    {
        BigInt x("+12323535344");
        out << x;

        REQUIRE(out.str() == "12323535344");
    }

    SUBCASE("Case 4: 1o3d34534436a")
    {
        REQUIRE_THROWS_AS(BigInt x("1o3d34534436a"), runtime_error);
    }

    SUBCASE("Case 5: '-' ")
    {
        REQUIRE_THROWS_AS(BigInt("-"), runtime_error);
    }

    SUBCASE("Case 6: 0000123")
    {
        BigInt x("0000123");
        out << x;

        REQUIRE(out.str() == "123");
    }

    SUBCASE("Case 7: -0000123")
    {
        BigInt x("-0000123");
        out << x;

        REQUIRE(out.str() == "-123");
    }

    SUBCASE("Case 8: 0000")
    {
        BigInt x("0000");
        out << x;

        REQUIRE(out.str() == "0");
    }

    SUBCASE("Case 9: -0 ")
    {
        BigInt x("-0");
        out << x;

        REQUIRE(out.str() == "0");
    }
    SUBCASE("Case 10: empty string ")
    {
        REQUIRE_THROWS_AS(BigInt(""), runtime_error);
    }
    SUBCASE("Case 11: 1_000_000_000")
    {
        BigInt x("1_000_000_000");
        out << x;

        REQUIRE(out.str() == "1000000000");
    }
}

TEST_CASE("Check constructor with integer parameter")
{
    std::ostringstream sout;
    SUBCASE("Case 1:")
    {
        BigInt x(numeric_limits<long long>::min());
        sout << x;

        REQUIRE(sout.str() == "-9223372036854775808");
    }
}

// TESTING INPUT OPERATOR

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

// TESTING ADDITION OPERATOR

TEST_CASE("BigInt: '+' operator")
{
    std::ostringstream sout;

    SUBCASE("Case 1: 123 + 12")
    {
        BigInt x("123");
        BigInt y("12");

        BigInt sum = x + y;

        sout << sum;

        REQUIRE(sout.str() == "135");
    }
    SUBCASE("Case 2: 999999999 + 1")
    {
        std::ostringstream out;
        BigInt x("999999999");
        BigInt y("1");

        out << x + y;

        REQUIRE(out.str() == "1000000000");
    }
    SUBCASE("Case 3: -123 + (-123)")
    {
        BigInt x("-123");
        BigInt y("-123");

        BigInt sum = x + y;

        sout << sum;

        REQUIRE(sout.str() == "-246");
    }
    SUBCASE("Case 4:  + (-123)")
    {
        BigInt x("-123");
        BigInt y("-123");

        BigInt sum = x + y;

        sout << sum;

        REQUIRE(sout.str() == "-246");
    }

    // SUBCASE("Case 4: [0, 1000]")
    // {
    //     for (int i = 0; i < 1000; i++)
    //     {
    //         for (int j = 0; j < 1000; j++)
    //         {
    //             BigInt x = i;
    //             BigInt y = j;

    //             ostringstream sout2;
    //             sout2 << x + y;
    //             REQUIRE(sout2.str() == to_string(i + j));
    //         }
    //     }
    // }
}