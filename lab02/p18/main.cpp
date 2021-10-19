#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    for (int nOfCourses; cin >> nOfCourses; nOfCourses != 0)
    {
        int nOfCategories;
        cin >> nOfCategories;

        int courses[nOfCourses];

        bool fulfill = true;
        for (int i = 0; i < nOfCategories; i++)
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
                int *end = courses + sizeof(courses);
                if (find(courses, end, course))
                {
                    nOfSimilarNums++;
                }
            }

            if (nOfSimilarNums < minNumOfCategory)
            {
                fulfill = false;
                break;
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