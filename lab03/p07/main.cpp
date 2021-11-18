#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class Game
{
    friend ostream &operator<<(ostream &sout, const Game &game);
    vector<string> board;

    bool isAttacked(int cellRow, int cellCol) const
    {
        bool res = false;
        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                switch (board[row][col])
                {
                case 'p':
                    if (attackedByBlackPawn(cellRow, cellCol, row, col))
                    {
                        res = true;
                    }
                    break;
                case 'P':
                    if (attackedByWhitePawn(cellRow, cellCol, row, col))
                    {
                        res = true;
                    }
                    break;
                case 'r':
                case 'R':
                    if (isAttackedByRook(cellRow, cellCol, row, col))
                    {
                        res = true;
                    }
                    break;
                case 'b':
                case 'B':
                    if (isAttackedByBishop(cellRow, cellCol, row, col))
                    {
                        res = true;
                    }
                    break;
                case 'q':
                case 'Q':
                    if (isAttackedByQueen(cellRow, cellCol, row, col))
                    {
                        res = true;
                    }
                    break;
                case 'n':
                case 'N':
                    if (isAttackedByKnight(cellRow, cellCol, row, col))
                    {
                        res = true;
                    }
                    break;
                case 'k':
                case 'K':
                    if (isAttackedByKing(cellRow, cellCol, row, col))
                    {
                        res = true;
                    }
                    break;
                }
            }
        }
        return res;
    }
    bool checkDir(int cellRow, int cellCol, int row, int col, int dr, int dc) const
    {
        for (;;)
        {
            if (row < 0 || 8 <= row || col < 0 || 8 <= col)
            {
                return false;
            }
            if (board[row][col] != '.')
            {
                return false;
            }
            if (row == cellRow && col == cellCol)
            {
                return true;
            }
            row += dr;
            col += dc;
        }
        return false;
    }

    bool isAttackedByRook(int cellRow, int cellCol, int rookRow, int rookCol) const
    {
        return checkDir(cellRow, cellCol, rookRow - 1, rookCol, -1, 0) ||
               checkDir(cellRow, cellCol, rookRow + 1, rookCol, +1, 0) ||
               checkDir(cellRow, cellCol, rookRow, rookCol + 1, 0, 1) ||
               checkDir(cellRow, cellCol, rookRow, rookCol - 1, 0, -1);
    }
    bool isAttackedByBishop(int cellRow, int cellCol, int bishopRow, int bishopCol) const
    {
        return checkDir(cellRow, cellCol, bishopRow - 1, bishopCol - 1, -1, -1) ||
               checkDir(cellRow, cellCol, bishopRow - 1, bishopCol + 1, -1, 1) ||
               checkDir(cellRow, cellCol, bishopRow + 1, bishopCol + 1, 1, 1) ||
               checkDir(cellRow, cellCol, bishopRow + 1, bishopCol - 1, 1, -1);
    }
    bool isAttackedByQueen(int cellRow, int cellCol, int queenRow, int queenCol) const
    {
        return isAttackedByRook(cellRow, cellCol, queenRow, queenCol) ||
               isAttackedByBishop(cellRow, cellCol, queenRow, queenCol);
    }
    bool isAttackedByKnight(int cellRow, int cellCol, int knightRow, int knightCol) const
    {
        return ((abs(cellCol - knightCol) == 2) && (abs(cellRow - knightRow) == 1)) ||
               ((abs(cellRow - knightRow) == 2) && (abs(cellCol - knightCol) == 1));
    }

    bool isAttackedByKing(int cellRow, int cellCol, int kingRow, int kingCol) const
    {
        return ((abs(cellRow - kingRow) == 1) && (abs(cellCol - kingCol) == 1)) ||
               ((cellRow == kingRow) && (abs(cellCol - kingCol) == 1)) ||
               ((cellCol == kingCol) && (abs(cellRow - kingRow) == 1));
    }

    bool attackedByBlackPawn(int cellRow, int cellCol, int pawnRow, int pawnCol) const
    {
        return cellRow == pawnRow + 1 && abs(cellCol - pawnCol) == 1;
    }
    bool attackedByWhitePawn(int cellRow, int cellCol, int pawnRow, int pawnCol) const
    {
        return cellRow == pawnRow - 1 && abs(cellCol - pawnCol) == 1;
    }

public:
    Game(const string &cnf)
        : board(8, string(8, '.'))
    {
        int row = 0;
        int col = 0;

        for (auto c : cnf)
        {
            if (c == '/')
            {
                col = 0;
                ++row;
            }
            else if (isdigit(c))
            {
                col += (c - '0');
            }
            else
            {
                board[row][col] = c;
                col++;
            }
        }
    }
    int getNumberOfSafeCells() const
    {
        int res = 0;

        for (int row = 0; row < 8; row++)
        {
            for (int col = 0; col < 8; col++)
            {
                if (board[row][col] == '.')
                {
                    res += !isAttacked(row, col);
                }
            }
        }
        return res;
    }
};

ostream &operator<<(ostream &sout, const Game &game)
{
    for (const auto &row : game.board)
    {
        for (auto cell : row)
        {
            sout << cell;
        }
        sout << endl;
    }
    return sout;
}

int main()
{
    iostream::sync_with_stdio(false);

    for (string cnf; getline(cin, cnf);)
    {
        Game game(cnf);
        cout << game.getNumberOfSafeCells() << endl;
    }
}