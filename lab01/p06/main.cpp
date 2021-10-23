#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include <sstream>
#include <stdexcept>

#include <vector>

using namespace std;

template <typename Container>
string containerToStr(const Container &c)
{
    ostringstream sinp;

    sinp << "{";

    bool isFirst = true;
    for (const auto &e : c)
    {
        if (!isFirst)
        {
            sinp << ", ";
        }

        sinp << e;
        isFirst = false;
    }

    sinp << "}";

    return sinp.str();
}

TEST_CASE("vector's default constructor")
{
    vector<int> v;

    REQUIRE(v.size() == 0);
    REQUIRE(v.capacity() == 0);
    REQUIRE(v.empty());
}

TEST_CASE("vectror's constructor with size")
{
    vector<int> v(5);

    REQUIRE(v.size() == 5);
    REQUIRE(v[0] == 0);
    REQUIRE(v[1] == 0);
    REQUIRE(v[2] == 0);
    REQUIRE(v[3] == 0);
    REQUIRE(v[4] == 0);

    vector<string> v2(3);

    REQUIRE(v2.size() == 3);
    REQUIRE(v2[0].empty());
    REQUIRE(v2[1].empty());
    REQUIRE(v2[2].empty());
}

TEST_CASE("vectror's constructor with size and initial value")
{
    vector<int> v3(3, 42);

    REQUIRE(v3.size() == 3);
    REQUIRE(v3[0] == 42);
    REQUIRE(v3[1] == 42);
    REQUIRE(v3[2] == 42);
}

TEST_CASE("vector's copy constructor")
{
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    vector<int> v2 = v;
    v[1] = 1000;

    REQUIRE(v2[1] != v[1]);
    REQUIRE(v2[1] == 2);
}

TEST_CASE("vector's move constructor")
{
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    vector<int> v2 = move(v);

    REQUIRE(v.empty());
    REQUIRE(v2.size() == 3);
    REQUIRE(v2[0] == 1);
    REQUIRE(v2[1] == 2);
    REQUIRE(v2[2] == 3);
}

TEST_CASE("Vector assignment operator")
{
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    vector<int> v2(2);
    v2[0] = 10;
    v2[1] = 20;

    v2 = v;

    REQUIRE(v2.size() == 3);
    REQUIRE(containerToStr(v2) == "{1, 2, 3}");

    v[1] = 1000;

    REQUIRE(containerToStr(v) == "{1, 1000, 3}");
    REQUIRE(containerToStr(v2) == "{1, 2, 3}");
}

TEST_CASE("vector's at operator")
{
    vector<int> v = {10, 20, 30};

    REQUIRE_THROWS_AS(v.at(3), out_of_range);
}

TEST_CASE("vector's reverse operator")
{
    vector<int> v = {1, 2, 3};
    std::reverse(v.begin(), v.end());

    REQUIRE(containerToStr(v) == "{3, 2, 1}");
}

TEST_CASE("vector's sort operator")
{
    vector<int> v = {5, 2, 3};
    std::sort(v.begin(), v.end());

    REQUIRE(containerToStr(v) == "{2, 3, 5}");
}

TEST_CASE("Vector's binary search algorithm")
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    bool exists = std::binary_search(v.begin(), v.end(), 9);

    REQUIRE(exists == true);
}
