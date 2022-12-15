#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    fstream in;
    in.open("in14");
    vector<vector<char>> mapa(200, vector<char>(1000, '.'));
    int maxY = 0;
    while (!in.eof())
    {
        string s;
        getline(in, s);
        istringstream line(s);
        pair<int, int> curr;
        line >> curr.second >> curr.first;
        maxY = max(maxY, curr.first);
        while (!line.eof())
        {
            pair<int, int> next;
            line >> next.second >> next.first;
            maxY = max(maxY, next.first);
            for (int i = min(next.first, curr.first); i <= max(next.first, curr.first); i++)
            {
                mapa[i][curr.second] = '#';
            }
            for (int i = min(next.second, curr.second); i <= max(next.second, curr.second); i++)
            {
                mapa[curr.first][i] = '#';
            }
            curr = next;
        }
    }

    for (int i = 0; i < mapa[2 + maxY].size(); i++)
    {
        mapa[2 + maxY][i] = '#';
    }

    int sandCnt = 0;
    while (mapa[0][500] == '.')
    {
        pair<int, int> sand = {0, 500};
        bool fits = true;
        while (true)
        {
            if (mapa[sand.first + 1][sand.second] == '.')
            {
                sand.first++;
            }
            else if (mapa[sand.first + 1][sand.second - 1] == '.')
            {
                sand.first++;
                sand.second--;
            }
            else if (mapa[sand.first + 1][sand.second + 1] == '.')
            {
                sand.first++;
                sand.second++;
            }
            else
            {
                mapa[sand.first][sand.second] = 'o';
                break;
            }
            if (sand.first + 1 >= mapa.size())
            {
                fits = false;
                break;
            }
        }
        if (!fits)
            break;
        sandCnt++;
    }

    cout << sandCnt << endl;
    return 0;
}
