#include <bits/stdc++.h>
using namespace std;

void case1(vector<int> in)
{
    sort(in.begin(), in.end());
    for (auto i : in)
    {
        if (binary_search(in.begin(), in.end(), 7777 - i))
        {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

void case2(vector<int> in)
{
    sort(in.begin(), in.end());
    auto it = unique(in.begin(), in.end());
    if (it != in.end())
    {
        cout << "Contains duplicate\n";
    }
    else
    {
        cout << "Unique\n";
    }
}

void case3(vector<int> &in)
{
    int n = in.size() / 2;
    sort(in.begin(), in.end());
    for (auto i : in)
    {
        auto lower = lower_bound(in.begin(), in.end(), i);
        auto upper = upper_bound(in.begin(), in.end(), i);
        if (distance(lower, upper) > n)
        {
            cout << i << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

void case4(vector<int> in)
{
    sort(in.begin(), in.end());
    if (in.size() % 2 == 1)
    {
        cout << in.at(in.size() / 2);
    }
    else
    {
        cout << in.at(in.size() / 2 - 1) << " " << in.at(in.size() / 2);
    }
    cout << "\n";
}

void case5(vector<int> in)
{
    sort(in.begin(), in.end());
    auto lower = lower_bound(in.begin(), in.end(), 100);
    auto upper = upper_bound(in.begin(), in.end(), 999);
    for (; lower < upper; ++lower)
    {
        cout << *lower;
        if (lower != upper - 1)
        {
            cout << " ";
        }
    }
}

int main()
{
    iostream::sync_with_stdio(false);
    int n, command;
    cin >> n >> command;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a.at(i);
    }
    if (command == 1)
    {
        case1(a);
    }
    if (command == 2)
    {
        case2(a);
    }
    if (command == 3)
    {
        case3(a);
    }
    if (command == 4)
    {
        case4(a);
    }
    if (command == 5)
    {
        case5(a);
    }
}