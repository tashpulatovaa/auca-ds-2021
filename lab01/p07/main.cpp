#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"

#include "Rational.hpp"

#include <cstdint>
#include <sstream>

using namespace std;

TEST_CASE("Rational: default constructor")
{
    int x;

    Rational<int> r;

    ostringstream sout;
    sout << r;

    REQUIRE(sout.str() == "0/1");
}

TEST_CASE("Rational: getters")
{
    const Rational<int64_t> r;

    REQUIRE(r.num() == 0);
    REQUIRE(r.den() == 1);
}
