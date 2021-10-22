#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);
    bool first = true;
    int nOfFriends;
    while (cin >> nOfFriends)
    {
        if (!first)
        {
            cout << "\n";
        }
        vector<string> names(nOfFriends);
        vector<int> netWorth(nOfFriends);

        for (int i = 0; i < nOfFriends; i++)
        {
            cin >> names[i];
        }

        for (int i = 0; i < nOfFriends; i++)
        {
            string name;
            int spentMoney, nOfGetters;

            cin >> name >> spentMoney >> nOfGetters;

            int idx = find(names.begin(), names.end(), name) - names.begin();

            if (nOfGetters != 0)
            {
                netWorth[idx] = netWorth[idx] - spentMoney + (spentMoney % nOfGetters);
            }

            for (int j = 0; j < nOfGetters; j++)
            {
                string nameG;
                cin >> nameG;

                int id = find(names.begin(), names.end(), nameG) - names.begin();
                netWorth[id] += spentMoney / nOfGetters;
            }
        }

        int count = 0;
        for (string name : names)
        {
            cout << name << " " << netWorth[count] << "\n";
            count++;
        }
        first = false;
    }
}