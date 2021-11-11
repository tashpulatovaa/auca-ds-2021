#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class World
{
    friend ostream &operator<<(ostream &out, const World &world);
    vector<vector<int>> columns;

    pair<int, int> findBlock(int a)
    {
        for (int col = 0; col < sz(columns); ++col)
        {
            for (int row = 0; row < sz(columns[col]); row++)
            {
                if (columns[col][row] == a)
                {
                    return make_pair(col, row);
                }
            }
        }
        throw runtime_error("incorrect number of block");
    }

    void putBack(pair<int, int> coord)
    {
        while (sz(columns[coord.first]) > coord.second + 1)
        {
            int c = columns[coord.first].back();
            columns[c].push_back(c);
            columns[coord.first].pop_back();
        }
    }

public:
    World(int n)
        : columns(n)
    {
        for (int i = 0; i < n; i++)
        {
            columns[i].push_back(i);
        }
    }

    void moveOnto(int a, int b)
    {
        pair<int, int> coordA = findBlock(a);
        pair<int, int> coordB = findBlock(b);

        if (coordA.first == coordB.second)
        {
            return;
        }

        putBack(coordA);
        putBack(coordB);

        columns[coordB.first].push_back(columns[coordA.first].back());
        columns[coordA.first].pop_back();
    }
    // MARK: - clears the moving block and push_backs only one element

    void moveOver(int a, int b)
    {
        pair<int, int> coordA = findBlock(a);
        pair<int, int> coordB = findBlock(b);

        if (coordA.first == coordB.second)
        {
            return;
        }

        putBack(coordA);

        columns[coordB.first].push_back(columns[coordA.first].back());
        columns[coordA.first].pop_back();
    }
    void pileOnto(int a, int b)
    {
        pair<int, int> coordA = findBlock(a);
        pair<int, int> coordB = findBlock(b);

        if (coordA.first == coordB.second)
        {
            return;
        }

        putBack(coordB);

        for (int i = 0; i < sz(columns[coordA.first][0]); i++)
        {
            columns[coordB.first].push_back(columns[coordA.first][i]);
            columns[coordA.first].pop_back();
        }
    }
    void pileOver(int a, int b)
    {
        pair<int, int> coordA = findBlock(a);
        pair<int, int> coordB = findBlock(b);

        if (coordA.first == coordB.second)
        {
            return;
        }

        putBack(coordA);

        columns[coordB.first].push_back(columns[coordA.first].back());
        columns[coordA.first].pop_back();
    }
};

ostream &operator<<(ostream &out, const World &world)
{
    for (int i = 0; i < sz(world.columns); i++)
    {
        out << i << ":";
        for (auto e : world.columns[i])
        {
            out << " " << e;
        }
        out << "\n";
    }
    return out;
}

int main()
{
    iostream::sync_with_stdio(false);

    int n;
    cin >> n;

    World world(n);

    for (string cmd; cin >> cmd && cmd != "quit";)
    {
        int a;
        cin >> a;

        string cmd2;
        cin >> cmd2;

        int b;
        cin >> b;

        if (cmd == "move" && cmd2 == "onto")
        {
            world.moveOnto(a, b);
        }
    }
    cout << world;
}