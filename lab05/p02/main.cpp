#include <iostream>
#include "VecInt.hpp"
#include <algorithm>

using namespace std;

int main()
{
    VecInt v;
    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }

    VecInt w;
    w.pushBack(1);
    w.pushBack(2);
    w = v;
    reverse(w.begin(), w.end());

    w = w;

    cout << (w == v ? "Palindrome\n" : "Not palindrome\n") << endl;
}