#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    map<int, long long> seaLanterns = {
        {0, 0},
        {1, 0},
        {2, 0},
        {3, 0},
        {4, 0},
        {5, 0},
        {6, 0},
        {7, 0},
        {8, 0}};
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        seaLanterns[a]++;
    }

    for (int day = 0; day < 256; day++)
    {
        long long nuly = seaLanterns[0];
        for (int i = 1; i < 9; i++)
        {
            seaLanterns[i - 1] = seaLanterns[i];
        }
        seaLanterns[6] += nuly;
        seaLanterns[8] = nuly;
    }

    long long count = 0;
    for (auto &i : seaLanterns)
    {
        count += i.second;
    }

    cout << "seaLanterns: " << count << endl;
    return 0;
}
