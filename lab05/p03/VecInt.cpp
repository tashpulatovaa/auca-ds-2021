#include "VecInt.hpp"

size_t VecInt::nOfCopies;

VecInt::VecInt(const VecInt &other)
    : data(new int[other.cp]), sz(other.sz), cp(other.cp)
{
    for (size_t i = 0; i < sz; ++i)
    {
        ++nOfCopies;
        data[i] = other.data[i];
    }
}

VecInt &VecInt::operator=(const VecInt &other)
{
    if (&other != this)
    {
        int *newData = new int[other.cp];
        for (size_t i = 0; i < other.sz; ++i)
        {
            ++nOfCopies;
            newData[i] = other.data[i];
        }

        delete[] data;
        sz = other.sz;
        cp = other.cp;
        data = newData;
    }

    return *this;
}

//move constructor
VecInt::VecInt(VecInt &&other)
    : data(other.data), sz(other.sz), cp(other.cp)
{
    other.data = nullptr;
    other.sz = 0;
    other.cp = 0;
}

//move assignment operator
VecInt &VecInt::operator=(VecInt &&other) noexcept
{
    if (&other != this)
    {
        delete[] data;
        data = other.data;
        sz = other.sz;
        cp = other.cp;
        other.data = nullptr;
        other.sz = 0;
        other.cp = 0;
    }
    return *this;
}

void VecInt::pushBack(int x)
{
    if (sz == cp)
    {
        cp = (cp == 0) ? 1 : 2 * cp;
        int *newData = new int[cp];

        for (size_t i = 0; i < sz; i++)
        {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
    }

    data[sz++] = x;
}

bool VecInt::operator==(const VecInt &other)
{
    if (sz != other.sz)
    {
        return false;
    }
    for (size_t i = 0; i < other.sz; i++)
    {
        if (data[i] != other[i])
        {
            return false;
        }
    }
    return true;
}
