#include <bits/stdc++.h>

using namespace std;

bool isBounded(int x, int y, int z)
{
    return x >= 0 && x < 100 && y >= 0 && y < 100 && z >= 0 && z < 100;
}

int main(int argc, char const *argv[])
{
    fstream in;
    in.open("in18");
    set<tuple<int, int, int>> cubes;
    while (!in.eof())
    {
        int x, y, z;
        in >> x >> y >> z;
        cubes.insert({x, y, z});
    }

    vector<vector<vector<bool>>> exterior(100, vector<vector<bool>>(100, vector<bool>(100, false)));
    int dirX[6] = {1, 0, 0, -1, 0, 0};
    int dirY[6] = {0, 1, 0, 0, -1, 0};
    int dirZ[6] = {0, 0, 1, 0, 0, -1};
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        if (exterior[get<0>(p)][get<1>(p)][get<2>(p)])
            continue;
        exterior[get<0>(p)][get<1>(p)][get<2>(p)] = true;
        for (int i = 0; i < 6; i++)
        {
            int newX = get<0>(p) + dirX[i];
            int newY = get<1>(p) + dirY[i];
            int newZ = get<2>(p) + dirZ[i];
            if (!isBounded(newX, newY, newZ))
                continue;
            if (!exterior[newX][newY][newZ] && cubes.find({newX, newY, newZ}) == cubes.end())
                q.push({newX, newY, newZ});
        }
    }

    int surface = 0;
    for (auto &cube : cubes)
    {
        for (int i = 0; i < 6; i++)
        {
            auto pos = make_tuple(get<0>(cube) + dirX[i], get<1>(cube) + dirY[i], get<2>(cube) + dirZ[i]);
            if (cubes.find(pos) == cubes.end() && (!isBounded(get<0>(pos), get<1>(pos), get<2>(pos)) || exterior[get<0>(pos)][get<1>(pos)][get<2>(pos)]))
            {
                surface++;
            }
        }
    }

    cout << surface << endl;
    return 0;
}
