#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int cases;
    cin >> cases;

    for (int i = 0; i < cases; i++)
    {
        vector<int> digits(10, 0);
        int number;
        cin >> number;

        for (int j = 1; j <= number; j++)
        {
            if (j >= 10)
            {
                int n = j;
                while (n > 0)
                {
                    digits[n % 10]++;
                    n /= 10;
                }
            }
            else
            {
                digits[j]++;
            }
        }
        for (int k = 0; k < sz(digits); k++)
        {
            cout << digits[k] << ((k != 9) ? " " : "");
        }
        cout << endl;
    }
}