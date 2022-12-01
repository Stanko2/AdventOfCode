#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> positions;
    int n;
    cin >> n;
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        positions.push_back(a);
        if (a > max)
            max = a;
    }
    long long minCost = INT64_MAX;
    for (int i = 0; i <= max; i++)
    {
        long long cost = 0;
        for (int j = 0; j < n; j++)
        {
            int x = abs(positions[j] - i);
            cost += x * (x + 1) / 2;
        }
        if (cost < minCost)
        {
            minCost = cost;
        }
    }
    cout << "minCost: " << minCost << endl;
    return 0;
}
