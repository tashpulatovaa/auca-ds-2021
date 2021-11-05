#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

class Computer
{
    vector<int> registers;
    vector<int> memory;
    int instructionPointer;

    void runCommand2(int d, int n)
    {
        registers[d] = n;
        ++instructionPointer;
    }

public:
    Computer()
        : registers(10, 0), memory(1000, 0), instructionPointer(0)
    {
    }

    void readCommands(istream &inp)
    {
        int curPos = 0;
        for (string line; getline(inp, line) && !line.empty();)
        {
            memory[curPos] = stoi(line);
            ++curPos;
        }
    }
    int run()
    {
        int res = 1;
        while (memory[instructionPointer] != 100)
        {
            int t = memory[instructionPointer];

            int d2 = t % 10;
            t /= 10;
            int d1 = t % 10;
            t /= 10;
            int d0 = t;

            switch (d0)
            {
            case 2:
                runCommand2(d1, d2);
                break;
            }
            ++res;
        }
        return res;
    }
};

int main()
{
    iostream::sync_with_stdio(false);

    int tests;
    cin >> tests >> ws;

    for (int test = 0; test < tests; test++)
    {
        Computer comp;

        comp.readCommands(cin);

        cout << comp.run() << "\n";
    }
}