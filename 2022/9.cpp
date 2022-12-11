#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    set<pair<int, int>> pos;
    pair<int, int> h = {0, 0};
    vector<pair<int, int>> knots(9, {0, 0});
    char prevDir;
    pos.insert(h);
    for (int i = 0; i < n; i++)
    {
        char dir;
        int a;
        cin >> dir >> a;
        for (int j = 0; j < a; j++)
        {
            switch (dir)
            {
            case 'L':
                h.first -= 1;
                break;
            case 'R':
                h.first += 1;
                break;
            case 'U':
                h.second += 1;
                break;
            case 'D':
                h.second -= 1;
                break;
            }

            pair<int, int> k = h;
            for (int l = 0; l < 9; l++)
            {
                pair<int, int> t = knots[l];
                if (abs(k.second - t.second) == 2 || abs(k.first - t.first) == 2)
                {
                    if (abs(k.second - t.second) == 0)
                    {
                        t.first = (t.first + k.first) / 2;
                    }
                    else if (abs(k.first - t.first) == 0)
                    {
                        t.second = (t.second + k.second) / 2;
                    }
                    else if (abs(k.second - t.second) == 1)
                    {
                        t.second = k.second;
                        t.first = (t.first + k.first) / 2;
                    }
                    else if (abs(k.first - t.first) == 1)
                    {
                        t.first = k.first;
                        t.second = (t.second + k.second) / 2;
                    }
                    else if (abs(k.second - t.second) == 2 && abs(k.first - t.first) == 2)
                    {
                        t.first = (t.first + k.first) / 2;
                        t.second = (t.second + k.second) / 2;
                    }
                }
                knots[l] = t;
                k = knots[l];
            }
            pos.insert(knots[8]);
        }
        prevDir = dir;
    }

    cout << pos.size() << endl;
    return 0;
}
