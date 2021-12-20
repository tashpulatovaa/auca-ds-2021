#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "../au/algol.hpp"

using namespace std;

struct Student
{
    string mName;
    double mGpa;
    Student(const string &name, double gpa)
        : mName(name), mGpa(gpa)
    {
    }
};

struct IsEven
{
    bool operator()(int number)
    {
        return (number) % 2 == 0;
    }
};

struct GreaterThan
{
    int mData;

    GreaterThan(int data)
        : mData(data)
    {
    }

    bool operator()(int number)
    {
        return (number > mData);
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
void p03()
{
    int x;

    cout << "x = ";
    cin >> x;

    vector<int> v = {3, 1, 20, 4, 7, 0, 5};
    //auto it = find_if(begin(v), end(v), GreaterThan(x));
    auto it = find_if(begin(v), end(v), [x](int n)
                      { return x < n; });

    if (it != end(v))
    {
        cout << "The positin of first number greater than " << x << " is " << it - begin(v) << " " << *it << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}
void p06()
{
    vector<Student> students;

    string name;
    double gpa;

    while ((cin >> name >> gpa))
    {
        students.emplace_back(name, gpa);
    }

    sort(begin(students), end(students), [](Student s1, Student s2)
         { return s1.mName < s2.mName; });

    for (auto s : students)
    {
        cout << s.mName << " " << s.mGpa << "\n";
    }

    cout << "------------------\n";

    sort(begin(students), end(students), [](Student s1, Student s2)
         { return s1.mGpa < s2.mGpa; });

    for (auto s : students)
    {
        cout << s.mName << " " << s.mGpa << "\n";
    }
}

int main()
{
    // p01();
    //p02();
    //p06();
    p03();
}