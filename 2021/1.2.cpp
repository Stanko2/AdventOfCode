#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int increased = -1;
    int lastSum = -1;
    deque<int> posledne;
    while (true)
    {
        int a;
        cin >> a;
        posledne.push_back(a);
        if (a == -1)
            break;
        if (posledne.size() < 3)
            continue;
        if (posledne.size() > 3)
            posledne.pop_front();
        int sum = posledne[0] + posledne[1] + posledne[2];
        if (sum > lastSum)
            increased++;
        lastSum = sum;
    }

    cout << "increased: " << increased << endl;
    return 0;
}
