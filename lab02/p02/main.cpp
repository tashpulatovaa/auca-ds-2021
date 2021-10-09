#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

//time limit

int main()
{
    iostream::sync_with_stdio(false);

    int testCases;

    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        int nOfWarriors;
        cin >> nOfWarriors;

        int counter = 0;
        int sum = 0;
        int rows = 0;

        while (sum <= nOfWarriors)
        {
            rows++;
            counter++;
            for (int j = 0; j < counter; j++)
            {
                sum++;
            }
        }
        cout << rows - 1 << "\n";
    }
}