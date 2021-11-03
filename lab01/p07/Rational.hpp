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
    Rational(const T &num, const T &den)
        : mNum(num), mDen(den)
    {
        if (mDen == 0)
        {
            throw std::runtime_error("Ratinal: denominator is equal to zero");
        }

        //euclid's algorithm
        T a = mNum < 0 ? -mNum : mNum;
        T b = mDen < 0 ? -mDen : mDen;
        while (b != 0)
        {
            T r = a % b;
            a = b;
            b = r;
        }

        mNum /= a;
        mDen /= a;

        if (mDen < 0)
        {
            mNum = -mNum;
            mDen = -mDen;
        }
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
Rational<T> operator+(const Rational<T> &a, const Rational<T> &b)
{
    T num = a.num() * b.den() + b.num() * a.den();
    T den = a.den() * b.den();

    return Rational<T>(num, den);
}

template <typename T>
Rational<T> operator-(const Rational<T> &a, const Rational<T> &b)
{
    T num = a.num() * b.den() - b.num() * a.den();
    T den = a.den() * b.den();

    return Rational<T>(num, den);
}

template <typename T>
Rational<T> operator*(const Rational<T> &a, const Rational<T> &b)
{
    T num = a.num() * b.num();
    T den = a.den() * b.den();

    return Rational<T>(num, den);
}

template <typename T>
Rational<T> operator/(const Rational<T> &a, const Rational<T> &b)
{
    T num = a.num() * b.den();
    T den = a.den() * b.num();

    return Rational<T>(num, den);
}
template <typename T>
bool operator<(const Rational<T> &a, const Rational<T> &b)
{
    return a.num() * b.den() < b.den() * a.den();
}

//a < b <=> b > a
template <typename T>
bool operator>(const Rational<T> &a, const Rational<T> &b)
{
    return b < a;
}

template <typename T>
bool operator==(const Rational<T> &a, const Rational<T> &b)
{
    return a.num() * b.den() == b.den() * a.den();
}

template <typename T>
bool operator!=(const Rational<T> &a, const Rational<T> &b)
{
    return !(a == b);
}

//a <= b <=> !(a > b)
template <typename T>
bool operator<=(const Rational<T> &a, const Rational<T> &b)
{
    return !(a > b);
}

template <typename T>
bool operator>=(const Rational<T> &a, const Rational<T> &b)
{
    return !(a < b);
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const Rational<T> &r)
{
    out << r.num() << "/" << r.den();

    return out;
}