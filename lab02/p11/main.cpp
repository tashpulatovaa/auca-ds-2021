#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int sumOfDigits(int n)
{
    int sum = 0;
    while (n != 0)
    {
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}

int sumOfLetters(const string &s)
{
    int sum = 0;
    for (char const ch : s)
    {
        if (isalpha(ch))
        {
            sum += toupper(ch) + 1 - 'A';
        }
    }
    return sum;
}

int main()
{
    iostream::sync_with_stdio(false);

    string name1;
    while (getline(cin, name1))
    {
        string name2;
        getline(cin, name2);

        int n1 = sumOfLetters(name1);
        while (n1 >= 10)
        {
            n1 = sumOfDigits(n1);
        }

        int n2 = sumOfLetters(name2);
        while (n2 >= 10)
        {
            n2 = sumOfDigits(n2);
        }

        double d = min(n1, n2) * 100.00 / max(n1, n2);

        cout << fixed << setprecision(2) << d << " %" << endl;
    }
}
