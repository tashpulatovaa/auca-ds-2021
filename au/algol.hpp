#pragma once

template <typename T>
void auSwap(T &x, T &y)
{
    T t = move(x);
    x = move(y);
    y = move(t);
}