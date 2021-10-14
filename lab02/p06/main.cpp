#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int testCases;
    cin >> testCases;

    for (int test = 0; test < testCases; test++)
    {
        int salaries[3];
        cin >> salaries[0] >> salaries[1] >> salaries[2];

        int m = max(max(salaries[0], salaries[1]), salaries[2]);
        int n = min(min(salaries[0], salaries[1]), salaries[2]);

        int r;

        for (int i = 0; i < 3; i++)
        {
            if (salaries[i] > n && salaries[i] < m)
                r = salaries[i];
        }

        cout << "Case " << test + 1 << ": " << r << "\n";
    }
}