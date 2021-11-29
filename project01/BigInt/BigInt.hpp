#pragma once

#include <vector>
#include <iosfwd>
#include <string>
#include <stdexcept>

class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend std::istringstream &operator>>(std::istringstream &sin, BigInt &x);
    friend BigInt operator+(const BigInt &x, const BigInt &y);
    friend BigInt operator-(const BigInt &x, const BigInt &y);

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

    static BigInt subAbsValues(const BigInt &x, const BigInt &y)
    {
        // if(x < y)
        // {
        //     BigInt temp = x;
        //     x = y;
        //     y = temp;
        // }
        BigInt result;
        result.mDigits.clear();
        auto p = x.mDigits.rbegin();
        auto q = y.mDigits.rbegin();

        int carry = 0;

        bool firstZero = true;
        while (p != x.mDigits.rend() || q != y.mDigits.rend())
        {
            int dif = carry;
            if (p != x.mDigits.rend())
            {
                if (carry == (-1) && *p == 0 && !firstZero)
                {
                    dif = 9;
                }

                dif += *p;
                ++p;
                carry = 0;
                if (*p == 0 && !firstZero)
                {
                    carry = -1;
                }
            }
            if (q != y.mDigits.rend())
            {
                if (dif < *q)
                {
                    dif += 10;
                    carry = -1;
                }
                dif -= *q;
                ++q;
            }
            result.mDigits.push_back(dif);
            if (*p == 0 && firstZero)
            {
                firstZero = false;
            }
        }
        std::reverse(result.mDigits.begin(), result.mDigits.end());

        return result;
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
        size_t i = 0;

        if (strValue.empty())
        {
            throw std::runtime_error("BigInt: Incorrect string initializer");
        }
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
    // use 1_000_000_000 дичную систему чтобы оптимизировать код
};

inline std::istringstream &operator>>(std::istringstream &sin, BigInt &x)
{
    std::string inputString;
    sin >> inputString;

    sin >> inputString;
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
}

inline BigInt operator-(const BigInt &x, const BigInt &y)
{

    BigInt r = BigInt::subAbsValues(x, y);
    r.mIsNegative = false;
    return r;
}