#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int cycleNum(int a)
{
    int i = 0;
    while (true)
    {
        i++;

        if (a == 1)
            break;

        if (a % 2 == 0)
        {
            a = a / 2;
        }
        else
        {
            a = 3 * a + 1;
        }
    }
    return i;
}

int main()
{
    iostream::sync_with_stdio(false);

    int a;
    int b;

    while (cin >> a >> b)
    {
        cout << a << " " << b << " ";
        if (a > b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        int max = 0;

        for (int i = a; i <= b; i++)
        {

            int c = cycleNum(i);

            if (c >= max)
            {
                max = c;
            }
        }

        cout << max << "\n";
    }
}