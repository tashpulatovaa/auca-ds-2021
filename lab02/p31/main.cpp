#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    cout << "PERFECTION OUTPUT\n";
    for (int number; cin >> number && number != 0;)
    {
        int sum = 0;
        for (int i = 1; i < number; i++)
        {
            if (number % i == 0)
            {
                sum += i;
            }
        }
        if (sum == number)
        {
            cout << setw(5) << number << "  PERFECT\n";
        }
        else if (sum > number)
        {
            cout << setw(5) << number << "  ABUNDANT\n";
        }
        else if (sum < number)
        {
            cout << setw(5) << number << "  DEFICIENT\n";
        }
    }
    cout << "END OF OUTPUT\n";
}