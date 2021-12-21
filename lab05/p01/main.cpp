#include <iostream>
#include "../../au/algol.hpp"
#include "VecInt.hpp"

using namespace std;

void printVecInt(const VecInt &v)
{
    // for (int e : v)
    // {
    //     cout << e << " ";
    // }
    // cout << "\n";

    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
}

void p01()
{
    cout << "The size of array: ";
    int n;
    cin >> n;

    VecInt v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    printVecInt(v);
    auReverse(v.begin(), v.end());
    printVecInt(v);
}

void p02()
{
    VecInt v;

    for (int x; cin >> x;)
    {
        v.pushBack(x);
    }

    printVecInt(v);
    auReverse(v.begin(), v.end());
    v[1000] = 10;
    printVecInt(v);
}

int main()
{
    p02();
}