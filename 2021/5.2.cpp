#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    const int gridSize = 1000;
    int pole[gridSize][gridSize];
    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            pole[i][j] = 0;
        }
    }
    int prekrizenia = 0;
    for (int i = 0; i < n; i++)
    {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 == x2)
        {
            for (int j = min(y1, y2); j < max(y1, y2) + 1; j++)
            {
                pole[x1][j]++;
            }
        }
        else if (y1 == y2)
        {
            for (int j = min(x1, x2); j < max(x1, x2) + 1; j++)
            {
                pole[j][y1]++;
            }
        }
        else
        {
            for (int j = 0; j < (max(x1, x2) - min(x1, x2)) + 1; j++)
            {
                if (y1 < y2)
                {
                    if (x1 < x2)
                    {
                        pole[x1 + j][y1 + j]++;
                    }
                    else
                    {
                        pole[x1 - j][y1 + j]++;
                    }
                }
                else
                {
                    if (x1 < x2)
                    {
                        pole[x1 + j][y1 - j]++;
                    }
                    else
                    {
                        pole[x1 - j][y1 - j]++;
                    }
                }
            }
        }
    }

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
        {
            if (pole[i][j] > 1)
            {
                prekrizenia++;
            }
            // cout << pole[j][i];
        }
        // cout << endl;
    }

    cout << "prekrizenia: " << prekrizenia << endl;
    return 0;
}
