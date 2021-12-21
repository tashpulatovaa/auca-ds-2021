#ifndef VECINT_HPP
#define VECINT_HPP

#include <cstddef>
#include <iostream>
#include <stdexcept>

#ifdef AUCA_DEBUG
#include <string>
#endif

class VecInt
{
    int *data;
    size_t sz;
    size_t cp;

public:
    static size_t nOfCopies;
    using Iter = int *;
    using CIter = const int *;

    VecInt()
        : data(nullptr), sz(0), cp(0)
    {
    }
    VecInt(std::size_t aSz, int initVal = 0)
        : data(new int[aSz]), sz(aSz), cp(aSz)
    {
        for (std::size_t i = 0; i < sz; i++)
        {
            data[i] = initVal;
        }
    }

    VecInt(std::initializer_list<int> initList)
        : VecInt()
    {
        for (auto e : initList)
        {
            pushBack(e);
        }
    }

    VecInt(const VecInt &other);
    VecInt &operator=(const VecInt &other);

    //move constructor
    VecInt(VecInt &&other);

    //move assignment operator
    VecInt &operator=(VecInt &&other) noexcept;

    ~VecInt()
    {
        std::cout << "The vector of size " << sz << " was removed\n";
        delete[] data;
    }

    std::size_t size() const
    {
        return sz;
    }

    Iter begin()
    {
        return data;
    }
    CIter begin() const
    {
        return data;
    }
    Iter end()
    {
        return data + sz;
    }
    CIter end() const
    {
        return data + sz;
    }

    void pushBack(int x);
    bool operator==(const VecInt &other);

    const int &operator[](std::size_t index) const
    {
#ifdef AUCA_DEBUG
        if (sz <= index)
        {
            throw std::runtime_error("VecInt: Incorrect index: " + std::to_string(index));
        }
#endif
        return data[index];
    }
    int &operator[](std::size_t index)
    {
#ifdef AUCA_DEBUG
        if (sz <= index)
        {
            throw std::runtime_error("VecInt: Incorrect index: " + std::to_string(index));
        }
#endif
        return data[index];
    }
};

#endif