#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int findClosestSum(const int &command, const vector<int> &integers)
{
    int closestSum = integers[0] + integers[1];
    int difference = abs(command - closestSum);
    for (int i = 0; i < sz(integers) - 1; i++)
    {
        for (int j = i + 1; j < sz(integers); j++)
        {
            if (difference > abs(command - (integers[i] + integers[j])))
            {
                difference = abs(command - (integers[i] + integers[j]));
                closestSum = integers[i] + integers[j];
            }
        }
    }
    return closestSum;
}

int main()
{
    iostream::sync_with_stdio(false);

    int cases = 0;
    for (int nOfIntegers; cin >> nOfIntegers && nOfIntegers != 0;)
    {
        vector<int> integers(nOfIntegers);
        for (int i = 0; i < nOfIntegers; i++)
        {
            cin >> integers[i];
        }
        int nOfCommands;
        cin >> nOfCommands;
        vector<int> commands(nOfCommands);
        for (int i = 0; i < nOfCommands; i++)
        {
            cin >> commands[i];
        }

        cases++;
        cout << "Case " << cases << ":"
             << "\n";

        for (int command : commands)
        {
            cout << "Closest sum to " << command << " is " << findClosestSum(command, integers) << "."
                 << "\n";
        }
    }
}