#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int out = 0;
    while (true)
    {
        string x;
        cin >> x;
        if (x == "end")
            break;
        int a = stoi(x), b, c, d;
        cin >> b >> c >> d;
        if (c >= a && d <= b)
            out++;
        else if (a >= c && b <= d)
            out++;
    }

    cout << out << endl;
    return 0;
}
