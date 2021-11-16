#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../../doctest/doctest.h"
#include <sstream>
#include <stdexcept>

#include <vector>

using namespace std;

template <typename T>
int sz(const T &n)
{
    return static_cast<int>(n.size());
}

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
TEST_CASE("vector's move assignment")
{
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    vector<int> v1(5, 1);

    v1 = move(v);

    REQUIRE(v.empty());
    REQUIRE(v1.size() == 3);
    REQUIRE(v1[0] == 1);
    REQUIRE(v1[1] == 2);
    REQUIRE(v1[2] == 3);
}

TEST_CASE("Vector's subsrcript operator")
{
    vector<int> v(3);
    v[0] = 10;

    REQUIRE(v[0] == 10);
}

TEST_CASE("Vector's at operator")
{
    vector<int> v(3, 5);

    REQUIRE_THROWS_AS(v.at(3), exception);
}

TEST_CASE("Vector's push_back method")
{
    vector<int> v(3);
    v[0] = 2;
    v[1] = 4;
    v[2] = 8;

    v.push_back(5);

    REQUIRE(v[3] == 5);
}
TEST_CASE("Vector's pop_back method")
{
    vector<int> v(3);
    v[0] = 2;
    v[1] = 4;
    v[2] = 8;

    v.pop_back();

    REQUIRE(v[sz(v) - 1] == 4);
}

TEST_CASE("For each construct with vector")
{
    vector<int> v(3);
    v[0] = 1;
    v[1] = 2;
    v[2] = 3;

    ostringstream sout;

    for (int num : v)
    {
        sout << num;
    }

    REQUIRE(sout.str() == "123");
}

TEST_CASE("front() and back() methods with vector")
{
    vector<string> v(3);
    v[0] = "A";
    v[1] = "B";
    v[2] = "C";

    REQUIRE(v.front() == "A");
    REQUIRE(v.back() == "C");
}

struct Student
{
    string name;
    int birthYear;
};

TEST_CASE("Vector<T>::iterators")
{

    SUBCASE("*it")
    {
        vector<int> v = {2, 3, 4};
        auto it = v.begin();
        auto it2 = v.end() - 1;

        REQUIRE(*it == 2);
        REQUIRE(*it2 == 4);
    }

    SUBCASE("it->fieldMember")
    {
        vector<Student> students = {{"Bob", 2009}, {"Alice", 2001}};

        auto it = students.begin();

        REQUIRE((*it).birthYear == 2009);
        REQUIRE(it->name == "Bob");

        auto it2 = students.end() - 1;

        REQUIRE(it2->birthYear == 2001);
        REQUIRE(it2->name == "Alice");
    }

    SUBCASE("--it and ++it")
    {
        vector<int> v = {1, 2, 3, 4};
        auto it1 = v.end();
        --it1;
        REQUIRE(*it1 == 4);

        auto it2 = v.begin();
        ++it2;
        REQUIRE(*it2 == 2);

        vector<int> v1 = {1, 2, 3, 4};
        auto it3 = v1.end() - 1;
        REQUIRE(*it3-- == 4);

        auto it4 = v1.begin();
        REQUIRE(*it4++ == 1);
    }

    SUBCASE("insert() and erase() methods")
    {
        vector<int> v = {1, 2, 3, 4, 5};
        v.insert(v.begin(), 0);

        REQUIRE(v[0] == 0);

        vector<int> v1 = {7, 8};
        v.insert(v.begin(), v1.begin(), v1.end());
        REQUIRE(containerToStr(v) == "{7, 8, 0, 1, 2, 3, 4, 5}");

        v.erase(v.begin());
        REQUIRE(v[0] == 8);

        v.erase(v.begin(), v.end());
        REQUIRE(v.empty() == true);
    }

    SUBCASE("Vector constructor(begin, end)")
    {
        vector<int> v1 = {1, 2, 4};
        vector<int> v2(v1.begin(), v1.end());

        REQUIRE(sz(v2) == 3);
        REQUIRE(v2[2] == 4);
    }
}

TEST_CASE("vector's reverse operator")
{
    vector<int> v = {1, 2, 3};
    reverse(v.begin(), v.end());

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

TEST_CASE("min_element algorithm")
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    REQUIRE(*(min_element(v.begin(), v.end())) == 1);
    REQUIRE(*(max_element(v.begin(), v.end())) == 9);
}