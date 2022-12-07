#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<stack<char>> s(n);
    for (int i = 0; i < n; i++)
    {
        string a;
        cin >> a;
        for (char j : a)
            s[i].push(j);
    }
    while (true)
    {
        int a, b, c;
        cin >> a;
        if (a == -1)
            break;
        cin >> b >> c;
        stack<char> t;
        for (int i = 0; i < a; i++)
        {
            char x = s[b - 1].top();
            s[b - 1].pop();
            t.push(x);
        }
        while (!t.empty())
        {
            s[c - 1].push(t.top());
            t.pop();
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << s[i].top();
    }
    cout << endl;
    return 0;
}
