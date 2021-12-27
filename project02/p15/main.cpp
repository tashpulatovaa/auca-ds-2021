#include <bits/stdc++.h>
using namespace std;

void parseAttributes(vector<string> &a, string line)
{
    string tmp;
    for (int i = 0; i < line.size(); ++i)
    {
        if (line.at(i) == ' ')
        {
            a.push_back(tmp);
            tmp = "";
        }
        else
            tmp += line.at(i);
    }
    a.push_back(tmp);
}

void parseSong(vector<string> &a, string line)
{
    string tmp;
    for (int i = 0; i < line.size(); ++i)
    {
        if (line.at(i) == ' ')
        {
            a.push_back(tmp);
            tmp = "";
        }
        else
            tmp += line.at(i);
    }
    a.push_back(tmp);
}

int main()
{
    vector<string> attr;
    string line;
    getline(cin, line);
    parseAttributes(attr, line);
    getline(cin, line);
    int m = stoi(line);
    vector<vector<string>> songs;
    while (m--)
    {
        vector<string> a;
        getline(cin, line);
        parseSong(a, line);
        songs.push_back(a);
    }
    getline(cin, line);
    m = stoi(line);
    while (m--)
    {
        getline(cin, line);
        auto it = find(attr.begin(), attr.end(), line);
        int d = distance(attr.begin(), it);
        stable_sort(songs.begin(), songs.end(), [&d](vector<string> const &a, vector<string> const &b)
                    { return a.at(d) < b.at(d); });
        for (int i = 0; i < attr.size(); ++i)
        {
            cout << attr.at(i);
            if (i < attr.size() - 1)
            {
                cout << " ";
            }
        }
        cout << "\n";
        for (int i = 0; i < songs.size(); ++i)
        {
            for (int j = 0; j < songs.at(i).size(); ++j)
            {
                cout << songs.at(i).at(j);
                if (j < songs.at(i).size() - 1)
                {
                    cout << " ";
                }
            }
            cout << "\n";
        }
        if (m != 0)
        {
            cout << "\n";
        }
    }
}