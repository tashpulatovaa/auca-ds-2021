#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
struct Freq
{
    char mLetter;
    int mCount;

    Freq(char letter, int count)
        : mLetter(letter), mCount(count)
    {
    }
};

bool operator==(Freq const &a, char const &b)
{
    return a.mLetter == b;
}

int main()
{
    iostream::sync_with_stdio(false);

    int cases;
    cin >> cases;

    for (int test = 1; test <= cases; test++)
    {
        int row, column, max, min;
        cin >> row >> column >> max >> min;
        vector<Freq> frequences;

        for (int i = 0; i < row; i++)
        {
            string s;
            cin >> s;

            for (int j = 0; j < column; j++)
            {
                auto it = find(begin(frequences), end(frequences), s[j]);
                if (it == frequences.end())
                {
                    frequences.push_back(Freq(s[j], 1));
                }
                else
                {
                    it->mCount = it->mCount + 1;
                }
            }
        }

        // for (Freq f : frequences)
        // {
        //     cout << f.mLetter << " " << f.mCount;
        // }

        sort(begin(frequences), end(frequences), [](Freq a, Freq b)
             { return a.mCount < b.mCount; });
        int maxVal = ((end(frequences) - 1)->mCount);

        int result = 0;
        auto k = begin(frequences);

        //cout << maxVal << endl;

        for (; k != end(frequences); k++)
        {
            if ((k->mCount) == maxVal)
            {
                result += ((k->mCount) * max);
            }
            else
            {
                result += ((k->mCount) * min);
            }
        }

        cout << "Case " << test << ": " << result << endl;
    }
}