#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "Rational.hpp"

#include <cstdint>
#include <sstream>

using namespace std;

TEST_CASE("Rational: default constructor")
{
    Rational<int> r;

    ostringstream sout;
    sout << r;

    REQUIRE(sout.str() == "0/1");
}

TEST_CASE("Rational: constructor with numerator and denominator")
{
    ostringstream sout;

    SUBCASE("Test with 1/2")
    {
        Rational<int> r(1, 2);
        sout << r;
        REQUIRE(sout.str() == "1/2");
    }

    SUBCASE("Test with 3/2")
    {
        Rational<int> r(3, 2);
        sout << r;
        REQUIRE(sout.str() == "3/2");
    }

    SUBCASE("Test with 30/25")
    {
        Rational<int> r(30, 25);
        sout << r;
        REQUIRE(sout.str() == "6/5");
    }

    SUBCASE("Test with 17/31")
    {
        Rational<int> r(17, 31);
        sout << r;
        REQUIRE(sout.str() == "17/31");
    }
    SUBCASE("Test with -30/-20")
    {
        Rational<int> r(-30, -20);
        sout << r;
        REQUIRE(sout.str() == "3/2");
    }
    SUBCASE("Test with 30/-20")
    {
        Rational<int> r(30, -20);
        sout << r;
        REQUIRE(sout.str() == "-3/2");
    }

    SUBCASE("Test with 3/0")
    {
        REQUIRE_THROWS_AS(Rational<int> r(3, 0), runtime_error);
    }
}

TEST_CASE("Rational: addition")
{
    ostringstream sout;
    SUBCASE("1/2 + 1/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);

        sout << r1 + r2;

        REQUIRE(sout.str() == "5/6");
    }
}

TEST_CASE("Rational: subtraction")
{
    ostringstream sout;
    SUBCASE("1/2 - 1/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);

        sout << r1 - r2;

        REQUIRE(sout.str() == "1/6");
    }
}
TEST_CASE("Rational: multiplication")
{
    ostringstream sout;
    SUBCASE("1/2 * 1/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);

        sout << r1 * r2;

        REQUIRE(sout.str() == "1/6");
    }
}
TEST_CASE("Rational: divition")
{
    ostringstream sout;
    SUBCASE("1/2 / 1/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);

        sout << r1 / r2;

        REQUIRE(sout.str() == "3/2");
    }
    SUBCASE("1/2 / 0/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(0, 3);

        //sout << r1 / r2;

        REQUIRE_THROWS_AS(r1 / r2, runtime_error);
    }
}

TEST_CASE("Rational: Operator <")
{
    ostringstream sout;

    SUBCASE("1/3 < 1/2")
    {
        Rational<int> r1(1, 3);
        Rational<int> r2(1, 2);

        sout << boolalpha << (r1 < r2);

        REQUIRE(sout.str() == "true");
    }
    SUBCASE("1/2 < 1/3")
    {
        Rational<int> r1(1, 2);
        Rational<int> r2(1, 3);

        sout << boolalpha << (r1 < r2);

        REQUIRE(sout.str() == "false");
    }
}
TEST_CASE("Rational: Operator >")
{
    ostringstream sout;

    SUBCASE("2/3 > 1/3")
    {
        Rational<int> r1(2, 3);
        Rational<int> r2(1, 3);

        sout << boolalpha << (r1 > r2);

        REQUIRE(sout.str() == "true");
    }
    SUBCASE("1/5 > 1/4")
    {
        Rational<int> r1(1, 5);
        Rational<int> r2(1, 4);

        sout << boolalpha << (r1 > r2);

        REQUIRE(sout.str() == "false");
    }
}

TEST_CASE("Rationla: == operator")
{
    ostringstream sout;

    SUBCASE("3/5 3/5")
    {
        Rational<int> r1(3, 5);
        Rational<int> r2(3, 5);

        sout << boolalpha << (r1 == r2);

        REQUIRE(sout.str() == "true");
    }
    SUBCASE("3/4 3/5")
    {
        Rational<int> r1(3, 4);
        Rational<int> r2(3, 5);

        sout << boolalpha << (r1 == r2);

        REQUIRE(sout.str() == "false");
    }
}
TEST_CASE("Rationla: != operator")
{
    ostringstream sout;

    SUBCASE("3/5 3/5")
    {
        Rational<int> r1(3, 5);
        Rational<int> r2(3, 5);

        sout << boolalpha << (r1 != r2);

        REQUIRE(sout.str() == "false");
    }
    SUBCASE("3/4 3/5")
    {
        Rational<int> r1(3, 4);
        Rational<int> r2(3, 5);

        sout << boolalpha << (r1 != r2);

        REQUIRE(sout.str() == "true");
    }
}
TEST_CASE("Rationla: <= operator")
{
    ostringstream sout;

    SUBCASE("3/5 3/2")
    {
        Rational<int> r1(3, 5);
        Rational<int> r2(3, 2);

        sout << boolalpha << (r1 <= r2);

        REQUIRE(sout.str() == "true");
    }
    SUBCASE("3/5 3/5")
    {
        Rational<int> r1(3, 5);
        Rational<int> r2(3, 5);

        sout << boolalpha << (r1 <= r2);

        REQUIRE(sout.str() == "true");
    }
    SUBCASE("3/4 3/5")
    {
        Rational<int> r1(3, 4);
        Rational<int> r2(3, 5);

        sout << boolalpha << (r1 <= r2);

        REQUIRE(sout.str() == "false");
    }
}
TEST_CASE("Rationla: >= operator")
{
    ostringstream sout;

    SUBCASE("3/5 3/2")
    {
        Rational<int> r1(3, 5);
        Rational<int> r2(3, 2);

        sout << boolalpha << (r1 >= r2);

        REQUIRE(sout.str() == "false");
    }
    SUBCASE("3/5 3/5")
    {
        Rational<int> r1(3, 5);
        Rational<int> r2(3, 5);

        sout << boolalpha << (r1 >= r2);

        REQUIRE(sout.str() == "true");
    }
    SUBCASE("3/4 3/5")
    {
        Rational<int> r1(3, 4);
        Rational<int> r2(3, 5);

        sout << boolalpha << (r1 >= r2);

        REQUIRE(sout.str() == "true");
    }
}

TEST_CASE("Rational: input operator")
{
    ostringstream sout;

    SUBCASE("3/5")
    {
        istringstream sinp("3/5");
        Rational<int> r;
        sinp >> r;

        sout << r;

        REQUIRE(sout.str() == "3/5");
    }

    SUBCASE("one over two")
    {
        istringstream sinp("one over two");

        Rational<int> r;
        sinp >> r;

        REQUIRE(sinp.fail());
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }
    SUBCASE("1:3")
    {
        istringstream sinp("1:3");

        Rational<int> r;

        sinp >> r;

        REQUIRE(sinp.fail());
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }
    SUBCASE("1 /2")
    {
        istringstream sinp("1 /2");
        Rational<int> r;

        sinp >> r;

        REQUIRE(sinp.fail());
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }
    SUBCASE("1/ 2")
    {
        istringstream sinp("1/ 2");
        Rational<int> r;

        sinp >> r;

        REQUIRE(sinp.fail());
        REQUIRE(r.num() == 0);
        REQUIRE(r.den() == 1);
    }
}

TEST_CASE("Rational: getters")
{
    const Rational<int64_t> r;

    REQUIRE(r.num() == 0);
    REQUIRE(r.den() == 1);
}
