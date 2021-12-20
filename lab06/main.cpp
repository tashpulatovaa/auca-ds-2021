#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "../au/algol.hpp"

using namespace std;

struct IsEven
{
    bool operator()(int number)
    {
        return (number) % 2 == 0;
    }
};

void p01()
{
    int a[] = {3, 1, 20, 4, 7, 0, 5};
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    auto it1 = auFind(begin(a), end(a), 20);
    auto it2 = auFind(begin(v), end(v), 20);

    if (it1 != end(a))
    {
        cout << "The positin of 20 in the array is " << it1 - begin(a) << endl;
    }
    else
    {
        cout << "-1 not found" << endl;
    }
    if (it2 != end(v))
    {
        cout << "The positin of 20 in the vector is " << it2 - begin(v) << endl;
    }
    else
    {
        cout << "-1 not found" << endl;
    }
}

void p02()
{
    IsEven functor;
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};
    //auto it = find_if(begin(v), end(v), functor);
    //auto it = find_if(begin(v), end(v), IsEven());
    // auto it = find_if(begin(v), end(v), [](int a)
    //                   { return a % 2 == 0; });

    auto it = auFindIf(begin(v), end(v), functor);

    if (it != end(v))
    {
        cout << "The positin of first even number in the vector is " << it - begin(v) << endl;
    }
    else
    {
        cout << "-1 not found" << endl;
    }
}

int main()
{
    // p01();
    p02();
}