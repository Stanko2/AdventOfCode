#include <bits/stdc++.h>

using namespace std;

string add(string a, string b)
{
    return '[' + a + ',' + b + ']';
}

bool explode(string &a)
{
    int d = 0;
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '[')
            d++;
        if (a[i] == ']')
            d--;
        if (!isdigit(a[i]))
            continue;
        pair<int, int> p = make_pair(-1, -1);
        int k = i;
        string s = "";
        while (isdigit(a[k]))
        {
            s += a[k];
            k++;
        }
        if (s != "")
            p.first = stoi(s);
        s = "";
        k++;
        while (isdigit(a[k]))
        {
            s += a[k];
            k++;
        }
        if (s != "")
            p.second = stoi(s);
        if (d == 5 && p.first != -1 && p.first != -1)
        {

            a = a.substr(0, i - 1) + '0' + a.substr(i + 4);
            for (int j = i - 2; j >= 0; j--)
            {
                if (isdigit(a[j]))
                {
                    int k = j;
                    string s = "";
                    while (isdigit(a[k]))
                    {
                        s += a[k];
                        k++;
                    }
                    a = a.substr(0, j) + to_string(p.first + stoi(s)) + a.substr(j + 1);
                    break;
                }
            }
            for (int j = i; j < a.size(); j++)
            {
                if (isdigit(a[j]))
                {
                    int k = j;
                    string s = "";
                    while (isdigit(a[k]))
                    {
                        s += a[k];
                        k++;
                    }
                    a = a.substr(0, j) + to_string(p.second + stoi(s)) + a.substr(j + 1, INT_MAX);
                    break;
                }
            }
            return true;
        }
    }
    return false;
}

bool split(string &a)
{
    for (int i = 0; i < a.size() - 1; i++)
    {
        if (isdigit(a[i]) && isdigit(a[i + 1]))
        {
            int c = 10 * (a[i] - '0') + a[i + 1] - '0';
            a = a.substr(0, i) + '[' + to_string(c / 2) + ',' + to_string((c + 1) / 2) + ']' + a.substr(i + 2, INT_MAX);
            return true;
        }
    }
    return false;
}

void reduce(string &a)
{
    while (true)
    {
        bool exploded = true;
        while (exploded)
            exploded = explode(a);
        bool splitted = split(a);
        if (!splitted)
            break;
    }
}

int main(int argc, char const *argv[])
{
    string a;
    cin >> a;
    reduce(a);
    while (true)
    {
        string b;
        cin >> b;
        if (b == "exit")
            break;
        reduce(b);
        a = add(a, b);
        reduce(a);
    }
    cout << a << endl;
    return 0;
}
