#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    deque<char> p;
    for (int i = 0; i < 13; i++)
    {
        p.push_back(s[i]);
    }
    for (int i = 14; i < s.size(); i++)
    {
        p.push_back(s[i]);
        set<char> s;
        for (auto a : p)
        {
            s.insert(a);
        }
        if (s.size() == 14)
        {
            cout << i + 1 << endl;
            break;
        }
        p.pop_front();
    }

    return 0;
}
