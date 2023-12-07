#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;

stringstream getLine() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    return ss;
}

int main(int argc, char const *argv[])
{
    vpll races;    
    stringstream ss = getLine();
    string s;
    ss >> s;
    ll ans = 1;
    while (!ss.eof())
    {
        ll x;
        ss >> x;
        races.push_back({x, 0});
    }
    ss = getLine();
    ss >> s;
    pair<ll, ll> race;
    for (auto &i : races)
    {
        ss >> i.second;
        race.first = stoll(to_string(race.first) + to_string(i.first));
        race.second = stoll(to_string(race.second) + to_string(i.second));
        int recordWays = 0;
        for (int j = 0; j < i.first; j++)
        {
            if ((i.first - j) * j > i.second) {
                recordWays++;
            }
        }
        ans *= recordWays;
    }
    



    cout << ans << endl;
    ll a = (-race.first + sqrt(race.first * race.first - 4 * race.second)) / -2;
    cout << ans << endl;
    ll b = (-race.first - sqrt(race.first * race.first - 4 * race.second)) / -2;
    cout << b - a << endl;
    return 0;
}
