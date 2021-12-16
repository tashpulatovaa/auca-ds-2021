#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int testCases;
    cin >> testCases;

    for (int i = 0; i < testCases; i++)
    {
        int segment;
        cin >> segment;
        vector<int> red, blue;

        for (int j = 0; j < segment; j++)
        {
            int lenght;
            char color;
            cin >> lenght;
            cin >> color;

            lenght--;

            if (color == 'R')
            {
                red.push_back(lenght);
            }
            else
            {
                blue.push_back(lenght);
            }
        }

        sort(red.rbegin(), red.rend());
        sort(blue.rbegin(), blue.rend());

        int size = min(red.size(), blue.size());

        int length = 0;

        for (int j = 0; j < size; j++)
        {
            length += blue[j];
            length += red[j];
        }

        cout << "Case #" << i + 1 << ": " << length << endl;
    }
}