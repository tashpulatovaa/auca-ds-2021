#pragma once
#include <vector>
#include <iosfwd>
#include <string>
#include <stdexcept>

class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend std::istringstream &operator>>(std::istringstream &sin, BigInt &x);
    std::vector<int> mDigits;
    bool mIsNegative;

public:
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }

    BigInt(const std::string &strValue)
        : mIsNegative(false)
    {
        size_t i = 0;

        if (strValue[i] == '-')
        {
            if (strValue.size() == 2 && strValue[i + 1] == '0')
            {
                mIsNegative = false;
            }
            else
            {
                mIsNegative = true;
            }
            ++i;
        }
        else if (strValue[i] == '+')
        {
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