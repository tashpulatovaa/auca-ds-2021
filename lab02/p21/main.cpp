#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    vector<vector<int>> triples;
    vector<int> line;
    int x;
    int c = 0;
    while (cin >> x)
    {
        c++;
        for (int i = 0; i < 3; i++)
        {
            cin >> triples[c][i];
        }
    }

    for (int i = 0; i < sz(triples); i++)
    {
        if (i != 0 && line.back() > triples[i][0])
        {
            continue;
        };
        line.push_back(triples[i][0]);
        line.push_back(triples[i][1]);
        int highest = triples[i][1];
        int highestIndex = i;
        int l = 0;

        while (triples[i][2] > triples[i + l][0])
        {
            if (highest < triples[i + l][1])
            {
                highestIndex = i + l;
            }
        }
        line.push_back(triples[highest][0]);
        line.push_back(triples[highest][1]);
    }
}