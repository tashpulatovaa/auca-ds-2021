#pragma once
#include <vector>
#include <iosfwd>
#include <string>

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
            if (isdigit(strValue[i]))
            {
                mDigits.push_back(strValue[i] - '0');
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