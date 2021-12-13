#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Pair
{
    int ascii;
    int value;

    bool operator==(int ch)
    {
        return ascii == ch;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    string str;
    bool first = true;

    while (getline(cin, str))
    {
        if (!first)
        {
            cout << endl;
        }
        vector<Pair> data;
        for (int i = 0; i < sz(str); i++)
        {
            auto ch = find(begin(data), end(data), str[i]);
            if (ch == end(data))
            {
                data.push_back({str[i], 1});
            }
            else
            {
                ch->value++;
            }
        }

        sort(begin(data), end(data), [](Pair p1, Pair p2)
             {
                 if (p1.value == p2.value)
                 {
                     return p2.ascii < p1.ascii;
                 }
                 else
                 {
                     return p1.value < p2.value;
                 }
             });
        for (auto t : data)
        {
            cout << t.ascii << " " << t.value << "\n";
        }

        first = false;
    }
}