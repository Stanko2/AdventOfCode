#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int score = 0;
    while (true)
    {
        string a, b;
        cin >> a;
        if (a == "end")
            break;
        cin >> b;
        if (b == "Y")
        {
            score += 3 + a[0] - 'A' + 1;
        }
        else if (b == "X")
        {
            if (a == "A")
                score += 3;
            else if (a == "B")
                score += 1;
            else if (a == "C")
                score += 2;
        }
        else
        {
            if (a == "A")
                score += 8;
            else if (a == "B")
                score += 9;
            else if (a == "C")
                score += 7;
        }
    }
    cout << score << endl;
    return 0;
}
