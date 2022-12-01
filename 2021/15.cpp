#include <bits/stdc++.h>

using namespace std;

struct queueItem
{
    int x;
    int y;
    int cost;
    bool operator<(const queueItem &a) const
    {
        return cost < a.cost;
    }
};

struct CompareCost
{
    bool operator()(queueItem const &a, queueItem const &b) const
    {
        return b.cost < a.cost;
    }
};

int main(int argc, char const *argv[])
{
    vector<string> map;
    while (true)
    {
        string str;
        cin >> str;
        int len = str.size();
        if (str == "exit")
            break;
        for (int i = len; i < 5 * len; i++)
        {
            str += str[i - len] == '9' ? '1' : str[i - len] + 1;
        }
        map.push_back(str);
    }
    int sizeX = map.size();
    int sizeY = map[0].size();
    for (int i = sizeX; i < 5 * sizeX; i++)
    {
        map.push_back("");
        for (int j = 0; j < 5 * sizeY; j++)
        {
            map[map.size() - 1] += map[map.size() - sizeX - 1][j] + 1;
            if (map[map.size() - 1][j] > '9')
            {
                map[map.size() - 1][j] = '1';
            }
        }
    }

    priority_queue<queueItem, vector<queueItem>, CompareCost> q;
    queueItem a;
    a.x = 0;
    a.y = 0;
    a.cost = 0;
    q.push(a);

    int minCost = INT32_MAX;
    while (q.size() > 0)
    {
        queueItem t = q.top();
        q.pop();
        if (map[t.x][t.y] == '-')
            continue;
        map[t.x][t.y] = '-';
        if (t.x == map.size() - 1 && t.y == map[0].size() - 1)
        {
            minCost = min(minCost, t.cost);
            cout << minCost << endl;
        }
        int smerX[] = {1, 0, -1, 0};
        int smerY[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            if (t.x + smerX[i] < map.size() && t.y + smerY[i] < map[0].size() && t.x + smerX[i] >= 0 && t.y + smerY[i] >= 0)
            {
                queueItem a;
                a.x = t.x + smerX[i];
                a.y = t.y + smerY[i];
                if (map[a.x][a.y] != '-')
                {
                    a.cost = t.cost + (map[a.x][a.y] - '0');
                    q.push(a);
                }
            }
        }
    }
    cout << minCost << endl;
    return 0;
}
