#include <bits/stdc++.h>

// FIX BUGS

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

long getDigitSum(int num)
{
    long sum;
    while (num != 0)
    {
        sum += num % 10;
        num = num / 10;
    }
    return sum;
}

int main()
{
    iostream::sync_with_stdio(false);
    string name1, name2;

    while (getline(cin, name1))
    {
        getline(cin, name2);
        int sum1, sum2;

        for (int i = 0; i < name1.length(); i++)
        {
            if (isalpha(name1.at(i)))
            {
                int c = (int)toupper(name1.at(i));
                sum1 += (c - (int)'A' + 1);
            }
        }

        for (int i = 0; i < name2.length(); i++)
        {
            if (isalpha(name2.at(i)))
            {
                int c = (int)toupper(name2.at(i));
                sum2 += (c - (int)'A' + 1);
            }
        }

        int r1 = 10, r2 = 10;
        while (r1 >= 10)
        {
            r1 = getDigitSum(sum1);
        }
        while (r2 >= 10)
        {
            r2 = getDigitSum(sum2);
        }

        // int r1 = getDigitSum(sum1);
        // int r2 = getDigitSum(sum2);

        if (r1 > r2)
        {
            swap(r1, r2);
        }

        double result = (double)r1 / (double)r2 * 100;
        cout << fixed << setprecision(2) << result << "%" << endl;
    }
}
