#include <bits/stdc++.h>

// FIX BUGS

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;
int getDigit(int num)
{
    int result;
    int sum;

    if (num >= 10)
    {
        while (num > 9)
        {
            sum += num % 10;
            num = num / 10;
        }
        result = getDigit(sum);
    }
    else
    {
        result = num;
    }
    return result;
}

int main()
{
    iostream::sync_with_stdio(false);
    string name1;
    string name2;

    while (getline(cin, name1) && getline(cin, name2))
    {
        int n1Length = name1.length(), n2Length = name2.length();
        int sum1, sum2;

        for (int i = 0; i < n1Length; i++)
        {
            if (isalpha(name1.at(i)))
            {
                char c = toupper(name1.at(i));
                sum1 += (name1.at(i) - 'A' + 1);
            }
        }

        for (int i = 0; i < n2Length; i++)
        {
            if (isalpha(name2.at(i)))
            {
                char c = toupper(name2.at(i));
                sum2 += (name2.at(i) - 'A' + 1);
            }
        }

        int r1 = getDigit(sum1);
        int r2 = getDigit(sum2);

        double ratio;
        if (r1 > r2)
        {
            ratio = (double)r1 / (double)r2;
        }
        else
        {
            ratio = (double)r2 / (double)r1;
        }

        cout << fixed;
        cout << setprecision(2) << ratio * 100.00 << "%" << endl;
    }
}
