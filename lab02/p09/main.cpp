#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    int testCases;
    int nOfShops, place, min, max;

    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        cin >> nOfShops;
        cin >> max;
        if (nOfShops == 1)
        {
            cout << 0 << "\n";
            continue;
        }
        cin >> min;
        if (max < min)
        {
            swap(max, min);
        }

        for (int j = 0; j < nOfShops - 2; j++)
        {
            cin >> place;

            if (place > max)
            {
                max = place;
            }
            if (place < min)
            {
                min = place;
            }
        }
        cout << (max - min) * 2 << "\n";
    }
}