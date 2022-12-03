#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int sum = 0;
    while (true)
    {
        string a;
        cin >> a;
        if (a == "end")
            break;
        set<char> first;
        char common;
        for (int i = 0; i < a.size() / 2; i++)
        {
            first.insert(a[i]);
        }
        for (int i = a.size() / 2; i < a.size(); i++)
        {
            if (first.find(a[i]) != first.end())
            {
                common = a[i];
                break;
            }
        }

        if (isupper(common))
        {
            sum += common - 'A' + 27;
        }
        else
        {
            sum += common - 'a' + 1;
        }
    }

    cout << sum << endl;
    return 0;
}
