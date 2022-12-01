#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int pole[1000][1000];
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
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
    }

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (pole[i][j] > 1)
            {
                prekrizenia++;
            }
        }
    }

    cout << "prekrizenia: " << prekrizenia << endl;
    return 0;
}
