#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<ll> vll;
typedef vector<pair<ll, ll>> vpll;

struct Interval {
    ll fromStart;
    ll toStart;
    ll range;
    Interval(ll fromStart, ll toStart, ll range) : fromStart(fromStart), toStart(toStart), range(range) {}

    bool isInRange(ll x) {
        return x >= fromStart && x <= fromStart + range;
    }

    ll getMapped(ll x) {
        ll i = x - fromStart;
        return toStart + i;
    }
};

void mapValues(deque<Interval> &intervaly, vector<ll> &values) {
    for (int i = 0; i < values.size(); i++)
    {
        for (int j = 0; j < intervaly.size(); j++)
        {
            if (intervaly[j].isInRange(values[i])) {
                values[i] = intervaly[j].getMapped(values[i]);
                break;
            }
        }
    }
}

vpll mapRanges(deque<Interval> &intervaly, vpll &values) {
    vpll result;
    int i = 0;
    while (i < values.size())
    {
        bool found = false;
        for (auto &j : intervaly){
            if (j.isInRange(values[i].first)) {
                ll mapped = j.getMapped(values[i].first);
                if (j.range < values[i].second){
                    result.push_back({mapped, j.range});
                    values[i].first += j.range;
                    values[i].second -= j.range;
                } else {
                    result.push_back({mapped, values[i].second});
                    i++;
                    found = true;
                    break;
                }
            } 
        }
        if (!found) {
            result.push_back(values[i]);
            i++;
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    char* s = new char[1000000];
    cin.getline(s, 1000000);
    string str(s);
    delete[] s;
    str = str.substr(str.find(": ") + 2, str.size() - str.find(": ") - 2);
    stringstream ss(str);
    vector<ll> seeds;
    vpll seedIntervals;
    while(!ss.eof()){
        ll x, y;
        ss >> x >> y;
        seeds.push_back(x);
        seeds.push_back(y);
        seedIntervals.push_back({x, y});
        cout << x << endl;
    }
    s = new char[1000000];
    cin.getline(s, 1000000);
    str = string(s);
    delete[] s;
    while (true)
    {
        char* s = new char[1000000];
        cin.getline(s, 1000000);
        str = string(s);
        delete[] s;
        if (str == "end") break;
        deque<Interval> intervals;
        while (str != "")
        {
            stringstream ss(str);
            ll a, b, c;
            ss >> a >> b >> c;
            intervals.push_back(Interval(b, a, c));
            s = new char[1000000];
            cin.getline(s, 1000000);
            str = string(s);
            delete[] s;
        }
        intervals.pop_front();
        mapValues(intervals, seeds);
        seedIntervals = mapRanges(intervals, seedIntervals);
    }
    
    sort(seeds.begin(), seeds.end());
    cout << seeds[0] << endl;
    return 0;
}
