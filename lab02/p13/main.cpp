#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int nOfBanks, nOfdebartures;
    while (1)
    {
        cin >> nOfBanks;
        cin >> nOfdebartures;
        if (nOfBanks == 0 && nOfdebartures == 0)
            break;

        vector<int> inReserve(nOfBanks + 5);
        int debtor, creditor, val;

        for (int i = 1; i <= nOfBanks; i++)
        {
            int c;
            cin >> c;
            inReserve[i] = c;
        }

        for (int j = 1; j <= nOfdebartures; j++)
        {
            cin >> debtor >> creditor >> val;

            inReserve[debtor] -= val;
            inReserve[creditor] += val;
        }

        bool can = true;
        for (int j = 1; j <= nOfBanks; j++)
        {
            if (inReserve[j] < 0)
            {
                can = false;
                break;
            }
        }

        if (can)
        {
            cout << "S" << endl;
        }
        else
        {
            cout << "N" << endl;
        }
    }
}