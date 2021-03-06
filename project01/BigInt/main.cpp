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

TEST_CASE("BigInt input operator")
{
    SUBCASE("123")
    {
        istringstream sinp("123");
        BigInt x;
        sinp >> x;
        REQUIRE(x == 123);

        bool state = static_cast<bool>(sinp);
        REQUIRE(state);
    }

    SUBCASE("   -123")
    {
        istringstream sinp("   -123");
        BigInt x;
        sinp >> x;
        REQUIRE(x == -123);

        bool state = static_cast<bool>(sinp);
        REQUIRE(state);
    }

    SUBCASE("-  123")
    {
        istringstream sinp("-  123");
        BigInt x;
        sinp >> x;
        bool state = static_cast<bool>(sinp);
        REQUIRE_FALSE(state);
    }

    SUBCASE("   ")
    {
        istringstream sinp("   ");
        BigInt x;
        sinp >> x;
        bool state = static_cast<bool>(sinp);
        REQUIRE_FALSE(state);
    }

    SUBCASE("   X")
    {
        istringstream sinp("    X");
        BigInt x;
        sinp >> x;
        bool state = static_cast<bool>(sinp);
        REQUIRE_FALSE(state);
        sinp.clear();
        char ch;
        sinp >> ch;
        REQUIRE(ch == 'X');
    }

    SUBCASE("-")
    {
        istringstream sinp("-");
        BigInt x;
        sinp >> x;
        bool state = static_cast<bool>(sinp);
        REQUIRE_FALSE(state);
    }

    SUBCASE("123+123")
    {
        istringstream sinp("123+123");
        BigInt x;
        sinp >> x;
        REQUIRE(x == 123);
        string rest;
        getline(sinp, rest);
        bool state = static_cast<bool>(sinp);
        REQUIRE(state);
        REQUIRE(rest == "+123");
    }

    SUBCASE("1 + 2 + 3 + 4 + 5")
    {
        istringstream sinp("1 2 3 4 5");
        BigInt r;
        for (int x; sinp >> x;)
        {
            r += x;
        }

        REQUIRE(r == 15);
        REQUIRE(sinp.eof());
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
    SUBCASE("Case 4: -123 + (-123)")
    {
        BigInt x("-123");
        BigInt y("-123");

        BigInt sum = x + y;

        sout << sum;

        REQUIRE(sout.str() == "-246");
    }
    SUBCASE("Case 5: -3 + 3")
    {
        BigInt x(-3);
        BigInt y(3);

        sout << x + y;

        REQUIRE(sout.str() == "0");
    }

    // SUBCASE("Case 4: [-500, 500]")
    // {
    //     for (int i = -500; i < 500; i++)
    //     {
    //         for (int j = -500; j < 500; j++)
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

// SUBTRACTION OPERATOR TESTS

TEST_CASE("BigInt: '-' operator")
{
    std::ostringstream sout;

    // SUBCASE("10 - 3")
    // {
    //     BigInt x(10);
    //     BigInt y(3);

    //     sout << x - y;

    //     REQUIRE(sout.str() == "7");
    // }
    // SUBCASE("3 - 10")
    // {
    //     BigInt x(3);
    //     BigInt y(10);

    //     sout << x - y;

    //     REQUIRE(sout.str() == "-7");
    // }
    // SUBCASE("-10 - 3")
    // {
    //     BigInt x(-10);
    //     BigInt y(3);

    //     sout << x - y;

    //     REQUIRE(sout.str() == "-13");
    // }
    // SUBCASE("-3 - 10")
    // {
    //     BigInt x(-3);
    //     BigInt y(10);

    //     sout << x - y;

    //     REQUIRE(sout.str() == "-13");
    // }
    // SUBCASE("-10 - (-3")
    // {
    //     BigInt x(-10);
    //     BigInt y(-3);

    //     sout << x - y;

    //     REQUIRE(sout.str() == "-7");
    // }
    // SUBCASE("-3 - (-10)")
    // {
    //     BigInt x(-3);
    //     BigInt y(-10);

    //     sout << x - y;

    //     REQUIRE(sout.str() == "7");
    // }
    // SUBCASE("Case 4: [-500, 500]")
    // {
    //     for (int i = -500; i < 500; i++)
    //     {
    //         for (int j = -500; j < 500; j++)
    //         {
    //             BigInt x = i;
    //             BigInt y = j;

    //             ostringstream sout2;
    //             sout2 << x - y;
    //             REQUIRE(sout2.str() == to_string(i - j));
    //         }
    //     }
    // }
}

// LESS THAN OPERATOR

TEST_CASE("BigInt: '<' operator ")
{
    std::ostringstream sout;
    // SUBCASE("10 < 4")
    // {
    //     BigInt x(10);
    //     BigInt y(4);

    //     sout << boolalpha << (x < y);

    //     REQUIRE(sout.str() == "false");
    // }
    // SUBCASE("10 < 4")
    // {
    //     BigInt x(10);
    //     BigInt y(4);

    //     sout << boolalpha << (x < y);

    //     REQUIRE(sout.str() == "false");
    // }
    // SUBCASE("4 < 10")
    // {
    //     BigInt x(4);
    //     BigInt y(10);

    //     sout << boolalpha << (x < y);

    //     REQUIRE(sout.str() == "true");
    // }
    // SUBCASE("-10 < 4")
    // {
    //     BigInt x(-10);
    //     BigInt y(4);

    //     sout << boolalpha << (x < y);

    //     REQUIRE(sout.str() == "true");
    // }
    // SUBCASE("-4 < 10")
    // {
    //     BigInt x(-4);
    //     BigInt y(10);

    //     sout << boolalpha << (x < y);

    //     REQUIRE(sout.str() == "true");
    // }
    // SUBCASE("-10 < -4")
    // {
    //     BigInt x(-10);
    //     BigInt y(-4);

    //     sout << boolalpha << (x < y);

    //     REQUIRE(sout.str() == "true");
    // }
    // SUBCASE("-4 < -10")
    // {
    //     BigInt x(-4);
    //     BigInt y(-10);

    //     sout << boolalpha << (x < y);

    //     REQUIRE(sout.str() == "false");
    // }
    SUBCASE("-10000000000 < -9999999999")
    {
        BigInt x(-10000000000);
        BigInt y(-9999999999);

        sout << boolalpha << (x < y);

        REQUIRE(sout.str() == "true");
    }
}

// GREATER THAN OPERATOR TEST

TEST_CASE("BigInt: '>' operator ")
{
    std::ostringstream sout;
    SUBCASE("-10000000000 < -9999999999")
    {
        BigInt x(-10000000000);
        BigInt y(-9999999999);

        sout << boolalpha << (x > y);

        REQUIRE(sout.str() == "false");
    }
}

// EQUAL TO OPERATOR TEST

TEST_CASE("BigInt: '==' operator ")
{
    std::ostringstream sout;

    SUBCASE("-10000000000 == -10000000000")
    {
        BigInt x(-10000000000);
        BigInt y(-10000000000);

        sout << boolalpha << (x == y);

        REQUIRE(sout.str() == "true");
    }
    SUBCASE("-10000000000 == 10000000000")
    {
        BigInt x(-10000000000);
        BigInt y(10000000000);

        sout << boolalpha << (x == y);

        REQUIRE(sout.str() == "false");
    }
    SUBCASE("10000000000 == 10000000000")
    {
        BigInt x(10000000000);
        BigInt y(10000000000);

        sout << boolalpha << (x == y);

        REQUIRE(sout.str() == "true");
    }
}

// NOT EQUAL TO OPERATOR

TEST_CASE("BigInt: '!=' operator ")
{
    std::ostringstream sout;

    SUBCASE("-10000000000 != -10000000000")
    {
        BigInt x(-10000000000);
        BigInt y(-10000000000);

        sout << boolalpha << (x != y);

        REQUIRE(sout.str() == "false");
    }
    SUBCASE("-10000000000 != 10000000000")
    {
        BigInt x(-10000000000);
        BigInt y(10000000000);

        sout << boolalpha << (x != y);

        REQUIRE(sout.str() == "true");
    }
}

// GREATER THAN OR EQUAL TO OPERATOR TEST

TEST_CASE("BigInt: '>=' operator ")
{
    std::ostringstream sout;

    SUBCASE("-10000000000 >= -10000000000")
    {
        BigInt x(-10000000000);
        BigInt y(-10000000000);

        sout << boolalpha << (x >= y);

        REQUIRE(sout.str() == "true");
    }
    SUBCASE("-10000000000 >= 10000000000")
    {
        BigInt x(-10000000000);
        BigInt y(10000000000);

        sout << boolalpha << (x >= y);

        REQUIRE(sout.str() == "false");
    }
}

//LESS THAN OR EQUAL TO OPERATOR

TEST_CASE("BigInt: '<=' operator ")
{
    std::ostringstream sout;

    SUBCASE("-10 <= -10")
    {
        BigInt x(-10);
        BigInt y(-10);

        sout << boolalpha << (x <= y);

        REQUIRE(sout.str() == "true");
    }
    SUBCASE("-10000000000 <= 10000000000")
    {
        BigInt x(-10000000000);
        BigInt y(10000000000);

        sout << boolalpha << (x <= y);

        REQUIRE(sout.str() == "true");
    }
}

TEST_CASE("BigInt: '*' operator ")
{
    std::ostringstream sout;

    SUBCASE("3 * 4")
    {
        BigInt x(3);
        BigInt y(4);

        sout << (x * y);

        REQUIRE(sout.str() == "12");
    }
    SUBCASE("-30 * -4")
    {
        BigInt x(-30);
        BigInt y(-4);

        sout << (x * y);

        REQUIRE(sout.str() == "120");
    }
    SUBCASE("-499 * 499")
    {
        BigInt x(499);
        BigInt y(499);

        sout << (x * y);

        REQUIRE(sout.str() == "249001");
    }
    SUBCASE("0 * -4000")
    {
        BigInt x(0);
        BigInt y(-4000);

        sout << (x * y);

        REQUIRE(sout.str() == "0");
    }
    SUBCASE("123456 * 234567")
    {
        BigInt x(123456);
        BigInt y(234567);

        sout << (x * y);

        REQUIRE(sout.str() == "28958703552");
    }
    // SUBCASE("Case 4: [-500, 500]")
    // {
    //     for (int i = -500; i < 500; i++)
    //     {
    //         for (int j = -500; j < 500; j++)
    //         {
    //             BigInt x(i);
    //             BigInt y(j);
    //             ostringstream sout2;
    //             sout2 << x * y;
    //             REQUIRE(sout2.str() == to_string(i * j));
    //         }
    //     }
    // }
}

TEST_CASE("BigInt: '/' operator ")
{
    std::ostringstream sout;

    SUBCASE("-10 / 5")
    {
        BigInt x(-10);
        BigInt y(5);

        sout << (x / y);

        REQUIRE(sout.str() == "-2");
    }
    SUBCASE("100 / -100")
    {
        BigInt x(100);
        BigInt y(-100);

        sout << (x / y);

        REQUIRE(sout.str() == "-1");
    }

    SUBCASE("-123 / -11")
    {
        BigInt x(-123);
        BigInt y(-11);

        sout << (x / y);

        REQUIRE(sout.str() == "11");
    }
    SUBCASE("23 / -100")
    {
        BigInt x(23);
        BigInt y(-100);

        sout << (x / y);

        REQUIRE(sout.str() == "0");
    }
    SUBCASE("23 / 0")
    {
        BigInt x(23);
        BigInt y(0);

        REQUIRE_THROWS_AS(x / y, runtime_error);
    }

    SUBCASE("Case 4: [-500, 500]")
    {
        for (int i = -500; i < 500; i++)
        {
            for (int j = -500; j < 500; j++)
            {
                if (j == 0)
                {
                    continue;
                }
                BigInt x(i);
                BigInt y(j);
                ostringstream sout2;
                cout << i << " " << j << "\n";
                sout2 << x / y;
                REQUIRE(sout2.str() == to_string(i / j));
            }
        }
    }
}

// TEST_CASE("BigInt: '%' operator ")
// {
//     std::ostringstream sout;

//     SUBCASE("-10 % 5")
//     {
//         BigInt x(-10);
//         BigInt y(5);

//         sout << (x % y);

//         REQUIRE(sout.str() == "0");
//     }
//     SUBCASE("10 % 7")
//     {
//         BigInt x(10);
//         BigInt y(7);

//         sout << (x % y);

//         REQUIRE(sout.str() == "3");
//     }

//     SUBCASE("-123 % -11")
//     {
//         BigInt x(-123);
//         BigInt y(-11);

//         sout << (x % y);

//         REQUIRE(sout.str() == "-2");
//     }
//     SUBCASE("3 % 5")
//     {
//         BigInt x(3);
//         BigInt y(5);

//         sout << (x % y);

//         REQUIRE(sout.str() == "3");
//     }
//     SUBCASE("23 % 0")
//     {
//         BigInt x(23);
//         BigInt y(0);

//         REQUIRE_THROWS_AS(x / y, runtime_error);
//     }

//     SUBCASE("Case 4: [-500, 500]")
//     {
//         for (int i = -500; i < 500; i++)
//         {
//             for (int j = -500; j < 500; j++)
//             {
//                 if (j == 0)
//                 {
//                     continue;
//                 }
//                 BigInt x(i);
//                 BigInt y(j);
//                 ostringstream sout2;
//                 sout2 << x % y;
//                 std::cout << x << "  " << y << " " << sout2.str() << endl;
//                 REQUIRE(sout2.str() == to_string(i % j));
//             }
//         }
//     }
// }

TEST_CASE("BigInt increment")
{
    SUBCASE("CASE 1")
    {
        BigInt t(1);
        BigInt b;
        ostringstream sout2;
        b = t++;
        sout2 << b;
        REQUIRE(sout2.str() == "1");
    }

    SUBCASE("CASE 2")
    {
        BigInt t("1");
        BigInt b;
        ostringstream sout2;
        b = ++t;
        sout2 << b;
        REQUIRE(sout2.str() == "2");
    }
}
