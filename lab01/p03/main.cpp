#include <iomanip> //Sets the decimal precision to used to format floating-point values (header for setprecision())
#include <iostream>
#include <string>

using namespace std;

int main()
{
    const int kNameWidth = 30;
    const int kAvgWidht =
        40;

    cout << setfill('.') << fixed;
    for (string name; cin >> name;)
    {
        double sum = 0;
        int nGrades = 0;
        for (int grade; cin >> grade;)
        {
            sum += grade;
            ++nGrades;
        }
        if (nGrades != 0)
        {
            cout << left << setw(kNameWidth) << name << "|" << right << setw(kAvgWidht) << setprecision(2) << sum / nGrades << "\n";
        }
        else
        {
            cout << left << setw(kNameWidth) << name << "|" << right << setw(kAvgWidht + 1) << "no data\n";
        }
        cin.clear();
    }
}