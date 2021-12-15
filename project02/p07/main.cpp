#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Participant
{
    int id;
    vector<int> solved;
    int penalty;
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
    cin.ignore(100, '\n');

    for (int test = 0; test < cases; test++)
    {
        int tId, tProblem, time;
        char tRes;
        stringstream sin;
        string s;
        getline(cin, s);
        sin << s;

        // while (sin != '\n' && s != "";)
        // {
        // }
    }
}