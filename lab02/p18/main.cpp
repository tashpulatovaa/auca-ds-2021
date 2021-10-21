#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    // for (int nOfCourses; cin >> nOfCourses; nOfCourses != 0)
    while (1)
    {
        int nOfCourses;
        cin >> nOfCourses;
        if (nOfCourses == 0)
        {
            break;
        }
        else
        {
            int nOfCategories;
            cin >> nOfCategories;

            int allCourses[nOfCourses];

            for (int i = 0; i < nOfCourses; i++)
            {
                int n;
                cin >> n;
                allCourses[i] = n;
            }

            bool fulfill = true;
            for (int i = 0; i < nOfCategories; ++i)
            {
                int nOfCoursesInCategory, minNumOfCategory;
                cin >> nOfCoursesInCategory >> minNumOfCategory;
                int nOfSimilarNums = 0;

                //vector<int> coursesOfCategory;
                for (int j = 0; j < nOfCoursesInCategory; j++)
                {
                    int course;
                    cin >> course;
                    // coursesOfCategory.push_back(course);
                    for (int k = 0; k < nOfCourses; k++)
                    {
                        if (course == allCourses[k])
                        {
                            nOfSimilarNums++;
                            break;
                        }
                    }
                }

                if (nOfSimilarNums < minNumOfCategory)
                {
                    fulfill = false;
                }
            }

            if (fulfill)
            {
                cout << "yes\n";
            }
            else
            {
                cout << "no\n";
            }
        }
    }
}