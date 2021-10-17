#include <utility>
#include <iostream>
using namespace std;

void badSwap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
}

void goodSwap01(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void goodSwap02(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

template <typename T>
void auSwap(T &x, T &y)
{
    T t = x;
    x = y;
    y = t;
}

int main()
{
    cout << "1st int: ";
    int x;
    cin >> x;

    cout << "2nd ints: ";
    int y;
    cin >> y;

    cout << "std::swap:\n";
    cout << "Before swap "
         << "a = " << x << ", "
         << "b = " << y << endl;

    swap(x, y);

    cout << "After swap "
         << "a = " << x << ", "
         << "b = " << y << endl;

    cout << "badSwap\n";
    cout << "Before swap "
         << "a = " << x << ", "
         << "b = " << y << endl;

    badSwap(x, y);
    cout << "After swap\n "
         << "a = " << x << ", "
         << "b = " << y << endl;

    cout << "goodSwap01\n";
    cout << "Before swap "
         << "a = " << x << ", "
         << "b = " << y << endl;

    goodSwap01(&x, &y);
    cout << "After swap "
         << "a = " << x << ", "
         << "b = " << y << endl;

    cout << "goodSwap02\n";
    cout << "Before swap "
         << "a = " << x << ", "
         << "b = " << y << endl;

    goodSwap02(x, y);
    cout << "After swap "
         << "a = " << x << ", "
         << "b = " << y << endl;

    cout << "general swap for doubles:\n";
    double d1 = 2.32;
    double d2 = 1.45;
    cout << "Before swap "
         << "d1 = " << d2 << ", "
         << "d2 = " << d2 << endl;

    auSwap(d1, d2);
    cout << "After swap "
         << "d1 = " << d1 << ", "
         << "d2 = " << d2 << endl;
}
