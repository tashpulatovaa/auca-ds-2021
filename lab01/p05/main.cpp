#include <utility>
#include <iostream>
using namespace std;

int main()
{
    cout << "1st int: ";
    int x;
    cin >> x;

    cout << "2nd ints: ";
    int y;
    cin >> y;

    cout << "Before swap "
         << "a = " << x << ", "
         << "b = " << y << endl;

    swap(x, y);

    cout << "After swap "
         << "a = " << x << ", "
         << "b = " << y << endl;
}
