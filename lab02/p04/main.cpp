#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    string name1;
    cin >> name1;
    char c;
    for (int i = 0; i < name1.length(); i++)
    {
        c = toupper(name1.at(i));
        cout << c << "\n";
    }
}