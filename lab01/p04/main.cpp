#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main()
{
    for (string line; getline(cin, line);)
    {
        string buff;
        for (auto c : line)
        {
            if (isalpha(c))
            {
                buff += tolower(c);
            }
        }
        string temp = buff;
        reverse(temp.begin(), temp.end());

        cout << (buff == temp ? "palindrome\n" : "not a palindrome\n");
    }
}