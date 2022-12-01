#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> map;
    while (true)
    {
        string str;
        cin >> str;
        if (str == "exit")
            break;
        map.push_back(str);
    }
    int smerX[4] = {-1, 0, 1, 0};
    int smerY[4] = {0, 1, 0, -1};
    int risk = 0;
    vector<pair<int, int>> minima;
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[i].size(); j++)
        {
            bool minimum = true;
            for (int k = 0; k < 4; k++)
            {
                if (j + smerX[k] >= 0 && j + smerX[k] < map[i].size() && i + smerY[k] >= 0 && i + smerY[k] < map.size())
                {
                    if (map[i + smerY[k]][j + smerX[k]] <= map[i][j])
                    {
                        minimum = false;
                        break;
                    }
                }
            }
            if (minimum)
            {
                cout << "minimum " << i << j << endl;
                risk += (map[i][j] - '0') + 1;
                minima.push_back(make_pair(i, j));
            }
        }
    }
    vector<int> basins;
    for (auto &i : minima)
    {
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        q.push(i);
        while (!q.empty())
        {
            pair<int, int> c = q.front();
            q.pop();
            if (visited.count(c) == 1)
            {
                continue;
            }
            visited.insert(c);
            for (int k = 0; k < 4; k++)
            {
                if (c.second + smerX[k] >= 0 && c.second + smerX[k] < map[0].size() && c.first + smerY[k] >= 0 && c.first + smerY[k] < map.size())
                {
                    if (map[c.first + smerY[k]][c.second + smerX[k]] > map[c.first][c.second] && map[c.first + smerY[k]][c.second + smerX[k]] != '9')
                    {
                        q.push(make_pair(c.first + smerY[k], c.second + smerX[k]));
                    }
                }
            }
        }
        basins.push_back(visited.size());
    }
    sort(basins.begin(), basins.end(), greater<int>());
    cout << "risk: " << risk << endl;
    cout << "basins: " << basins[0] * basins[1] * basins[2] << endl;
    return 0;
}
