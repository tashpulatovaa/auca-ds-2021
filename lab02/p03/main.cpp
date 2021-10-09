#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int testCase;
    cin >> testCase;
    for (int i = 0; i < testCase; i++)
    {
        int column, row;
        cin >> column;
        cin >> row;

        column -= 2;
        row -= 2;

        int nOfLocatorsC = column / 3 + (column % 3 != 0);
        int nOfLocatorsR = row / 3 + (row % 3 != 0);

        cout << nOfLocatorsC * nOfLocatorsR << "\n";
    }
}