#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

//declarations(prototypes) of functions
vector<int> createDeck();
void printDeck(const vector<int> &deck);
vector<vector<int>> readShuffles();
void applyShuffleToDeck(vector<int> &deck, vector<int> &shuffle);

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests;

    for (int test = 0; test < tests; test++)
    {
        auto shuffles = readShuffles();
        auto deck = createDeck();

        for (string line; getline(cin, line) && !line.empty();)
        {
            int m = stoi(line);
            applyShuffleToDeck(deck, shuffles[m - 1]);
        }
        if (test != 0)
        {
            cout << "\n";
        }

        printDeck(deck);
    }
}

vector<int> createDeck()
{
    vector<int> r(52);

    for (int i = 0; i < 52; i++)
    {
        r[i] = i;
    }

    return r;
}

void printDeck(const vector<int> &deck)
{
    static vector<string> ranks = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    static vector<string> suits = {"Clubs", "Diamonds", "Hearts", "Spades"};

    for (auto card : deck)
    {
        cout << ranks[card % 13] << " of " << suits[card / 13] << endl;
    }
}

vector<vector<int>> readShuffles()
{
    int n;
    cin >> n;

    vector<vector<int>> r(n, vector<int>(52));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 52; j++)
        {
            cin >> r[i][j];
        }
    }

    cin.ignore(1024, '\n');

    return r;
}

void applyShuffleToDeck(vector<int> &deck, vector<int> &shuffle)
{
    vector<int> t = deck;
    for (int i = 0; i < 52; i++)
    {
        deck[i] = t[shuffle[i] - 1];
    }
}