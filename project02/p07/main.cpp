#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Team
{
    int nMembers;
    vector<vector<Submission>> members;

    void parse(stringstream &s)
    {
        int id;
        cin >> id;
        //members[id]
    }
};

struct Submission
{
    int participantId;
    int problemId;
    int time;
    char result;
};

int main()
{
    iostream::sync_with_stdio(false);

    int cases;
    cin >> cases;
    string g;
    getline(cin, g);
    //  cin.ignore(100, '\n');

    for (int test = 0; test < cases; test++)
    {
        string s;
        while (getline(cin, s) && s != "")
        {
            stringstream sin(s);
            Team team;
            team.parse(sin);
        }
    }
}
