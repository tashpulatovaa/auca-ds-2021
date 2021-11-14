#include <bits/stdc++.h>

template <typename C>
int sz(const C &c) { return static_cast<int>(c.size()); }

using namespace std;

void Convert(const string &deck, vector<int> &hand)
{
    if (deck == "HA" || deck == "CA" || deck == "SA" || deck == "DA")
    {
        hand.push_back(4);
    }
    else if (deck == "HK" || deck == "CK" || deck == "SK" || deck == "DK")
    {
        hand.push_back(3);
    }
    else if (deck == "HQ" || deck == "CQ" || deck == "SQ" || deck == "DQ")
    {
        hand.push_back(2);
    }
    else if (deck == "HJ" || deck == "CJ" || deck == "SJ" || deck == "DJ")
    {
        hand.push_back(1);
    }
    else
    {
        hand.push_back(0);
    }
}

bool dealDeck(vector<int> &h1, vector<int> &h2)
{
    h1.clear();
    h2.clear();

    for (int i = 0; i < 26; i++)
    {
        string d2;
        cin >> d2;

        if (d2 == "#")
            return false;
        else
        {
            Convert(d2, h2);

            string d1;
            cin >> d1;

            Convert(d1, h1);
        }
    }
    return true;
}

bool LoopChek(vector<int> &turn, vector<int> &stage)
{
    bool haveFace = false;
    int face = stage.back();
    for (int i = 0; i < face; i++)
    {
        if (sz(turn) == 0)
        {
            return false;
        }
        if (turn.back() != 0)
        {
            haveFace = true;
        }
        stage.push_back(turn.back());
        turn.pop_back();
        if (haveFace)
        {
            break;
        }
    }
    return haveFace;
}

int playGame(vector<int> &h1, vector<int> &h2)
{
    vector<int> stage;
    vector<int> turn = h2;
    vector<int> temp;
    vector<int> notTurn = h1;
    bool player1 = false;

    while (sz(turn) != 0 && sz(notTurn) != 0)
    {
        stage.push_back(turn.back());
        turn.pop_back();
        player1 = !player1;
        temp = turn;
        turn = notTurn;
        notTurn = temp;

        //cout << sz(turn) << " " << sz(notTurn) << endl;

        if (stage.back() != 0)
        {
            //mini sequences until one of players takes entire heap

            while (LoopChek(turn, stage))
            {
                temp = turn;
                turn = notTurn;
                notTurn = temp;
                player1 = !player1;
            }

            temp = turn;
            turn = notTurn;
            notTurn = temp;
            player1 = !player1;
            if (sz(notTurn) != 0)
            {
                // cout << sz(turn) << " + " << sz(stage) << " " << sz(notTurn) << endl;
                reverse(stage.begin(), stage.end());
                turn.insert(turn.begin(), stage.begin(), stage.end());

                stage.clear();
            }
        }
    }
    h1 = turn;

    if (player1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
}

int main()
{
    iostream::sync_with_stdio(false);

    vector<int> hand1;
    vector<int> hand2;

    while (dealDeck(hand1, hand2))
    {

        // for (int d : hand1)
        // {
        //     cout << d << " ";
        // }
        // cout << "\n";

        // for (int d : hand2)
        // {
        //     cout << d << " ";
        // }
        // cout << "\n";

        int winner = playGame(hand1, hand2);
        cout << winner << setw(3) << sz(hand1) << "\n";
    }
}
