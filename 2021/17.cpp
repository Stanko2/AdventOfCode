#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int count = 0;
    for (int y = -500; y < 500; y++)
    {
        for (int x = 0; x < 1000; x++)
        {
            int e = y;
            int f = x;

            if (c <= e && e <= d && f >= a && f <= b)
            {
                count++;
                // cout << x << " " << y << endl;
                continue;
            }

            for (int i = 1; i < 1000; i++)
            {
                e += y - i;

                f += max(0, x - i);
                if (c <= e && e <= d && f >= a && f <= b)
                {
                    count++;
                    // cout << x << " " << y << endl;
                    break;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
