#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
int computeDigits(int n)
{
    int sumDigits = 0;

    if (n > 9)
    {
        while (n > 0)
        {
            sumDigits += n % 10;
            n /= 10;
        }
        return computeDigits(sumDigits);
    }
    return n;
}

int main()
{
    iostream::sync_with_stdio(false);

    for (int n; cin >> n && n != 0;)
    {
        int num = computeDigits(n);

        cout << num << "\n";
    }
}