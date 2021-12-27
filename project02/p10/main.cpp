#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    using Cup = pair<int, string>;

    int n;
    cin >> n;

    vector<Cup> cups;
    string data1;
    string data2;

    for (int i = 0; i < n; i++)
    {
        cin >> data1;
        cin >> data2;
        if (isdigit(data1[0]))
        {
            cups.emplace_back(stoi(data1), data2);
        }
        else
        {
            cups.emplace_back((stoi(data2) * 2), data1);
        }
    }

    sort(begin(cups), end(cups), [](Cup c1, Cup c2)
         { return c1.first < c2.first; });

    for (auto c : cups)
    {
        cout << c.second << endl;
    }
}