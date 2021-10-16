#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int nOfGroups;
    cin >> nOfGroups;

    for (int i = 0; i < nOfGroups; i++)
    {
        vector<int> group(10);
        for (int j = 0; j < 10; j++)
        {
            cin >> group[j];
        }

        if (i == 0)
        {
            cout << "Lumberjacks:"
                 << "\n";
        }

        if (is_sorted(group.begin(), group.end()))
        {
            cout << "Ordered" << endl;
        }
        else
        {
            reverse(group.begin(), group.end());

            if (is_sorted(group.begin(), group.end()))
            {
                cout << "Ordered" << endl;
            }
            else
            {
                cout << "Unordered" << endl;
            }
        }
    }
}