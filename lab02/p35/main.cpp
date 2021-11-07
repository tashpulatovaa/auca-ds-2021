#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string final = "";
    string keyboard = "qwertyuiop[]\\ asdfghjkl;' zxcvbnm,./";
    bool first = true;
    for (string part; cin >> part;)
    {
        if (!first)
        {
            final += " ";
        }
        for (int i = 0; i < sz(part); i++)
        {
            for_each(part.begin(), part.end(), [](char &c)
                     { c = ::tolower(c); });

            string s = part.substr(i, 1);
            size_t found = keyboard.find(s);
            if (found != string::npos)
            {
                final += keyboard.substr(found - 2, 1);
            }
        }
        first = false;
    }
    cout << final << endl;
}