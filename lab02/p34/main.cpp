#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for (int n, m; cin >> n >> m;)
    {
        int counter = 0;
        for (int i = n; i <= m; i++)
        {
            if (i >= 10)
            {
                string s = to_string(i);
                vector<char> digits(s.begin(), s.end());
                sort(digits.begin(), digits.end());
                bool hasDuplicates = adjacent_find(digits.begin(), digits.end()) != digits.end();
                if (!hasDuplicates)
                {
                    counter++;
                }
            }
            else
            {
                counter++;
            }
        }
        cout << counter << endl;
    }
}