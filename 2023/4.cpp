#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int ans = 0;
    map<int, int> cardsWon;
    while (true)
    {
        if(s == "end") break;
        assert(s == "Card");
        int id;
        cin >> id;
        char c;
        cin >> c;
        set<int> win;
        set<int> my;
        while(true){
            cin >> s;
            if(s == "|") break;
            win.insert(stoi(s));
        }
        while(true){
            cin >> s;
            if(s == "Card" || s == "end") break;
            my.insert(stoi(s));
        }
        vector<int> res;
        set_intersection(win.begin(), win.end(), my.begin(), my.end(), back_inserter(res));
        if (res.size() > 0)
            ans += 1 << (res.size() - 1);
        
        if(cardsWon.find(id) == cardsWon.end())
            cardsWon[id] = 1;
        for (int i = 1; i <= res.size(); i++)
        {
            if (cardsWon.find(id + i) == cardsWon.end())
                cardsWon[id + i] = 1 + cardsWon[id];
            else
                cardsWon[id + i]+= cardsWon[id];
        }
    }
    
    cout << ans << endl;

    ans = 0;
    for (auto i = cardsWon.begin(); i != cardsWon.end(); i++)
    {
        ans += i->second;
    }
    
    cout << ans << endl;
    return 0;
}
