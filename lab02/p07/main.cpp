#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int a, b;

    while (cin >> a, cin >> b)
    {
        if (a == -1 && b == -1)
            break;

        if (a > b)
        {
            swap(a, b);
        }

        int n1 = b - a;
        int n2 = a + 1 + (99 - b);

        int r = min(n1, n2);

        cout << r << "\n";
    }
}