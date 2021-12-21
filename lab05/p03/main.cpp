#include <iostream>
#include "VecInt.hpp"
#include <algorithm>
#include <vector>

using namespace std;

VecInt getFirstInt(const VecInt &v, size_t n)
{
    VecInt res;

    size_t lim = min(v.size(), n);
    for (size_t i = 0; i < lim; ++i)
    {
        res.pushBack(v[i]);
    }

    return res;
}

void p00()
{
    cout << "---p00-----\n";
    VecInt::nOfCopies = 0;

    VecInt v = {1, 2, 3, 4, 5, 6, 7};

    VecInt w = {1, 2};
    w = getFirstInt(v, 5);
    cout << "w.size = " << w.size() << endl;

    cout << "Number of copies " << VecInt::nOfCopies << endl;
}
void p01()
{
    cout << "---p01-----\n";
    VecInt::nOfCopies = 0;

    VecInt v1 = {5, 2, 3};
    VecInt v2 = {4, 5, 6, 7, 8, 9, 10};

    swap(v1, v2);

    cout << "Number of copies " << VecInt::nOfCopies << endl;
}
void p02()
{
    cout << "---p02-----\n";
    vector<VecInt> v;
    v.reserve(4);
    v.emplace_back(100);
    v.emplace_back(200);
    v.emplace_back(300);
    VecInt w(400);
    v.insert(begin(v), w);

    cout << "Number of copies " << VecInt::nOfCopies << endl;
}

int main()
{
    //p00();
    //p01();
    p02();
}