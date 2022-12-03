#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int x = 0;
    int sum = 0;
    vector<set<char>> s;
    while (true)
    {
        string a;
        cin >> a;
        if (a == "end")
            break;
        s.push_back(set<char>());
        for (int i = 0; i < a.size(); i++)
            s[x].insert(a[i]);

        x++;
        if (x % 3 == 0)
        {
            set<char> temp;
            set_intersection(s[x - 1].begin(), s[x - 1].end(), s[x - 2].begin(), s[x - 2].end(), inserter(temp, temp.begin()));
            set<char> res;
            set_intersection(temp.begin(), temp.end(), s[x - 3].begin(), s[x - 3].end(), inserter(res, res.begin()));
            char h = *res.begin();
            if (isupper(h))
            {
                sum += h - 'A' + 27;
            }
            else
            {
                sum += h - 'a' + 1;
            }
        }
    }
    cout << sum << endl;
    return 0;
}
