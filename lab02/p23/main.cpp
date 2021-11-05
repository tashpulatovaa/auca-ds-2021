#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for (string bottom; getline(cin, bottom) && !bottom.empty();)
    {
        string top;
        getline(cin, top);

        bool suits = false;
        int counter = 0;
        int result = 0;
        if (sz(bottom) < sz(top))
        {
            swap(bottom, top);
        }

        while (!suits)
        {
            for (int i = 0; i < sz(bottom); i++)
            {
                if (counter + sz(top) == sz(bottom))
                {
                    suits = true;
                    break;
                }
                if (counter > sz(bottom) - sz(top) && counter + sz(top) != sz(bottom))
                {
                    if (i + counter > sz(bottom) - 1)
                    {
                        continue;
                    }
                }
                if (!(bottom[i + counter] == top[i] && bottom[i + counter] == 2))
                {
                    suits = true;
                    break;
                }
            }
            counter++;
        }
        if (suits)
        {
            if (counter + sz(top) == sz(bottom))
            {
                result = sz(bottom) + sz(top);
            }
            else if (counter > sz(bottom) - sz(top))
            {
                result = sz(bottom) + (sz(top) + counter - sz(bottom));
            }
            else
            {
                result = sz(bottom);
            }
        }

        cout << result << "\n";
    }
}
