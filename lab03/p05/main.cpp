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
    void runCommand3(int d, int n)
    {
        registers[d] += n;
        registers[d] %= 1000;
        ++instructionPointer;
    }
    void runCommand4(int d, int n)
    {
        registers[d] *= n;
        registers[d] %= 1000;
        ++instructionPointer;
    }
    void runCommand5(int d, int s)
    {
        registers[d] = registers[s];
        ++instructionPointer;
    }
    void runCommand6(int d, int s)
    {
        registers[d] += registers[s];
        registers[d] %= 1000;
        ++instructionPointer;
    }
    void runCommand7(int d, int s)
    {
        registers[d] *= registers[s];
        registers[d] %= 1000;
        ++instructionPointer;
    }
    void runCommand8(int d, int a, vector<int> &memory1)
    {
        registers[d] = memory1[registers[a]];
        ++instructionPointer;
    }
    void runCommand9(int s, int a, vector<int> &memory1)
    {
        memory1[registers[a]] = registers[s];
        ++instructionPointer;
    }
    void runCommand0(int d, int s)
    {
        instructionPointer = registers[s] == 0 ? instructionPointer + 1 : registers[d];
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
            case 3:
                runCommand3(d1, d2);
                break;
            case 4:
                runCommand4(d1, d2);
                break;
            case 5:
                runCommand5(d1, d2);
                break;
            case 6:
                runCommand6(d1, d2);
                break;
            case 7:
                runCommand7(d1, d2);
                break;
            case 8:
                runCommand8(d1, d2, memory);
                break;
            case 9:
                runCommand9(d1, d2, memory);
                break;
            case 0:
                runCommand0(d1, d2);
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

    bool first = true;
    for (int test = 0; test < tests; test++)
    {
        Computer comp;

        comp.readCommands(cin);

        //cout << comp.run() << "\n";
        if (first)
        {
            cout << comp.run() << endl;
        }
        else
        {
            cout << "\n"
                 << comp.run() << endl;
        }
        first = false;
    }
}