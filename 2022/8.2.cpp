#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mapa;

int getScore(int r, int c)
{
    int score = 0;
    int total = 1;
    int h = 0;
    for (int j = c + 1; j < mapa[0].size(); j++)
    {
        score++;
        if (mapa[r][j] >= mapa[r][c])
            break;
    }

    h = 0;
    total *= score;
    score = 0;
    for (int j = c - 1; j >= 0; j--)
    {
        score++;
        if (mapa[r][j] >= mapa[r][c])
            break;
    }

    h = 0;
    total *= score;
    score = 0;
    for (int j = r + 1; j < mapa.size(); j++)
    {
        score++;
        if (mapa[j][c] >= mapa[r][c])
            break;
    }

    h = 0;
    total *= score;
    score = 0;
    for (int j = r - 1; j >= 0; j--)
    {
        score++;
        if (mapa[j][c] >= mapa[r][c])
            break;
    }

    total *= score;
    return total;
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    mapa.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            mapa[i][j] = x - '0';
        }
    }

    int score = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            score = max(getScore(i, j), score);
        }
    }

    // cout << getScore(4, 1) << endl;
    cout << score << endl;
    return 0;
}
