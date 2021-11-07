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

        for (int i = 1; i < nOfElements - 1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                for (int k = i + 1; k < nOfElements; k++)
                {
                    if (2 * numbers[i] == numbers[j] + numbers[k])
                    {
                        progression = true;
                        break;
                    }
                }
                if (progression)
                {
                    break;
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