#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    int countSlashes = 0;
    char table[h][w];

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> table[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char c = table[i][j];
            if (c == 47 || c == 92)
            {
                countSlashes++;
            }
            else
            {
                bool left = false, right = false, up = false, down = false;
                for (int k = 0; k < j; k++)
                {
                    if (table[i][k] == 47 || (table[i][k] == 92))
                    {
                        left = true;
                        break;
                    }
                }
                for (int k = j; k < w; k++)
                {
                    if (table[i][k] == 47 || (table[i][k] == 92))
                    {
                        right = true;
                        break;
                    }
                }
                for (int k = 0; k < i; k++)
                {
                    if (table[k][j] == 47 || (table[k][j] == 92))
                    {
                        up = true;
                        break;
                    }
                }
                for (int k = i; k < h; k++)
                {
                    if (table[k][j] == 47 || (table[k][j] == 92))
                    {
                        down = true;
                        break;
                    }
                }
                if (left && right && up && down)
                {
                    countSlashes += 2;
                }
            }
        }
    }

    //cout << (countSlashes % 2 == 0) ? countSlashes / 2 : countSlashes / 2 + 0.5;
    cout << countSlashes / 2 << "\n";
}