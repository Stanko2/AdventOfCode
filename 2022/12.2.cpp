#include <bits/stdc++.h>

using namespace std;

int n, m;

int dist(vector<vector<int>> &mapa, pair<int, int> start, pair<int, int> end)
{
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    queue<pair<pair<int, int>, int>> q;
    q.push({start, 0});
    int dirX[4] = {1, 0, 0, -1};
    int dirY[4] = {0, 1, -1, 0};
    while (!q.empty())
    {
        auto x = q.front();
        q.pop();
        if (visited[x.first.first][x.first.second])
            continue;
        visited[x.first.first][x.first.second] = true;
        if (x.first == end)
        {
            return x.second;
        }
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> pos = {x.first.first + dirX[i], x.first.second + dirY[i]};
            if (pos.first >= 0 && pos.second >= 0 && pos.first < n && pos.second < m)
            {
                if (mapa[pos.first][pos.second] - mapa[x.first.first][x.first.second] <= 1 && !visited[pos.first][pos.second])
                {
                    q.push({pos, x.second + 1});
                }
            }
        }
    }
    return INT32_MAX;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;
    vector<vector<int>> mapa(n, vector<int>(m, 0));
    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            if (x == 'S')
            {
                start = {i, j};
                mapa[i][j] = 0;
            }
            else if (x == 'E')
            {
                end = {i, j};
                mapa[i][j] = 25;
            }
            else
                mapa[i][j] = x - 'a';
        }
    }

    int minDist = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mapa[i][j] == 0)
                minDist = min(dist(mapa, {i, j}, end), minDist);
        }
    }
    cout << minDist << endl;
    return 0;
}
