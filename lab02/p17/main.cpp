#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int h = 0;
    int w = 0;

    while (cin >> h >> w)
    {
        char ch[h][w];

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> ch[i][j];
            }
        }

        int nOfSlashes = 0;
        int r = 0;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                if (ch[i][j] == '.')
                {
                    if (nOfSlashes % 2 != 0)
                    {
                        ++r;
                    }
                }
                else
                {
                    ++nOfSlashes;
                }
            }
        }
        r += nOfSlashes / 2;
        cout << r << "\n";
    }
}