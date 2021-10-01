#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    int age;

    while (cin >> name >> age)
    {
        cout << name << " " << age << "\n";
    }
}