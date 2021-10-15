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

        vector<int> banks(nOfBanks);
        vector<int> debatures(nOfdebartures);
        vector<int> inReserve(nOfBanks);

        for (int i = 0; i < nOfBanks; i++)
        {
            banks[i] = i;
        }

        for (int i = 0; i < nOfBanks; i++)
        {
            int c;
            cin >> c;
            inReserve[i] = c;
        }

        bool can = true;
        for (int j = 0; j < nOfdebartures; j++)
        {
            int debtor, creditor, val;

            cin >> debtor;
            cin >> creditor;
            cin >> val;

            inReserve[creditor - 1] += val;

            if (inReserve[debtor - 1] - val < 0)
            {
                can = false;
            }
        }
        if (can)
        {
            cout << "S"
                 << "\n";
        }
        else
        {
            cout << "N"
                 << "\n";
        }
        can = true;
    }
}