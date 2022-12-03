#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<string> map;
    while (true)
    {
        string a;
        cin >> a;
        if (a == "end")
            break;
        map.push_back(a);
    }
    int moved = 1;
    int step = 0;
    while (moved > 0)
    {
        vector<string> newMap = map;
        moved = 0;
        for (int i = 0; i < map.size(); i++)
        {
            for (int j = map[i].size() - 1; j >= 0; j--)
            {
                int next = (j + 1) % map[i].size();
                if (map[i][j] == '>' && map[i][next] == '.')
                {
                    newMap[i][j] = '.';
                    newMap[i][next] = '>';
                    moved++;
                }
            }
        }
        map = newMap;
        for (int i = 0; i < map.size(); i++)
        {
            for (int j = map[i].size(); j >= 0; j--)
            {
                int next = (i + 1) % map.size();
                if (map[i][j] == 'v' && map[next][j] == '.')
                {
                    newMap[i][j] = '.';
                    newMap[next][j] = 'v';
                    moved++;
                }
            }
        }
        map = newMap;

        step++;
    }
    cout << step << endl;
    return 0;
}
