#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct SpecialString
{
    string s;
    int weight;
};

int main()
{
    iostream::sync_with_stdio(false);

    int dataSets;
    cin >> dataSets;

    for (int i = 0; i < dataSets; i++)
    {
        int lenght, row;
        cin >> lenght >> row;

        vector<SpecialString> data(row);

        for (int j = 0; j < row; j++)
        {
            string str;
            cin >> str;

            SpecialString tmp = {str, 0};
            for (int k = 0; k < lenght; k++)
            {
                char c = str[k];
                for (int l = k + 1; l < lenght; ++l)
                {
                    if (c > str[l])
                    {
                        tmp.weight++;
                    }
                }
            }
            data[j] = tmp;
        }

        stable_sort(begin(data), end(data), [](SpecialString s1, SpecialString s2)
                    { return s1.weight < s2.weight; });

        for (auto r : data)
        {
            cout << r.s << "\n";
        }
        if (i != dataSets - 1)
        {
            cout << endl;
        }
    }
}