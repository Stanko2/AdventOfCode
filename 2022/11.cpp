#include <bits/stdc++.h>

using namespace std;

long long mod;

struct Monkey
{
    queue<long long> items;
    function<long long(long long)> func;
    int testNum;
    Monkey *ifTrue;
    Monkey *ifFalse;
    int inspected = 0;
    Monkey(vector<long long> _items, int _testNum, function<long long(long long)> _func, Monkey *_ifTrue, Monkey *_ifFalse)
    {
        testNum = _testNum;
        func = _func;
        ifTrue = _ifTrue;
        ifFalse = _ifFalse;
        for (auto i : _items)
            items.push(i);
    }

    void MakeTurn()
    {
        while (!items.empty())
        {
            long long item = items.front();
            items.pop();
            inspected++;
            item = func(item) % mod;
            if (item % testNum == 0)
                ifTrue->items.push(item);
            else
                ifFalse->items.push(item);
        }
    }
};

int main(int argc, char const *argv[])
{
    Monkey monkeys[8] = {
        Monkey(
            {98, 97, 98, 55, 56, 72}, 11, [](long long a)
            { return a * 13; },
            &monkeys[4], &monkeys[7]),
        Monkey(
            {73, 99, 55, 54, 88, 50, 55}, 17, [](long long a)
            { return a + 4; },
            &monkeys[2], &monkeys[6]),
        Monkey(
            {67, 98}, 5, [](long long a)
            { return a * 11; },
            &monkeys[6], &monkeys[5]),
        Monkey(
            {82, 91, 92, 53, 99}, 13, [](long long a)
            { return a + 8; },
            &monkeys[1], &monkeys[2]),
        Monkey(
            {52, 62, 94, 96, 52, 87, 53, 60}, 19, [](long long a)
            { return a * a; },
            &monkeys[3], &monkeys[1]),
        Monkey(
            {94, 80, 84, 79}, 2, [](long long a)
            { return a + 5; },
            &monkeys[7], &monkeys[0]),
        Monkey(
            {89}, 3, [](long long a)
            { return a + 1; },
            &monkeys[0], &monkeys[5]),
        Monkey(
            {70, 59, 63}, 7, [](long long a)
            { return a + 3; },
            &monkeys[4], &monkeys[3]),
    };
    // Monkey monkeys[4] = {
    //     Monkey(
    //         {79, 98}, 23, [](long long a)
    //         { return a * 19; },
    //         &monkeys[2], &monkeys[3]),
    //     Monkey(
    //         {54, 65, 75, 74}, 19, [](long long a)
    //         { return a + 6; },
    //         &monkeys[2], &monkeys[0]),
    //     Monkey(
    //         {79, 60, 97}, 13, [](long long a)
    //         { return a * a; },
    //         &monkeys[1], &monkeys[3]),
    //     Monkey(
    //         {74}, 17, [](long long a)
    //         { return a + 3; },
    //         &monkeys[0], &monkeys[1])};

    mod = 1;
    for (int i = 0; i < size(monkeys); i++)
    {
        mod *= monkeys[i].testNum;
    }

    for (int i = 0; i < 10000; i++)
    {
        for (int j = 0; j < size(monkeys); j++)
        {
            monkeys[j].MakeTurn();
        }
    }

    for (int i = 0; i < size(monkeys); i++)
    {
        cout << monkeys[i].inspected << endl;
    }
    return 0;
}
