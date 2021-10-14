#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int counter = 0;

    for (char c; cin >> c;)
    {
        //cout << (c != '"') ? c : ((counter % 2 == 0) ? "``" : "''");

        if (c == '"')
        {
            counter++;
            cout << (counter % 2 == 0) ? '8' : '9';
        }
        else
        {
            cout << c;
        }
    }
}