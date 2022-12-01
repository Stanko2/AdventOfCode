#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> cisla;
    string str;
    cin >> str;

    stringstream ss(str);

    for (int i; ss >> i;)
    {
        cisla.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }

    vector<vector<vector<int>>> stav;
    int n = 0;
    while (true)
    {
        char str = cin.peek();
        if (str == -1)
            break;
        stav.push_back(vector<vector<int>>());
        for (int i = 0; i < 5; i++)
        {
            stav[n].push_back(vector<int>(5));
            for (int j = 0; j < 5; j++)
            {
                cin >> stav[n][i][j];
            }
        }
        n++;
    }
    bool plne[n - 1];
    int pocetPlnych = 0;
    for (int i = 0; i < n - 1; i++)
        plne[i] = false;
    for (auto &cislo : cisla)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (plne[i])
                continue;
            for (int j = 0; j < 5; j++)
            {
                bool riadokPlny = true;
                bool stlpecPlny = true;
                for (int k = 0; k < 5; k++)
                {
                    if (stav[i][j][k] == cislo)
                    {
                        stav[i][j][k] = -1;
                    }
                    if (stav[i][j][k] != -1)
                        riadokPlny = false;
                    if (stav[i][k][j] != -1)
                        stlpecPlny = false;
                }
                if (riadokPlny || stlpecPlny)
                {
                    plne[i] = true;
                    pocetPlnych++;
                    if (pocetPlnych == n - 1)
                    {
                        cout << "cislo: " << cislo << endl;
                        for (int j = 0; j < 5; j++)
                        {
                            for (int k = 0; k < 5; k++)
                            {
                                cout << stav[i][j][k] << " ";
                            }
                            cout << endl;
                        }
                    }
                    break;
                }
            }
        }
    }

    return 0;
}
