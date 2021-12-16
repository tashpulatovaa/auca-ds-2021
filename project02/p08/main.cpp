#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, command;
    cin >> n >> command;

    vector<int> numbers(n);
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    sort(begin(numbers), end(numbers));

    switch (command)
    {
    case 1:
    {
        bool have = false;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (numbers[i] + numbers[j] == 7777)
                {
                    have = true;
                    break;
                }
            }
        }
        if (have)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
        break;
    }

    case 2:
    {
        const bool hasDuplicates = std::adjacent_find(numbers.begin(), numbers.end()) != numbers.end();

        if (!hasDuplicates)
        {
            cout << "Unique" << endl;
        }
        else
        {
            cout << "Contains duplicate" << endl;
        }
        break;
    }

    case 3:
    {

        bool h = false;
        auto t1 = begin(numbers);
        auto t2 = begin(numbers);

        for (int i = 0; i < n; i++)
        {
            t1 = lower_bound(begin(numbers), end(numbers), numbers[i]);
            t2 = upper_bound(begin(numbers), end(numbers), numbers[i]);
            if ((t2 - t1) > n / 2)
            {
                h = true;
                break;
            }
        }
        cout << (h) ? *t1 : -1;
        cout << endl;
        break;
    }

    case 4:
    {
        if (n % 2 == 0)
        {
            cout << numbers[n / 2 - 1] << " " << numbers[n / 2] << endl;
        }
        else
        {
            cout << numbers[n / 2 + 1] << endl;
        }
        break;
    }

    case 5:
    {
        bool first = true;
        auto t1 = lower_bound(begin(numbers), end(numbers), 100);
        auto t2 = upper_bound(begin(numbers), end(numbers), 999);
        bool f = true;
        while (t1 != t2)
        {
            if (!f)
            {
                cout << " ";
            }
            cout << *t1;
            t1++;
            f = false;
        }
        cout << endl;
        break;
    }
    }
}