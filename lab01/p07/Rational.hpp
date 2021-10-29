#pragma once

#include <iosfwd>

template <typename T>
class Rational
{

    T mNum;
    T mDen;

public:
    Rational()
        : mNum(0), mDen(1)
    {
    }

    const T &num() const
    {
        return mNum;
    }
    const T &den() const
    {
        return mDen;
    }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const Rational<T> &r)
{
    out << r.num() << "/" << r.den();

    return out;
}