#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for (int nOfElements; cin >> nOfElements && nOfElements != 0;)
    {
        vector<int> numbers(nOfElements);
        char c;
        cin >> c;
        for (int i = 0; i < nOfElements; i++)
        {
            cin >> numbers[i];
        }
        bool progression = false;

        for (int i = 0; i < nOfElements - 2; i++)
        {
            for (int j = i + 1; j < nOfElements; j++)
            {
                int nextMember = numbers[j] - numbers[i] + numbers[j];
                if (nextMember >= 0 && nextMember < nOfElements)
                {
                    if ((find(numbers.begin(), numbers.end(), nextMember) - numbers.begin()) > j)
                    {
                        progression = true;
                        break;
                    }
                }
            }
            if (progression)
            {
                break;
            }
        }

        if (progression)
        {
            cout << "no\n";
        }
        else
        {
            cout << "yes\n";
        }
    }
}