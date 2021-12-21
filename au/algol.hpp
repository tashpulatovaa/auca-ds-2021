#pragma once
#include <utility>

template <typename T>
void auSwap(T &x, T &y)
{
    T t = std::move(x);
    x = std::move(y);
    y = std::move(t);
}

template <typename BidirectionalIter>
void auReverse(BidirectionalIter beg, BidirectionalIter end)
{
    for (;;)
    {
        if (beg == end)
        {
            break;
        }
        --end;

        if (beg == end)
        {
            break;
        }

        auSwap(*beg, *end);
        ++beg;
    }
}

template <typename ForwardIter, typename Key>
ForwardIter auFind(ForwardIter beg, ForwardIter end, const Key &key)
{
    while (beg != end)
    {
        if (*beg == key)
        {
            return beg;
        }
        beg++;
    }

    return beg;
}

template <typename ForwardIter, typename UnaryPredicate>
ForwardIter auFindIf(ForwardIter beg, ForwardIter end, UnaryPredicate condition)
{
    while (beg != end)
    {
        if (condition(*beg))
        {
            return beg;
        }

        ++beg;
    }
    return beg;
}

template <typename ForwardIter>
ForwardIter auMinElement(ForwardIter beg, ForwardIter end)
{
    int min = *beg;
    ForwardIter it = beg;
    while (beg != end)
    {
        if (*beg < min)
        {
            min = *beg;
            it = beg;
        }
        ++beg;
    }

    return it;
}

template <typename ForwardIter, typename Comp>
ForwardIter auMinElement(ForwardIter beg, ForwardIter end, Comp cmp)
{
    if (beg == end)
    {
        return end;
    }
    ForwardIter it = beg;
    ++beg;
    while (beg != end)
    {
        if (cmp(*beg, *it))
        {
            it = beg;
        }
        ++beg;
    }
    return it;
}

template <class ForwardIterator, class T>
bool auBinarySearch(ForwardIterator first, ForwardIterator last, const T &val)
{
    first = std::lower_bound(first, last, val);
    return (first != last && !(val < *first));
}
