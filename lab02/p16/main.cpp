#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

int main()
{
    iostream::sync_with_stdio(false);

    int nOfPeople;
    cin >> nOfPeople;
    vector<string> people(nOfPeople);
    for (auto &name : people)
    {
        cin >> name;
    }

    vector<string> words = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you",
                            "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    int indexOfWords = 0, indexOfPerson = 0;
    bool allSang = false;

    while (1)
    {
        cout << people[indexOfPerson] << ": " << words[indexOfWords] << "\n";
        ++indexOfPerson;
        if (indexOfPerson == sz(people))
        {
            indexOfPerson = 0;
            allSang = true;
        }

        ++indexOfWords;
        if (indexOfWords == sz(words))
        {
            indexOfWords = 0;
            if (allSang)
            {
                break;
            }
        }
    }
}