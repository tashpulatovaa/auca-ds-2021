#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int n, m;

    vector<int> nums;

    while (cin >> n >> m)
    {
        cout << n << " " << m << "\n";
        if (n == 0 && m == 0)
        {
            break;
        }
        nums.clear();
        for (int i = 0; i < n; i++)
        {
            int d;
            cin >> d;
            nums.push_back(d);
        }

        sort(begin(nums), end(nums), [&m](int num1, int num2)
             {
                 if (num1 % m < num2 % m)
                 {
                     return true;
                 }
                 else if (num1 % m == num2 % m)
                 {
                     if ((num1 % 2 == 0) && (num2 % 2 == 0))
                     {
                         if (num1 < num2)
                         {
                             return true;
                         }
                         else
                         {
                             return false;
                         }
                     }
                     else if ((num1 % 2 != 0) && (num2 % 2 != 0))
                     {
                         if (num1 > num2)
                         {
                             return true;
                         }
                         else
                         {
                             return false;
                         }
                     }
                     else
                     {
                         if (num1 % 2 == 0)
                         {
                             return false;
                         }
                         else
                         {
                             return true;
                         }
                     }
                 }
                 else
                 {
                     return false;
                 }
             });
        for (auto i : nums)
        {
            cout << i << "\n";
        }
    }
}