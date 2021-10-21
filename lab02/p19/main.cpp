#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests;
    cin.ignore();

    for (int test = 0; test < tests; test++)
    {
        vector<string> pieces;

        bool loop = true;

        {
            string s;
            cin >> s;

            getline(cin, s);

            for (int i = 0; i < sz(pieces); i++)
            {
                if (i != sz(pieces) - 1 && pieces[i].at(1) == pieces[i + 1].at(0))
                    loop = false;
            }

            if (loop)
            {
                cout << "LOOP\n";
            }
            else
            {
                cout << "NO LOOP\n";
            }
        }
    }