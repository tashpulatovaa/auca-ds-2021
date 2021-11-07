#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for (int test; test < tests; test++)
    {
        int nDays, memorySize;
        string nameString;
        cin >> nDays >> memorySize >> nameString;
        vector<char> names(nameString.begin(), nameString.end());

        vector<char> memory(memorySize, ' ');
        int counter = 0;
        for (int i = 0; i < nDays; i++)
        {
            char curName = names[i];
            if (find(memory.begin(), memory.end(), curName) != memory.end())
            {
                counter++;
            }
            memory.erase(memory.begin());
            memory.push_back(curName);
        }
        cout << "Case " << test + 1 << ": " << counter << endl;
    }
}