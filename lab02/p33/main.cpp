#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; test++)
    {
        int nStudents;
        cin >> nStudents;
        vector<int> grades(nStudents);
        int sum = 0;
        for (int i = 0; i < nStudents; i++)
        {
            cin >> grades[i];
            sum += grades[i];
        }
        int more = 0;
        double avarage = sum * 1.0 / nStudents;
        for (int i = 0; i < nStudents; i++)
        {
            if (grades[i] > avarage)
            {
                more++;
            }
        }
        cout << fixed << setprecision(3) << (more * 1.0 / nStudents) * 100 << "%\n";
    }
}