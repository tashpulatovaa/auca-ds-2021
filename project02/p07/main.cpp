#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

struct Submission
{
    int mContestant;
    int mProblem;
    int mTime;
    char mResult;

    Submission(const string &s)
    {
        istringstream sinp(s);
        sinp >> mContestant >> mProblem >> mTime >> mResult;
    }
};

using Problem = pair<bool, int>;

struct Contestant
{
    int mNumber;
    int mNumberOfSolvedProblems;
    int mPenaltyTime;
    bool mHadAtLeastOneSubmission;
    vector<Problem> mProblems;

    Contestant(int number)
        : mNumber(number), mNumberOfSolvedProblems(0), mPenaltyTime(0), mHadAtLeastOneSubmission(false), mProblems(9)
    {
    }

    void processSubmission(const Submission s)
    {
        mHadAtLeastOneSubmission = true;

        if (mProblems[s.mProblem - 1].first)
        {
            return;
        }

        if (s.mResult == 'C')
        {
            ++mNumberOfSolvedProblems;
            mProblems[s.mProblem - 1].first = true;
            mPenaltyTime += s.mTime + mProblems[s.mProblem - 1].second;
        }
        else if (s.mResult == 'I')
        {
            mProblems[s.mProblem - 1].second += 20;
        }
    }
};

struct CmpContestants
{
    bool operator()(const Contestant &c1, const Contestant &c2) const
    {
        if (c1.mNumberOfSolvedProblems != c2.mNumberOfSolvedProblems)
        {
            return c1.mNumberOfSolvedProblems > c2.mNumberOfSolvedProblems;
        }
        if (c1.mPenaltyTime != c2.mPenaltyTime)
        {
            return c1.mPenaltyTime < c2.mPenaltyTime;
        }
        return c1.mNumber < c2.mNumber;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int nTests;
    cin >> nTests >> ws;

    for (int test = 0; test < nTests; ++test)
    {
        vector<Contestant> contestants;
        for (int i = 1; i <= 100; ++i)
        {
            contestants.emplace_back(i);
        }

        for (string line; getline(cin, line) && !line.empty();)
        {
            Submission subm(line);
            contestants[subm.mContestant - 1].processSubmission(subm);
        }

        sort(begin(contestants), end(contestants), CmpContestants());

        if (test != 0)
        {
            cout << "\n";
        }

        for (const auto &c : contestants)
        {
            if (c.mHadAtLeastOneSubmission)
            {
                cout << c.mNumber << " " << c.mNumberOfSolvedProblems << " " << c.mPenaltyTime << "\n";
            }
        }
    }
}