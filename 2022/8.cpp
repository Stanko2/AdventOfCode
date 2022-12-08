#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            map[i][j] = x - '0';
        }
    }

    set<pair<int, int>> visible;
    for (int i = 0; i < n; i++)
    {
        int h = map[i][0];
        visible.insert({i, 0});
        for (int j = 1; j < m; j++)
        {
            if (map[i][j] > h)
            {
                visible.insert({i, j});
                h = map[i][j];
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        int h = map[i][m - 1];
        visible.insert({i, m - 1});
        for (int j = m - 2; j >= 0; j--)
        {
            if (map[i][j] > h)
            {
                visible.insert({i, j});
                h = map[i][j];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int h = map[0][i];
        visible.insert({0, i});
        for (int j = 1; j < n; j++)
        {
            if (map[j][i] > h)
            {
                visible.insert({j, i});
                h = map[j][i];
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        int h = map[n - 1][i];
        visible.insert({n - 1, i});
        for (int j = n - 2; j >= 0; j--)
        {
            if (map[j][i] > h)
            {
                visible.insert({j, i});
                h = map[j][i];
            }
        }
    }

    cout << visible.size() << endl;
    return 0;
}
