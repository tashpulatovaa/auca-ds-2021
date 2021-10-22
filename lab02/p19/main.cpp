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

        bool loop = true;

        string s;
        int counter = 0;
        getline(cin, s);
        if (sz(s) < 4)
        {
            loop = false;
        }
        else
        {
            vector<char> pieces(s.begin(), s.end());
            for (int i = 0; i < sz(pieces); i++)
            {
                if (pieces[i] == 'M')
                {
                    counter++;
                }
                else if (pieces[i] == 'F')
                {
                    counter--;
                }
            }

            if (counter == 0)
            {
                loop = true;
            }
            else
            {
                loop = false;
            }
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