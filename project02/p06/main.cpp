#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Team
{
    string name;
    int totalPoint;
    int gamesPlayed;
    int wins;
    int ties;
    int losses;
    int goalDif;
    int goalsScored;
    int goalsAgainst;

    bool operator==(string s)
    {
        return name == s;
    }
};
ostream &operator<<(ostream &s, Team team)
{
    s << team.name << " " << team.totalPoint << "p, "
      << team.gamesPlayed << "g (" << team.wins << "-"
      << team.ties << "-" << team.losses << "), " << team.goalDif << "gd (" << team.goalsScored << "-"
      << team.goalsAgainst << ")";

    return s;
}

struct CmpByName
{
    bool operator()(Team const &a, Team const &b)
    {
        return a.name < b.name;
    }
};
struct CmpByResult
{
    bool operator()(Team const &a, Team const &b)
    {
        if (a.totalPoint == b.totalPoint)
        {
            if (a.wins == b.wins)
            {
                if (a.goalDif == b.goalDif)
                {
                    if (a.goalsScored == b.goalsScored)
                    {
                        if (a.gamesPlayed == b.gamesPlayed)
                        {
                            string s1 = a.name;
                            string s2 = b.name;
                            std::transform(s1.begin(), s1.end(), s1.begin(),
                                           [](unsigned char c)
                                           { return std::tolower(c); });
                            std::transform(s2.begin(), s2.end(), s2.begin(),
                                           [](unsigned char c)
                                           { return std::tolower(c); });

                            return s1 < s2;
                        }
                        return a.gamesPlayed < b.gamesPlayed;
                    }
                    return a.goalsScored > b.goalsScored;
                }
                return a.goalDif > b.goalDif;
            }
            return a.wins > b.wins;
        }
        return a.totalPoint > b.totalPoint;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int tournaments;
    cin >> tournaments;
    string s;
    getline(cin, s);
    bool first = true;

    for (int i = 0; i < tournaments; i++)
    {
        vector<Team> teams;
        teams.clear();
        if (!first)
        {
            cout << endl;
        }
        string tName;
        getline(cin, tName);

        int nTeams;
        cin >> nTeams;
        getline(cin, s);

        for (int j = 0; j < nTeams; j++)
        {
            string name;
            getline(cin, name);
            teams.push_back({name, 0, 0, 0, 0, 0, 0, 0, 0});
        }
        int nGames;
        cin >> nGames;
        getline(cin, s);

        for (int c = 0; c < nGames; c++)
        {
            string line;
            getline(cin, line);

            string t1 = "", t2 = "";
            string goal1 = "", goal2 = "";

            int k = 0;
            while (line[k] != '#')
            {
                t1 += line[k];
                k++;
            }
            k++;
            while (line[k] != '@')
            {
                goal1 += line[k];
                k++;
            }
            k++;
            while (line[k] != '#')
            {
                goal2 += line[k];
                k++;
            }
            k++;
            while (k != sz(line))
            {
                t2 += line[k];
                k++;
            }

            auto it1 = find(begin(teams), end(teams), t1);
            auto it2 = find(begin(teams), end(teams), t2);

            // it1->totalPoint += stoi(goal1);
            // it2->totalPoint += stoi(goal2);

            it1->gamesPlayed++;
            it2->gamesPlayed++;

            it1->goalsScored += stoi(goal1);
            it2->goalsScored += stoi(goal2);
            it1->goalsAgainst += stoi(goal2);
            it2->goalsAgainst += stoi(goal1);

            if (stoi(goal1) > stoi(goal2))
            {
                it1->wins++;
                it2->losses++;
            }
            else if (stoi(goal1) < stoi(goal2))
            {
                it1->losses++;
                it2->wins++;
            }
            else if (stoi(goal1) == stoi(goal2))
            {
                it1->ties++;
                it2->ties++;
            }

            it1->totalPoint = (3 * it1->wins + it1->ties);
            it2->totalPoint = (3 * it2->wins + it2->ties);

            it1->goalDif = (it1->goalsScored - it1->goalsAgainst);
            it2->goalDif = (it2->goalsScored - it2->goalsAgainst);
        }

        sort(begin(teams), end(teams), CmpByResult());

        cout << tName << endl;
        int count = 1;
        for (auto t : teams)
        {
            cout << count << ") " << t << "\n";
            count++;
        }
        first = false;
    }
}