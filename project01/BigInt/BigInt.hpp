#pragma once

#include <vector>
#include <iosfwd>
#include <string>
#include <stdexcept>

#define BASE 10

class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend std::istringstream &operator>>(std::istringstream &sin, BigInt &x);
    friend BigInt abs(BigInt x);
    friend BigInt operator+(const BigInt &x, const BigInt &y);
    friend BigInt operator-(const BigInt &x, const BigInt &y);
    friend BigInt operator*(const BigInt &x, const BigInt &y);
    friend BigInt operator*(const BigInt &x, int y);
    friend BigInt operator/(const BigInt &x, const BigInt &y);
    //friend void operator=(BigInt &x, BigInt &y);
    friend void operator+=(BigInt &x, const BigInt &y);
    friend void operator-=(BigInt &x, const BigInt &y);
    friend bool operator<(const BigInt &x, const BigInt &y);
    friend bool operator>(const BigInt &x, const BigInt &y);
    friend bool operator==(const BigInt &x, const BigInt &y);
    friend bool operator!=(const BigInt &x, const BigInt &y);
    friend bool operator<=(const BigInt &x, const BigInt &y);
    friend bool operator>=(const BigInt &x, const BigInt &y);

    std::vector<int> mDigits;
    bool mIsNegative;

    static BigInt addAbsValues(const BigInt &x, const BigInt &y)
    {
        BigInt result;
        result.mDigits.clear();
        auto p = x.mDigits.rbegin();
        auto q = y.mDigits.rbegin();

        int carry = 0;

        while (p != x.mDigits.rend() || q != y.mDigits.rend())
        {
            int sum = carry;
            if (p != x.mDigits.rend())
            {
                sum += *p;
                ++p;
            }
            if (q != y.mDigits.rend())
            {
                sum += *q;
                ++q;
            }
            result.mDigits.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry != 0)
        {
            result.mDigits.push_back(carry);
        }
        std::reverse(result.mDigits.begin(), result.mDigits.end());

        return result;
    }

    static BigInt subAbsValues(const BigInt &a, const BigInt &b)
    {
        BigInt r;
        r.mDigits.clear();

        auto i = a.mDigits.rbegin();
        auto j = b.mDigits.rbegin();

        int borrow = 0;
        while (i != a.mDigits.rend())
        {
            int dif = *i - borrow;
            ++i;

            if (j != b.mDigits.rend())
            {
                dif -= *j;
                ++j;
            }

            if (dif < 0)
            {
                dif += 10;
                borrow = 1;
            }
            else
            {
                borrow = 0;
            }

            r.mDigits.push_back(dif);
        }

        while (r.mDigits.size() > 1 && r.mDigits.back() == 0)
        {
            r.mDigits.pop_back();
        }

        std::reverse(r.mDigits.begin(), r.mDigits.end());
        return r;
    }

    static BigInt mulAbsValues(const BigInt &x, const BigInt &y)
    {
        BigInt r;
        r.mDigits.resize(x.mDigits.size() + y.mDigits.size());

        auto j = y.mDigits.rbegin();
        auto i = x.mDigits.rbegin();
        int shift = 0;
        int carry, curShift;

        for (; j != y.mDigits.rend(); j++)
        {
            carry = 0;
            curShift = shift;

            for (; i != x.mDigits.rend(); i++)
            {
                int s = *i * *j + carry;
                BigInt::addDigit(r, s % 10, curShift);
                carry = s / 10;
                curShift++;
            }
            if (carry != 0)
            {
                BigInt::addDigit(r, carry, curShift);
            }
            shift++;

            i = x.mDigits.rbegin();
        }

        if (r.mDigits.front() == 0)
        {
            r.mDigits.erase(r.mDigits.begin());
        }
        return r;
    }

    static void addDigit(BigInt &r, int d, int shift)
    {
        int carry = 0;
        auto i = r.mDigits.rbegin();
        i += shift;
        int sum = *i + d;
        *i = sum % 10;
        carry = sum / 10;

        while (carry != 0)
        {
            sum = 0;
            ++i;
            sum += (*i + carry);
            *i = sum % 10;
            carry = sum / 10;
        }
        if (carry != 0)
        {
            *(i + shift) = carry;
        }
    }

    static BigInt divAbsValues(const BigInt &x, const BigInt &y)
    {
        BigInt r;
        r.mDigits.clear();

        auto i = x.mDigits.begin();
        BigInt divident;
        divident.mDigits.clear();

        while (i != x.mDigits.end())
        {
            int count = 0;
            while (divident < y && i < x.mDigits.end())
            {
                divident.mDigits.push_back(*i);
                if (divident == BigInt("0"))
                {
                    divident.mDigits.clear();
                    r.mDigits.push_back(0);
                    i++;
                    continue;
                }
                i++;
                count++;
                if (count > (int)y.mDigits.size())
                {
                    r.mDigits.push_back(0);
                }
            }
            if (divident == BigInt("0") || divident.mDigits.empty())
            {
                break;
            }
            std::pair<int, BigInt> quotientRemainder = BigInt::findQuotientRemainder(divident, abs(y));
            r.mDigits.push_back(quotientRemainder.first);
            divident.mDigits = (quotientRemainder.second).mDigits;
            if (divident == BigInt("0"))
            {
                divident.mDigits.clear();
            }
        }
        if (r.mDigits.front() == 0 && r.mDigits.size() != 1)
        {
            r.mDigits.erase(r.mDigits.begin(), r.mDigits.begin() + 1);
        }
        return r;
    }

    static std::pair<int, BigInt> findQuotientRemainder(const BigInt &divident, const BigInt &divisor)
    {
        int r = 0;
        for (int i = 0; i <= 10; i++)
        {
            if (divisor * i > divident)
            {
                r = i;
                break;
            }
        }
        return {r - 1, divident - (divisor * (r - 1))};

        // BINARY_SEARCH APPROACH

        // int r = 5;
        // int remainder;
        // bool increses = (divisor * 5 > divident) ? false : true;

        // for (; (r > 0 && r < 10);)
        // {
        //     (increses) ? r++ : r--;

        //     if (divisor * 5 == divident)
        //     {
        //         return {5, BigInt()};
        //     }
        //     if (r < 5 && divisor * r <= divident)
        //     {
        //         return {r, divident - divisor * r};
        //     }
        //     if (r > 5 && (divisor * r >= divident))
        //     {
        //         return {(r - 1), (divident - divisor * r)};
        //     }
        // }
        // return {0, BigInt()};
    }

    static int cmpAbsValues(const BigInt &a, const BigInt &b)
    {
        if (a.mDigits.size() > b.mDigits.size())
        {
            return 1;
        }

        if (a.mDigits.size() < b.mDigits.size())
        {
            return -1;
        }

        for (size_t i = 0; i < a.mDigits.size(); ++i)
        {
            if (a.mDigits[i] != b.mDigits[i])
            {
                return a.mDigits[i] - b.mDigits[i];
            }
        }

        return 0;
    }

public:
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }

    BigInt(long long x)
        : BigInt(std::to_string(x))
    {
    }

    explicit BigInt(const std::string &strValue)
        : mIsNegative(false)
    {
        if (strValue.empty())
        {
            throw std::runtime_error("BigInt: Incorrect string initializer");
        }

        size_t i = 0;
        if (strValue[i] == '-' || strValue[i] == '+')
        {
            mIsNegative = strValue[i] == '-';
            ++i;
        }

        while (i + 1 != strValue.size() && strValue[i] == '0')
        {
            ++i;
        }

        for (; i != strValue.size(); i++)
        {
            if (!isdigit(strValue[i]))
            {
                if (strValue[i] == '_')
                {
                    continue;
                }
                else
                {
                    throw std::runtime_error("BigInt cannot be initialized by non-digit character");
                }
            }
            mDigits.push_back(strValue[i] - '0');
        }
        if (mDigits.empty())
        {
            throw std::runtime_error("Incorrect string initializer");
        }
        if (mDigits.size() == 1 && mDigits.front() == 0)
        {
            mIsNegative = false;
        }
    }

    // temporary solution
    void operator=(const BigInt &otherBigInt)
    {
        mDigits = otherBigInt.mDigits;
        mIsNegative = otherBigInt.mIsNegative;
    }
};

inline std::istringstream &operator>>(std::istringstream &sin, BigInt &x)
{
    std::string inputString;
    getline(sin, inputString);

    BigInt y(inputString);
    x = y;

    return sin;
}

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    if (x.mIsNegative)
    {
        out << '-';
    }

    for (auto digit : x.mDigits)
    {
        out << digit;
    }
    return out;
}

inline BigInt operator+(const BigInt &x, const BigInt &y)
{
    if (x.mIsNegative == y.mIsNegative)
    {
        BigInt r = BigInt::addAbsValues(x, y);
        r.mIsNegative = x.mIsNegative;
        return r;
    }
    int cmp = BigInt::cmpAbsValues(x, y);
    if (cmp == 0)
    {
        return BigInt();
    }
    if (cmp > 0)
    {
        BigInt r = BigInt::subAbsValues(x, y);
        r.mIsNegative = x.mIsNegative;
        return r;
    }

    BigInt r = BigInt::subAbsValues(y, x);
    r.mIsNegative = y.mIsNegative;
    return r;
}

inline BigInt operator-(const BigInt &x, const BigInt &y)
{
    // (5) - (-3) -> 5 + 3

    if (!(x.mIsNegative) && y.mIsNegative)
    {
        BigInt r = BigInt::addAbsValues(x, y);
        r.mIsNegative = false;
        return r;
    }

    // (-5) - (3) -> -(5+3)

    if (x.mIsNegative && !(y.mIsNegative))
    {
        BigInt r = BigInt::addAbsValues(x, y);
        r.mIsNegative = true;
        return r;
    }

    // 5 - 3 -> 2
    // 3 - 5 -> (-2)
    // (-5) - (-3) -> (-5) + 3 -> (-2);
    // (-3) - (-5) -> (-3) + 5 -> 2;

    if (x.mIsNegative == y.mIsNegative)
    {
        int cmp = BigInt::cmpAbsValues(x, y);
        if (cmp == 0)
        {
            return BigInt();
        }
        else if (cmp > 0)
        {
            BigInt r = BigInt::subAbsValues(x, y);
            r.mIsNegative = x.mIsNegative;
            return r;
        }
        else
        {
            BigInt r = BigInt::subAbsValues(y, x);
            r.mIsNegative = !y.mIsNegative;
            return r;
        }
    }

    return BigInt();
}

inline bool operator<(const BigInt &x, const BigInt &y)
{
    if (x.mIsNegative && !(y.mIsNegative))
    {
        return true;
    }
    if (!(x.mIsNegative) && y.mIsNegative)
    {
        return false;
    }
    if (!(x.mIsNegative) && !(y.mIsNegative))
    {
        return (BigInt::cmpAbsValues(x, y)) < 0;
    }

    return (BigInt::cmpAbsValues(x, y)) > 0;
}

inline bool operator>(const BigInt &x, const BigInt &y)
{
    if (x == y)
    {
        return false;
    }
    return !((x < y));
}

inline bool operator==(const BigInt &x, const BigInt &y)
{
    if (x.mIsNegative == y.mIsNegative)
    {
        return (BigInt::cmpAbsValues(x, y) == 0);
    }

    return false;
}

inline bool operator!=(const BigInt &x, const BigInt &y)
{
    return !(x == y);
}

inline bool operator>=(const BigInt &x, const BigInt &y)
{
    return !(x < y);
}
inline bool operator<=(const BigInt &x, const BigInt &y)
{
    return !(x > y);
}

inline BigInt operator*(const BigInt &x, const BigInt &y)
{

    if (x == 0 || y == 0)
    {
        return BigInt();
    }

    BigInt r(BigInt::mulAbsValues(x, y));

    r.mIsNegative = (x.mIsNegative == y.mIsNegative) ? false : true;

    return r;
}

inline void operator+=(BigInt &x, const BigInt &y)
{
    x = x + y;
}
inline void operator-=(BigInt &x, const BigInt &y)
{
    x = x - y;
}

BigInt abs(const BigInt x)
{
    //x.mIsNegative = false;
    BigInt y;
    y.mDigits = x.mDigits;
    y.mIsNegative = false;
    return y;
}

inline BigInt operator/(const BigInt &x, const BigInt &y)
{
    if (y == 0)
    {
        throw std::runtime_error("Impossible to divide to 0");
    }

    BigInt r = (BigInt::divAbsValues(abs(x), abs(y)));

    if (r != 0)
    {
        r.mIsNegative = (x.mIsNegative == y.mIsNegative) ? false : true;
    }
    return r;
}

inline BigInt operator*(const BigInt &x, int y)
{
    // temporary implimaentation without optimization

    BigInt yb(y);
    return x * yb;
}