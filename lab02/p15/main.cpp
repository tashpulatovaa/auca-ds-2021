#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for (int test = 1; test <= tests; ++test)
    {
        vector<string> pages(10);
        vector<int> relevances(10);

        for (int i = 0; i < 10; i++)
        {
            cin >> pages[i];
            cin >> relevances[i];
        }
        auto maxPos = max_element(begin(relevances), end(relevances));

        cout << "Case #" << test << ":\n";

        for (int i = 0; i < sz(pages); ++i)
        {
            if (relevances[i] == *maxPos)
            {
                cout << pages[i] << "\n";
            }
        }
    }
}