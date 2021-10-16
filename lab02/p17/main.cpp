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
    vector<vector<char>> v(h, vector<char>(w));

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            char c = v[i][j];
            if (c == 47 || c == 92)
            {
                countSlashes++;
            }
            else
            {
                bool left = false, right = false, up = false, down = false;
                for (int k = 0; k < j; k++)
                {
                    if (v[h][k] == 47 || (v[h][k] == 92))
                    {
                        left = true;
                        break;
                    }
                }
                for (int k = j; k < sz(v[0]); k++)
                {
                    if (v[h][k] == 47 || (v[h][k] == 92))
                    {
                        right = true;
                        break;
                    }
                }
                for (int k = 0; k < i; k++)
                {
                    if (v[k][j] == 47 || (v[k][j] == 92))
                    {
                        up = true;
                        break;
                    }
                }
                for (int k = h; k < sz(v); k++)
                {
                    if (v[k][j] == 47 || (v[k][j] == 92))
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