#pragma once
#include <vector>
#include <iosfwd>
#include <string>
#include <stdexcept>

class BigInt
{
    friend std::ostream &operator<<(std::ostream &out, const BigInt &x);
    friend std::istringstream &operator>>(std::istringstream &sin, BigInt &x);
    friend BigInt &operator+(const BigInt &x, const BigInt &y);
    std::vector<int> mDigits;
    bool mIsNegative;

public:
    BigInt()
        : mIsNegative(false)
    {
        mDigits.push_back(0);
    }

    BigInt(int &paramNumber)
        : mIsNegative(false)
    {
        if (paramNumber == 0)
        {
            mDigits.push_back(0);
        }
        else
        {
            if (paramNumber < 0)
            {
                mIsNegative = true;
                paramNumber = -paramNumber;
            }

            while (paramNumber > 0)
            {
                mDigits.push_back(paramNumber % 10);
                paramNumber /= 10;
            }
            reverse(mDigits.begin(), mDigits.end());
        }
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

inline BigInt &operator+(const BigInt &x, const BigInt &y)
{
    // STRIGHT FORWARD SOLUTION

    BigInt sumResult;
    sumResult.mDigits = std::vector<int>(std::max((x.mDigits).size(), (y.mDigits).size()), 0);
    sumResult.mIsNegative = false;

    std::vector<int> first = x.mDigits > y.mDigits ? x.mDigits : y.mDigits;
    std::vector<int> second = y.mDigits > x.mDigits ? y.mDigits : x.mDigits;

    int minLenght = std::min((x.mDigits).size(), (y.mDigits).size());
    int maxLenght = std::max((x.mDigits).size(), (y.mDigits).size());

    for (int i = first.size() - 1, j = second.size() - 1; i >= 0; i--, j--)
    {
        if (j >= 0)
        {
            if (first[i] + second[j] >= 10)
            {
                sumResult.mDigits[i] += (first[i] + second[j]) % 10;
                sumResult.mDigits[i - 1] += 1;
            }
            else
            {
                sumResult.mDigits[i] = first[i] + second[j];
            }
        }
        else
        {
            sumResult.mDigits[i] = first[i];
        }
    }

    //if they are equal;
    //consider signs too
    // }
    return sumResult;
}