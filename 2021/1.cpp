#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int increased = -1;
    int posledne = -1;
    while (true)
    {
        int a;
        cin >> a;
        if (a == -1)
            break;
        if (a > posledne)
            increased++;
        posledne = a;
    }

    cout << "increased: " << increased << endl;
    return 0;
}
