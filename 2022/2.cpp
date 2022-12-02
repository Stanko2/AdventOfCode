#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int score = 0;
    map<string, string> m = {
        {"X", "A"}, // Rock
        {"Y", "B"}, // Paper
        {"Z", "C"}  // Scissors
    };

    while (true)
    {
        string a, b;
        cin >> a;
        if (a == "end")
            break;
        cin >> b;
        b = m[b];
        score += b[0] - 'A' + 1;
        if (a == b)
            score += 3;
        else if (a == "A" && b == "B")
            score += 6;
        else if (a == "B" && b == "C")
            score += 6;
        else if (a == "C" && b == "A")
            score += 6;
    }
    cout << score << endl;
    return 0;
}
