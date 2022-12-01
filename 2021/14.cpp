#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string str;
    int n;
    cin >> str >> n;
    map<string, char> replaces;
    for (int i = 0; i < n; i++)
    {
        string s;
        char a;
        cin >> s >> a;
        replaces[s] = a;
    }
    map<string, long long> pairs;
    map<char, long long> counts;
    for (char i = 'A'; i <= 'Z'; i++)
        counts[i] = 0;

    for (int q = 0; q < str.size() - 1; q++)
    {
        counts[str[q]]++;
        if (pairs.find(str.substr(q, 2)) == pairs.end())
        {
            pairs[str.substr(q, 2)] = 1;
        }
        else
            pairs[str.substr(q, 2)]++;
    }
    counts[str[str.size() - 1]]++;

    for (int i = 0; i < 40; i++)
    {
        map<string, long long> newPairs;
        for (auto i : pairs)
        {
            string a = "";
            if (replaces.find(i.first) != replaces.end())
            {
                a += i.first[0];
                a += replaces[i.first];
                counts[replaces[i.first]] += i.second;
                if (newPairs.find(a) == newPairs.end())
                {
                    newPairs[a] = i.second;
                }
                else
                {
                    newPairs[a] += i.second;
                }
                a.erase(0, 1);
                a += i.first[1];
                if (newPairs.find(a) == newPairs.end())
                {
                    newPairs[a] = i.second;
                }
                else
                {
                    newPairs[a] += i.second;
                }
                pairs[i.first] = 0;
            }
        }

        for (auto i : newPairs)
        {
            if (pairs.find(i.first) == pairs.end())
            {
                pairs[i.first] = i.second;
            }
            else
                pairs[i.first] += i.second;
        }
    }
    long long minimum = LONG_LONG_MAX;
    long long maximum = 0;
    for (auto i : counts)
    {
        if (i.second > maximum)
            maximum = i.second;
        if (i.second < minimum && i.second > 0)
            minimum = i.second;
    }

    cout << maximum - minimum << endl;
    return 0;
}
