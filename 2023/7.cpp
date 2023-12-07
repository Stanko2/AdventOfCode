#include<bits/stdc++.h>

using namespace std;


struct hand {
    int cards[5];
    int bet;
};

map<char, int> cardStrength = {
    {'J', 0},
    {'2', 1},
    {'3', 2},
    {'4', 3},
    {'5', 4},
    {'6', 5},
    {'7', 6},
    {'8', 7},
    {'9', 8},
    {'T', 9},
    {'Q', 11},
    {'K', 12},
    {'A', 13},
};

int getType(hand &h) {
    map<int, int> c;
    int numJokers = 0;
    for (int i = 0; i < 5; i++)
    {
        if (h.cards[i] == 0){
            numJokers++;
            continue;
        }
        if(c.find(h.cards[i]) == c.end()) {
            c[h.cards[i]] = 1;
        } else {
            c[h.cards[i]]++;
        }
    }
    if (c.size() == 1 || c.size() == 0){
        return 1; // five of a kind
    }
    if (c.size() == 2) {
        for (auto &i : c)
        {
            if (i.second + numJokers == 4) {
                return 2; // four of a kind
            }
            if (i.second == 3) {
                if (numJokers == 0)
                    return 3; // full house
                else if (numJokers == 1)
                    return 2; // four of a kind
            }
            if (i.second == 2 && numJokers == 1)
                return 3; // full house 2 + 1 joker
        }
    }
    if (c.size() == 3) {
        if (numJokers == 2)
            return 4; // three of a kind - 3 + 2 jokers
        for (auto &i : c)
        {
            if (i.second == 3) {
                return 4; // three of a kind - no jokers
            }
            if(i.second == 2 && numJokers == 1) {
                return 4; // three of a kind - 2 + 1 joker
            }
        }
        if (numJokers == 0)
            return 5; // two pair - no jokers
    }
    if(c.size() == 4){
        return 6; // one pair - no jokers or 1 joker
    }
    return 7; // high card
}

bool compareCards(hand a, hand b) {
    if (getType(a) != getType(b)) {
        return getType(a) > getType(b);
    }
    int i = 0;
    while(a.cards[i] == b.cards[i]) {
        i++;
    }
    return a.cards[i] < b.cards[i];
}

int main(int argc, char const *argv[])
{
    string s;
    vector<hand> hands;
    while (true)
    {
        cin >> s;
        if (s == "end") break;
        int n;
        cin >> n;
        hand h;
        h.bet = n;
        for (int i = 0; i < 5; i++)
        {
            h.cards[i] = cardStrength[s[i]];    
        }
        hands.push_back(h);
    }

    sort(hands.begin(), hands.end(), compareCards);
    long long ans = 0;
    for (int i = 0; i < hands.size(); i++)
    {
        ans += hands[i].bet * (i + 1);
    }

    cout << ans << endl;
    return 0;
}
