#include <utility>
#include <iostream>
#include "../../au/algol.hpp"

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

int main()
{
     cout << "1st int: ";
     int x;
     cin >> x;

     cout << "2nd ints: ";
     int y;
     cin >> y;

     cout << "std::swap:\n";
     cout << "Before swap x = " << x << ", b = " << y << "\n";
     swap(x, y);
     cout << "After swap x = " << x << ", b = " << y << "\n";

     cout << "badSwap:\n";
     cout << "Before swap x = " << x << ", b = " << y << "\n";
     badSwap(x, y);
     cout << "After swap x = " << x << ", b = " << y << "\n";

     cout << "goodSwap01:\n";
     cout << "Before swap x = " << x << ", b = " << y << "\n";
     goodSwap01(&x, &y);
     cout << "After swap x = " << x << ", b = " << y << "\n";


     cout << "goodSwap02:\n";
     cout << "Before swap x = " << x << ", b = " << y << "\n";
     goodSwap02(x, y);
     cout << "After swap x = " << x << ", b = " << y << "\n";

     cout << "general swap for doubles:\n";
     double d1 = 2.32;
     double d2 = 1.45;
     cout << "Before swap d1 = " << d1 << ", d2 = " << d2 << "\n";
     auSwap(d1, d2);
     cout << "After swap d1 = " << d1 << ", d2 = " << d2 << "\n";

     cout << "general swap for strings:\n";
     string s1 = "Hello";
     string s2 = "World";
     cout << "Before swap s1 = " << s1 << ", s2 = " << s2 << "\n";
     auSwap(s1, s2);
     cout << "After swap s1 = " << s1 << ", s2 = " << s2 << "\n";    
}
