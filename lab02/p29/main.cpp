#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    vector<string> block;
    for (string line; getline(cin, line) && line != "#";)
    {
        if (line.substr(0, 1) == "e")
        {
            int maxMatchLine = 0;
            int maxMatch = 0;
            for (int i = 0; i < sz(block); i++)
            {
                int matches = 0;
                for (int j = 0; j < sz(block); j++)
                {
                    if (j == i)
                        continue;
                    for (int k = 0; k < 5; k++)
                    {
                        // cout << block[i].substr(k * 4, 3) << "  " << block[j].substr(k * 4, 3) << "  ";
                        if (block[i].substr(k * 4, 3) == block[j].substr(k * 4, 3))
                        {
                            matches++;
                        }
                    }
                    //cout << endl;
                }
                if (matches > maxMatch)
                {
                    maxMatch = matches;
                    maxMatchLine = i + 1;
                }
            }
            cout << maxMatchLine << endl;
            block.clear();
            continue;
        }
        else
        {
            block.push_back(line);
        }
    }
}