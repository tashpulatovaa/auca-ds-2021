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
        long n;
        cin >> n;

        long r = abs((((((n * 567) / 9) + 7492) * 235) / 47) - 498);
        int result = (int)(r % 100) / 10;

        cout << result << "\n";
    }
}