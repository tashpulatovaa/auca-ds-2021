#include <bits/stdc++.h>
using namespace std;

struct CmpWords
{
    bool operator()(string w1, string w2)
    {
        reverse(begin(w1), end(w1));
        reverse(begin(w2), end(w2));
        return w1 < w2;
    }
};

void process(vector<string> &words, int &maxLength)
{
    CmpWords functor;
    sort(begin(words), end(words), functor);
    for (string s : words)
    {
        cout << right << setw(maxLength) << s << "\n";
    }
    //cout << endl;
    words.clear();
    maxLength = 0;
}

int main()
{
    vector<string> words;
    string line;
    int maxLength = 0;
    bool f = true;

    while (getline(cin, line))
    {
        if (line == "")
        {
            if (!f)
            {
                cout << endl;
            }
            process(words, maxLength);
            f = false;
        }
        else
        {
            words.push_back(line);
            if (line.size() > maxLength)
            {
                maxLength = line.size();
            }
        }
    }
    if (!f)
    {
        cout << endl;
    }
    process(words, maxLength);
}