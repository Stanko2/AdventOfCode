#include <bits/stdc++.h>

using namespace std;

struct queueItem
{
    set<string> visitedSmall;
    string current;
    bool smallTwice;
    vector<string> trace;
};

int main(int argc, char const *argv[])
{
    map<string, set<string>> g;
    while (true)
    {
        string a, b;
        cin >> a >> b;
        if (a == "exit")
            break;
        g[a].insert(b);
        g[b].insert(a);
    }

    queue<queueItem> q;
    queueItem a = queueItem();
    a.current = "start";
    a.smallTwice = false;
    a.visitedSmall = set<string>();
    a.trace = vector<string>();
    q.push(a);
    int roads = 0;

    while (!q.empty())
    {
        queueItem p = q.front();
        q.pop();
        if (p.current == "end")
        {
            roads++;
            for (string i : p.trace)
                cout << i << ",";
            cout << p.smallTwice;
            cout << endl;
            continue;
        }
        if (p.current[0] > 'Z')
        {
            p.visitedSmall.insert(p.current);
        }
        string curr = p.current;
        p.trace.push_back(p.current);

        for (auto &i : g[p.current])
        {
            if (i == "start")
                continue;
            p.current = i;
            if (p.current == "end")
            {
                q.push(p);
                continue;
            }
            if (i[0] < 'a')
            {
                q.push(p);
                continue;
            }

            if (p.visitedSmall.count(i) == 0)
            {
                q.push(p);
            }
            else if (!p.smallTwice)
            {
                p.smallTwice = true;
                q.push(p);
                p.smallTwice = false;
            }
        }
    }

    cout << "roads: " << roads << endl;

    return 0;
}
