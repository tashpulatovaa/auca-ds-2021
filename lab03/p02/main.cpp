#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void printPuzzle(const vector<string> &puzzle)
{
    for (const auto &row : puzzle)
    {
        for (int i = 0; i < sz(row); i++)
        {
            if (i != 0)
            {
                cout << " ";
            }
            cout << row[i];
        }
        cout << "\n";
    }
}

bool readPuzzle(vector<string> &puzzle)
{
    puzzle.clear();

    string line;
    getline(cin, line);

    if (line == "Z")
    {
        return false;
    }

    puzzle.push_back(line);
    for (int i = 0; i < 4; ++i)
    {
        getline(cin, line);
        puzzle.push_back(line);
    }

    return true;
}

string readMoves()
{
    string r;
    for (char c; cin >> c && c != '0';)
    {
        r.push_back(c);
    }
    cin.ignore(1024, '\n');
    return r;
}
vector<int> emptyPoint(const vector<string> &puzzle)
{
    int emptyRow = -1;
    int emptyCol = -1;
    vector<int> point(2);
    point.push_back(emptyRow);
    point.push_back(emptyCol);

    for (int row = 0; row < sz(puzzle); ++row)
    {
        size_t pos = puzzle[row].find(' ');
        if (pos != string::npos)
        {
            point[0] = row;
            point[1] = int(pos);
        }
    }

    return point;
}

bool applyMoves(vector<string> &puzzle, const string &moves)
{
    int emptyRow = (emptyPoint(puzzle))[0];
    int emptyCol = (emptyPoint(puzzle))[1];
    for (auto m : moves)
    {
        int row = emptyRow;
        int col = emptyCol;
        if (m == 'A')
            row = emptyRow - 1;

        else if (m == 'B')
            row = emptyRow + 1;

        else if (m == 'L')
            col = emptyCol - 1;

        else if (m == 'R')
            col = emptyCol + 1;

        if (0 <= row && row < 5 && 0 <= col && col < 5)
        {
            swap(puzzle[emptyRow][emptyCol], puzzle[row][col]);
            emptyRow = row;
            emptyCol = col;
        }
        else
            return false;
    }
    return true;
}

int main()
{
    iostream::sync_with_stdio(false);

    vector<string> puzzle;
    for (int test = 1; readPuzzle(puzzle); ++test)
    {
        string moves = readMoves();

        if (test != 1)
        {
            cout << "\n";
        }
        cout << "Puzzle #" << test << ":\n";

        if (applyMoves(puzzle, moves))
        {
            printPuzzle(puzzle);
        }
        else
        {
            cout << "This puzzle has no final configuration.\n";
        }
    }
}