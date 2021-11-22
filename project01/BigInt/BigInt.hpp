#pragma once
#include <vector>
#include <iosfwd>
#include <string>
#include <stdexcept>

class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    std::vector<int> mDigits;
    bool isNegative;

public:
    BigInt()
        : isNegative(false)
    {
        mDigits.push_back(0);
    }

    BigInt(const std::string &strValue)
        : isNegative(false)
    {
        size_t i = 0;

        if (strValue[i] == '-' || strValue[i] == '+')
        {
            isNegative = strValue[i];
            ++i;
        }

        for (; i != strValue.size(); i++)
        {
            if (!isdigit(strValue[i]))
            {
                throw std::runtime_error("BigInt cannot be initialized by non-digit character");
            }
            mDigits.push_back(strValue[i] - '0');
            if (mDigits.empty())
            {
                throw std::runtime_error("Incorrect string initializer");
            }
        }
    }
};

inline std::ostream &operator<<(std::ostream &out, const BigInt &x)
{
    if (x.isNegative)
    {
        out << '-';
    }

    for (auto digit : x.mDigits)
    {
        out << digit;
    }
    return out;
}