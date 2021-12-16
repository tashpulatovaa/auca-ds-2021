#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct CmpTeamByNumber
{
};

struct Participant
{
    int id;
    vector<int> solved;
    vector<int> tries;
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
    string g;
    getline(cin, g);
    cin.ignore(100, '\n');

    for (int test = 0; test < cases; test++)
    {
        if (test != 0)
        {
            cout << endl;
        }
        string s;
        int tId, tProblem, tTime;
        char tResult;
        vector<Submission> submissions;
        vector<Participant> team;

        while (getline(cin, s) && s != "")
        {
            stringstream sin(s);

            sin >> tId >> tProblem >> tTime >> tResult;
            //cout << tId << tProblem << tTime << tResult;
            if (tResult == 'C' || tResult == 'I')
            {
                submissions.push_back({tId, tProblem, tTime, tResult});
                auto it = find_if(begin(team), end(team), [tId](Participant p1)
                                  { return tId == p1.id; });
                if (it == end(team))
                {
                    team.push_back({tId, vector<int>{0}, vector<int>{0}, 0});
                    auto p = team.back();
                    if (p.solved.size() == 1 && p.solved[0] == 0)
                    {
                        p.solved.clear();
                        p.tries.clear();
                    }

                    if (tResult == 'C')
                    {
                        p.solved.push_back(tProblem);
                        p.penalty = tTime;
                    }
                    else
                    {
                        p.tries.push_back(tProblem);
                    }
                }
                else
                {
                    if (tResult == 'C')
                    {
                        //int count = 0;
                        auto it2 = find(begin(it->tries), end(it->tries), tProblem);
                        while (it2 != end(it->tries))
                        {
                            it->penalty += 20;
                            it->tries.erase(it2);
                            it->penalty += tTime;
                            it2 = find(begin(it->tries), end(it->tries), tProblem);
                        }
                        it->solved.push_back(tProblem);
                    }
                    else
                    {
                        it->tries.push_back(tProblem);
                    }
                }
            }
        }
        sort(begin(team), end(team), [](Participant p1, Participant p2)
             { return p1.solved < p2.solved; });

        for (auto t : team)
        {
            cout << t.id << " " << t.solved.size() << " " << t.penalty << endl;
        }
        for (auto t : team)
        {
            for (auto k : t.solved)
            {
                cout << k;
            }
            cout << endl;
        }
    }
}
