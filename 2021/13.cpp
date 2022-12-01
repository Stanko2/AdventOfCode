#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int maxX = 0, maxY = 0;
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        int b, c;
        cin >> b >> c;
        a[i] = make_pair(b, c);
        if (b > maxX)
            maxX = b + 1;
        if (c > maxY)
            maxY = c + 1;
    }

    string map[1000];

    for (int i = 0; i < maxY; i++)
    {
        for (int j = 0; j < maxX + 1; j++)
            map[i] += '.';
    }

    for (auto i : a)
    {
        map[i.second][i.first] = '#';
    }

    int q;
    cin >> q;
    int points;
    for (int k = 0; k < q; k++)
    {
        points = 0;
        int b, c;
        cin >> b >> c;
        if (b == 0)
        {
            for (int i = 0; i < c; i++)
            {
                for (int j = 0; j < maxY; j++)
                {
                    if (map[j][i] == '#' || map[j][2 * c - i] == '#')
                    {
                        points++;
                        map[j][i] = '#';
                    }
                }
            }
            maxX = c;
        }
        else if (b == 1)
        {
            for (int i = 0; i < maxX + 1; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (map[j][i] == '#' || map[2 * c - j][i] == '#')
                    {
                        points++;
                        map[j][i] = '#';
                    }
                }
            }
            maxY = c;
        }
        cout << "fold: " << k << " points: " << points << endl;
    }

    for (int i = 0; i < maxY; i++)
    {
        for (int j = 0; j < maxX + 1; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }

    return 0;
}
