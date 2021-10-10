#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    //int n1, n2;
    int c = 1;

    for (int n1, n2; cin >> n1 && n1 != 0 && cin >> n2 && n2 != 0;)
    {
        --n1;
        cout << "Case " << c++ << ": ";
        if (n1 / n2 > 26)
            cout << "impossible\n";
        else
            cout << n1 / n2 << '\n';
    }
}