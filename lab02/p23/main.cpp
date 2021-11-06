#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string top, bottom;
    while (cin >> top >> bottom)
    {

        int bottomIndex = 0;
        bool match = false;
        for (; bottomIndex < sz(bottom); ++bottomIndex)
        {
            int i = bottomIndex, j = 0;
            for (; i < sz(bottom) && j < sz(top); ++i, ++j)
            {
                if (bottom[i] == '2' && top[j] == '2')
                {
                    match = false;
                    break;
                }
                else
                {
                    match = true;
                }
            }
            if (match)
                break;
        }

        int topIndex = 0;
        match = false;
        for (; topIndex < sz(top); ++topIndex)
        {

            int i = topIndex, j = 0;

            for (; i < sz(top) && j < sz(bottom); ++i, ++j)
            {
                if (top[i] == '2' && bottom[j] == '2')
                {
                    match = false;
                    break;
                }
                else
                {
                    match = true;
                }
            }
            if (match)
                break;
        }

        if (sz(top) + bottomIndex >= sz(bottom) && sz(bottom) + topIndex >= sz(top))
        {
            cout << min(sz(top) + bottomIndex, sz(bottom) + topIndex) << endl;
        }
        else if (sz(top) + bottomIndex <= sz(bottom) && sz(bottom) + topIndex >= sz(top))
        {
            cout << min(sz(bottom), sz(bottom) + topIndex) << endl;
        }

        else if (sz(top) + bottomIndex <= sz(bottom) && sz(bottom) + topIndex <= sz(top))
        {
            cout << min(sz(bottom), sz(top)) << endl;
        }
        else if (sz(top) + bottomIndex >= sz(bottom) && sz(bottom) + topIndex <= sz(top))
        {
            cout << min(sz(top) + bottomIndex, sz(top)) << endl;
        }
    }
}