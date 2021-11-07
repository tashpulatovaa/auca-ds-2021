#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int front, rear;

    while (cin >> front >> rear)
    {
        vector<int> fronts(front);
        for (int i = 0; i < front; i++)
        {
            cin >> fronts[i];
        }
        vector<int> rears(rear);
        for (int i = 0; i < rear; i++)
        {
            cin >> rears[i];
        }

        vector<double> driveRatios;
        for (int i = 0; i < front; i++)
        {
            for (int j = 0; j < rear; j++)
            {
                driveRatios.push_back((double)(rears[j] * 1.0 / fronts[i] * 1.0));
            }
        }
        sort(driveRatios.begin(), driveRatios.end());

        double maxNum = -1;
        for (int i = 0; i < sz(driveRatios) - 1; i++)
        {
            if (maxNum < (driveRatios[i + 1] / driveRatios[i]))
            {
                maxNum = driveRatios[i + 1] / driveRatios[i];
            }
        }

        cout << setprecision(3) << maxNum << endl;
    }
}