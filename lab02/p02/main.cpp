#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int testCases;

    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        long long nOfWarriors;
        cin >> nOfWarriors;

        long long l = (long long)floor(sqrt(2.0 * nOfWarriors + 0.25) + 0.5) - 1;

        cout << l << "\n";
    }
}