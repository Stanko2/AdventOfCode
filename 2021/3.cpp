#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int counts[12];
    int n = 0;
    for (int i = 0; i < 12; i++)
    {
        counts[i] = 0;
    }
    while (true)
    {
        string str;
        cin >> str;
        if (str == "exit")
            break;
        n++;
        for (int i = 0; i < str.length(); i++)
        {
            if (str[i] == '1')
                counts[i]++;
        }
    }

    int min = 0;
    int max = 0;
    int mul = 1;
    for (int i = 11; i >= 0; i--)
    {
        if (n - counts[i] < counts[i])
        {
            max += mul;
        }
        else
        {
            min += mul;
        }
        mul *= 2;
    }
    cout << max * min << endl;
    return 0;
}