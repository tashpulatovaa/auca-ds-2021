#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int findDistance(int point1, int point2)
{
    return abs(point1 - point2);
}

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test = 0; test < tests; test++)
    {
        int nOfRelatives;
        cin >> nOfRelatives;
        vector<int> addresses(nOfRelatives);
        for (int i = 0; i < nOfRelatives; i++)
        {
            cin >> addresses[i];
        }

        int minDis;
        for (int i = 0; i < nOfRelatives; i++)
        {
            int sum = 0;
            for (int j = 0; j < nOfRelatives; j++)
            {
                if (addresses[i] == addresses[j])
                    continue;
                sum += findDistance(addresses[i], addresses[j]);
            }
            if (i == 0)
            {
                minDis = sum;
            }
            else
            {
                if (sum < minDis)
                {
                    minDis = sum;
                }
            }
        }
        cout << minDis << endl;
    }
}