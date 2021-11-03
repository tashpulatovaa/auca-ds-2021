#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int testCases;
    cin >> testCases;

    for (int test = 0; test < testCases; test++)
    {
        int nOfDigits;
        cin >> nOfDigits;
        vector<int> nums(nOfDigits);
        for (int i = 0; i < nOfDigits; i++)
        {
            int x;
            cin >> x;
            nums[i] = x;
        }

        int resultSum = 0;
        for (int i = 1; i < nOfDigits; i++)
        {
            int sum = 0;
            for (int j = 0; j < i; j++)
            {
                if (nums[i] > nums[j] || nums[i] == nums[j])
                {
                    sum++;
                }
            }
            resultSum += sum;
        }

        cout << resultSum << "\n";
    }
}