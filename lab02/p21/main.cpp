#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
const int START = 1;
int main()
{
    iostream::sync_with_stdio(false);

    int start, height, end;
    vector<int> heights(10000);

    int largeEnd = 0;

    while (cin >> start >> height >> end)
    {
        if (largeEnd < end)
        {
            largeEnd = end;
        }

        for (int i = start; i < end; i++)
        {
            heights[i] = max(heights[i], height);
        }
    }

    int best = heights[1];
    cout << "1 " << best;

    for (int j = 2; j < largeEnd; ++j)
    {
        if (best != heights[j])
        {
            cout << ' ' << ' ' << heights[j];
            best = heights[j];
        }
    }
    cout << ' ' << largeEnd << " 0\n";
}