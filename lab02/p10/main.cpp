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
        int nOfWalls, currentWall, nextWall;
        int lows = 0;
        int highs = 0;
        cin >> nOfWalls;
        cin >> currentWall;

        for (int j = 0; j < nOfWalls - 1; j++)
        {
            cin >> nextWall;
            if (currentWall > nextWall)
            {
                lows++;
            }
            else if (currentWall < nextWall)
            {
                highs++;
            }
            currentWall = nextWall;
        }
        cout << "Case " << i + 1 << ": " << highs << " " << lows << "\n";
    }
}