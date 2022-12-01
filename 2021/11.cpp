#include <bits/stdc++.h>

using namespace std;

int octopuses[10][10];
set<pair<int, int>> flashed;
int flashCount = 0;

void flash(int x, int y)
{
    int smerX[] = {1, 1, 0, -1, -1, -1, 0, 1};
    int smerY[] = {0, 1, 1, 1, 0, -1, -1, -1};
    octopuses[x][y] = 0;
    flashCount++;
    flashed.insert(make_pair(x, y));
    for (int i = 0; i < 8; i++)
    {
        if (x + smerX[i] >= 0 && x + smerX[i] < 10 && y + smerY[i] >= 0 && y + smerY[i] < 10)
        {
            if (flashed.count(make_pair(x + smerX[i], y + smerY[i])) == 0)
            {
                octopuses[x + smerX[i]][y + smerY[i]]++;
                if (octopuses[x + smerX[i]][y + smerY[i]] > 9)
                {
                    flash(x + smerX[i], y + smerY[i]);
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        string str;
        getline(std::cin, str);
        for (int j = 0; j < 10; j++)
        {
            octopuses[i][j] = str[j] - '0';
        }
    }
    int i = 0;
    while (flashed.size() < 100)
    {
        flashed.clear();
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                if (flashed.count(make_pair(j, k)) == 0)
                {
                    octopuses[j][k]++;
                    if (octopuses[j][k] > 9)
                    {
                        flash(j, k);
                    }
                }
            }
        }

        cout << "--------------------------------" << endl;
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                cout << octopuses[j][k];
            }
            cout << endl;
        }
        i++;
    }

    cout << "All flashed: " << i << endl;
    cout << "Flashes: " << flashCount << endl;

    return 0;
}
