#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int r, c;

    while ((cin >> r >> c) && (r != 0 && c != 0))
    {
        vector<string> strings(c, "");

        for (int i = 0; i < r; i++)
        {
            char ch;
            for (int j = 0; j < c; j++)
            {
                cin >> ch;
                strings[j].push_back(ch);
            }
        }

        stable_sort(begin(strings), end(strings), [](string s1, string s2)
                    {
                        for (auto &k : s1)
                        {
                            k = tolower(k);
                        }
                        for (auto &k : s2)
                        {
                            k = tolower(k);
                        }

                        return s1 < s2;
                    });

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << strings[j][i];
            }
            cout << "\n";
        }
        cout << endl;
    }
}