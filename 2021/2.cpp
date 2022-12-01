#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string cmd;
    int arg;
    int y = 0, x = 0;
    while (true)
    {
        cin >> cmd >> arg;
        if (cmd == "down")
        {
            y += arg;
        }
        else if (cmd == "up")
        {
            y -= arg;
        }
        else if (cmd == "forward")
        {
            x += arg;
        }
        else
        {
            break;
        }
    }
    cout << "Solution: " << x * y << endl;
    return 0;
}
