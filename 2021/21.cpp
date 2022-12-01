#include <bits/stdc++.h>

using namespace std;

struct Player
{
    int pos = 0;
    int score = 0;
};
struct gameState
{
    Player first;
    Player second;
    bool firstOnTurn = true;
    bool operator==(const gameState &s) const
    {
        return s.first.pos == first.pos && s.second.pos == second.pos && s.first.score == first.score && s.second.score == second.score && firstOnTurn == s.firstOnTurn;
    }
};

struct hash_fn
{
    size_t operator()(const gameState &s) const
    {
        string str = to_string(s.first.pos) + to_string(s.second.pos) + to_string(s.first.score) + to_string(s.second.score) + "f" + to_string(s.firstOnTurn);
        hash<string> h;
        return h(str);
    }
};

unordered_map<gameState, pair<long long, long long>, hash_fn> states;

pair<long long, long long> getScores(gameState state)
{
    if (states.find(state) != states.end())
    {
        return states[state];
    }
    Player *p = state.firstOnTurn ? &state.first : &state.second;
    pair<long long, long long> res;
    for (int i = 1; i < 4; i++)
    {
        gameState a;
        a.firstOnTurn = !state.firstOnTurn;
        Player *p2 = state.firstOnTurn ? &a.first : &a.second;
        p2->pos = (p->pos + i) % 10;
        p2->score += p2->pos + 1;
        if (p2->score >= 21)
        {
            if (state.firstOnTurn)
                res.first++;
            else
                res.second++;
        }
        else
        {
            pair<long long, long long> b = getScores(a);
            res.first += b.first;
            res.second += b.second;
        }
    }
    states[state] = res;
    return res;
}

int main(int argc, char const *argv[])
{
    int currDice = 1;
    Player firstPlayer;
    Player secondPlayer;
    cin >> firstPlayer.pos >> secondPlayer.pos;
    firstPlayer.pos--;
    secondPlayer.pos--;
    // int diceCount = 0;
    // Player *hasTurn = &firstPlayer;
    // while (max(firstPlayer.score, secondPlayer.score) < 1000)
    // {
    //     int num = 0;
    //     for (int i = 0; i < 3; i++)
    //     {
    //         num += currDice;
    //         currDice++;
    //         if (currDice > 100)
    //         {
    //             currDice = 1;
    //         }
    //     }
    //     diceCount += 3;
    //     hasTurn->pos = (hasTurn->pos + num) % 10;
    //     hasTurn->score += hasTurn->pos + 1;
    //     hasTurn = hasTurn == &firstPlayer ? &secondPlayer : &firstPlayer;
    // }
    // cout << min(firstPlayer.score, secondPlayer.score) << endl;
    // cout << diceCount << endl;
    gameState s;
    s.first = firstPlayer;
    s.second = secondPlayer;
    pair<long long, long long> p = getScores(s);
    cout << p.first << " " << p.second << endl;
    return 0;
}
