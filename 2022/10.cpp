#include <bits/stdc++.h>

using namespace std;

int signalStrength(int cycle, int x)
{
    if (cycle >= 20 && (cycle - 20) % 40 == 0)
    {
        return cycle * x;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    int x = 1;
    int cycle = 0;
    int s = 0;
    vector<bool> screen(40 * 6, false);
    while (true)
    {
        string op;
        cin >> op;
        if (op == "noop")
        {
            if (abs(x % 40 - cycle % 40) < 2)
                screen[cycle] = true;
            cycle++;
            s += signalStrength(cycle, x);
        }
        else if (op == "end")
        {
            break;
        }
        else if (op == "addx")
        {
            int c;
            cin >> c;
            if (abs(x % 40 - cycle % 40) < 2)
                screen[cycle] = true;
            cycle++;
            s += signalStrength(cycle, x);
            if (abs(x % 40 - cycle % 40) < 2)
                screen[cycle] = true;
            cycle++;
            s += signalStrength(cycle, x);
            x += c;
        }
    }

    cout << s << endl;
    for (int i = 0; i < 40 * 6; i++)
    {
        if (i % 40 == 0)
        {
            cout << endl;
        }
        cout << (screen[i] ? '#' : '.');
    }

    return 0;
}
