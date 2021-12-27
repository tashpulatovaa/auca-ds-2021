#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    bool f = true;

    while (cin >> n && n != 0)
    {
        vector<string> names;

        string name;
        for (int i = 0; i < n; i++)
        {
            cin >> name;
            names.emplace_back(name);
        }

        stable_sort(begin(names), end(names), [](string const &n1, string const &n2)
                    { return (n1.at(0) < n2.at(0)) || (n1.at(0) == n2.at(0) && n1.at(1) < n2.at(1)); });

        if (!f)
        {
            cout << endl;
        }
        for (auto &e : names)
        {
            cout << e << "\n";
        }
        f = false;
    }
}