#include <bits/stdc++.h>
using namespace std;

int maxlen(vector<string> a)
{
    int m = 0;
    for (auto c : a)
    {
        if (c.size() > m)
            m = c.size();
    }
    return m;
}

int main()
{
    vector<string> in;
    for (string line; getline(cin, line);)
    {
        if (line.empty())
        {
            sort(in.begin(), in.end(), [](string const &a, string const &b)
                 {
                     string t1 = a;
                     string t2 = b;
                     reverse(t1.begin(), t1.end());
                     reverse(t2.begin(), t2.end());
                     return t1 < t2;
                 });
            int m = maxlen(in);
            for (int i = 0; i < in.size(); ++i)
            {
                cout << setw(m) << in.at(i) << "\n";
            }
            cout << "\n";
            in.clear();
        }
        else
        {
            in.push_back(line);
        }
    }
    sort(in.begin(), in.end(), [](string const &a, string const &b)
         {
             string t1 = a;
             string t2 = b;
             reverse(t1.begin(), t1.end());
             reverse(t2.begin(), t2.end());
             return t1 < t2;
         });
    int m = maxlen(in);
    for (int i = 0; i < in.size(); ++i)
    {
        cout << setw(m) << in.at(i) << "\n";
    }
}