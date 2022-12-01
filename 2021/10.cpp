#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    map<char, char> match = {
        {'{', '}'},
        {'[', ']'},
        {'(', ')'},
        {'<', '>'},
    };
    map<char, int> pts = {
        {')', 1},
        {']', 2},
        {'}', 3},
        {'>', 4},
    };
    vector<long long> score;
    while (true)
    {
        string str;
        getline(cin, str);
        if (str == "exit")
            break;
        stack<char> opening;
        bool broken = false;
        for (auto &i : str)
        {
            if (i == '{' || i == '(' || i == '<' || i == '[')
            {
                opening.push(i);
            }
            else if (i == match[opening.top()])
            {
                opening.pop();
            }
            else
            {
                broken = true;
                break;
            }
        }
        if (!broken)
        {
            score.push_back(0);
            while (!opening.empty())
            {
                score[score.size() - 1] *= 5;
                score[score.size() - 1] += pts[match[opening.top()]];
                opening.pop();
            }
        }
    }
    sort(score.begin(), score.end());
    cout << "Score: " << score[score.size() / 2] << endl;
    return 0;
}
