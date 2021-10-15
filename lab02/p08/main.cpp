#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int counter = 0;
    char ch;

    while (cin.get(ch))
    {
        if (ch == '"')
        {
            counter++;
            if (counter % 2 == 0)
            {
                cout << "''";
            }
            else if (counter % 2 == 1)
            {
                cout << "``";
            }
        }
        else if (ch == 32)
        {
            cout << " ";
        }
        else
        {
            cout.put(ch);
        }
    }
    cout << "\n";

    // for (char ch; cin >> ch; ch != 1)
    // {
    //     if (ch == '"')
    //     {
    //         counter++;
    //         if (counter % 2 == 0)
    //         {
    //             cout << "''";
    //         }
    //         else if (counter % 2 == 1)
    //         {
    //             cout << "``";
    //         }
    //     }
    //     else if (ch == 32)
    //     {
    //         cout << " ";
    //     }
    //     else
    //     {
    //         cout << ch;
    //     }
    // }
    // cout << "\n";
}