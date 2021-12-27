#include <bits/stdc++.h>
using namespace std;
string delimiter = "==============================\n";

void parseClass(string &c, char n)
{
    if (n == 'u')
    {
        c = 'a' + c;
    }
    else if (n == 'm')
    {
        c = 'b' + c;
    }
    else
    {
        c = 'c' + c;
    }
}

int main()
{
    using Person = pair<string, string>;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<Person> dict;
        for (int i = 0; i < n; ++i)
        {
            string name;
            string c;
            string t;
            cin >> name >> c >> t;
            name.pop_back();
            dict.push_back({name, c});
        }
        stable_sort(dict.begin(), dict.end(), [](Person const &a, Person const &b)
                    {
                        string a1, a2;
                        parseClass(a1, a.second.at(0));
                        for (int i = 0; i < a.second.size(); ++i)
                        {
                            if (a.second.at(i) == '-')
                            {
                                parseClass(a1, a.second.at(i + 1));
                            }
                        }
                        parseClass(a2, b.second.at(0));
                        for (int i = 0; i < b.second.size(); ++i)
                        {
                            if (b.second.at(i) == '-')
                            {
                                parseClass(a2, b.second.at(i + 1));
                            }
                        }
                        if (a1.size() < a2.size())
                        {
                            int diff = a2.size() - a1.size();
                            for (int i = 0; i < diff; ++i)
                            {
                                a1 = a1 + 'b';
                            }
                        }
                        if (a2.size() < a1.size())
                        {
                            int diff = a1.size() - a2.size();
                            for (int i = 0; i < diff; ++i)
                            {
                                a2 = a2 + 'b';
                            }
                        }
                        return (a1 < a2) || (a1 == a2 && a.first < b.first);
                    });
        for (int i = 0; i < n; ++i)
        {
            cout << dict.at(i).first << "\n";
        }
        cout << delimiter;
    }
}