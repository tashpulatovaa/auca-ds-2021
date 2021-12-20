#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <utility>
#include <tuple>

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
void p04()
{
    vector<int> v;

    int x;
    while (cin >> x)
    {
        v.push_back(x);
    }
    //auto it = min_element(begin(v), end(v));
    auto it = auMinElement(begin(v), end(v));

    if (it != end(v))
    {
        cout << "The positin of the min element in vector "
             << " is " << it - begin(v) << " " << *it << endl;
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
void p07()
{
    vector<Student> students = {{"StudentD", 4.0},
                                {"StudentA", 4.0},
                                {"SudentW", 3.9},
                                {"StudentX", 4.0},
                                {"StudentE", 3.0},
                                {"StudentZ", 4.0},
                                {"StudentY", 4.0}};

    cout << "-----Regular sort-----\n";

    sort(begin(students), end(students), [](Student s1, Student s2)
         { return s1.mName < s2.mName; });

    for (auto s : students)
    {
        cout << s.mName << " " << s.mGpa << "\n";
    }

    cout << "-----Sort by GPA-----\n";
    sort(begin(students), end(students), [](Student s1, Student s2)
         { return s1.mGpa < s2.mGpa; });

    for (auto s : students)
    {
        cout << s.mName << " " << s.mGpa << "\n";
    }

    cout << "-----Stable sort-----\n";

    stable_sort(begin(students), end(students), [](Student s1, Student s2)
                { return s1.mName < s2.mName; });

    for (auto s : students)
    {
        cout << s.mName << " " << s.mGpa << "\n";
    }
}
void p08()
{
    vector<pair<string, double>> students;

    string name;
    double gpa;

    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }

    sort(begin(students), end(students));

    for (auto &s : students)
    {
        cout << s.first << " " << s.second << "\n";
    }
}
void p09()
{
    using Employee = tuple<string, int, double>;
    vector<Employee> employees;

    string name;
    int age;
    double salary;

    while (cin >> name >> age >> salary)
    {
        employees.emplace_back(name, age, salary);
    }

    sort(begin(employees), end(employees), [](Employee e1, Employee e2)
         { return get<1>(e1) < get<1>(e2); });

    for (auto &e : employees)
    {
        cout << get<0>(e) << " " << get<1>(e) << " " << get<2>(e) << "\n";
    }
}
void p10()
{
    vector<int> v = {0, 4, 5, 10, 12, 20, 25, 40};
    // for (int x; cin >> x;)
    // {
    //     cout << (binary_search(begin(v), end(v), x) ? "yes" : "no") << endl;
    // }
    for (int x; cin >> x;)
    {
        cout << (auBinarySearch(begin(v), end(v), x) ? "yes" : "no") << endl;
    }
}
void p11()
{
    vector<int> v = {0, 4, 5, 10, 12, 20, 25, 40};
    for (int x; cin >> x;)
    {
        auto it = lower_bound(begin(v), end(v), x);
        if (it == end(v))
        {
            cout << "No such element\n";
        }
        else if (*it == x)
        {
            cout << "The index of the elemnent is " << it - begin(v) << endl;
        }
        else if (*it > x)
        {
            cout << "The index of the first element that is greater than x is  " << it - begin(v) << endl;
        }
    }
}
void p12()
{
    vector<int> v = {0, 0, 4, 5, 10, 10, 10, 12, 20, 25, 35, 25, 25, 40};
    for (int x; cin >> x;)
    {
        auto p = equal_range(begin(v), end(v), x);

        cout << "The number of occurences of " << x << " is " << p.second - p.first << endl;
    }
}
int main()
{
    //p01();
    //p02();
    //p03();
    //p04();
    //p06();
    //p07();
    //p08();
    //p09();
    //p10();
    //p11();
    p12();
}