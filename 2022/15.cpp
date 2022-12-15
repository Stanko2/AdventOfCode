#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int begin, end;
    Node *l, *r;
    bool val;
    bool lazy;
    Node(int _begin, int _end)
    {
        begin = _begin;
        end = _end;
        val = true;
        if (end - begin > 1)
        {
            int mid = (begin + end) / 2;
            l = new Node(begin, mid);
            r = new Node(mid, end);
        }
    }

    void propagate()
    {
        if (lazy)
        {
            lazy = false;
            if (l)
            {
                l->lazy = true;
                l->val = val;
            }
            if (r)
            {
                r->lazy = true;
                r->val = val;
            }
        }
    }

    void set(int b, int e, bool val)
    {
        if (end <= b || e < begin)
            return;
        if (b <= begin && e >= end)
        {
            this->val = val;
            lazy = true;
            return;
        }
        this->propagate();
        if (r)
            r->set(b, e, val);
        if (l)
            l->set(b, e, val);
    }
    int getEmpty()
    {
        if (end - begin == 1 && val)
            return begin;
        if (lazy && !val)
            return -1;

        if (l)
        {
            int x = l->getEmpty();
            if (x != -1)
                return x;
        }
        if (r)
        {
            int x = r->getEmpty();
            if (x != -1)
                return x;
        }
        return -1;
    }
};

void deleteTree(Node *node)
{
    if (node == NULL)
        return;

    deleteTree(node->l);
    deleteTree(node->r);

    delete node;
}

int main(int argc, char const *argv[])
{
    fstream in;
    in.open("in15");
    set<int> positions;
    int y = 2000000;
    vector<pair<pair<int, int>, int>> sensors;
    while (!in.eof())
    {
        pair<int, int> s, b;
        in >> s.first >> s.second >> b.first >> b.second;
        int dist = abs(s.first - b.first) + abs(s.second - b.second);
        sensors.push_back({s, dist});
        int remainingDist = dist - abs(y - s.second);
        if (remainingDist <= 0)
            continue;
        for (int i = -remainingDist; i <= remainingDist; i++)
        {
            if (b.second == y && s.first + i == b.first)
                continue;
            positions.insert(s.first + i);
        }
    }
    cout << positions.size() << endl;
    int maxdim = 4000000;
    Node *row = new Node(0, maxdim);
    for (int i = 0; i < maxdim; i++)
    {
        row->set(0, maxdim + 1, true);
        for (auto &s : sensors)
        {
            int dist = s.second - abs(s.first.second - i);
            if (dist < 0)
                continue;
            row->set(s.first.first - dist, s.first.first + dist + 1, false);
        }
        int empty = row->getEmpty();
        if (empty != -1)
        {
            long long out = (long long)empty * 4000000 + (long long)i;
            cout << i << ' ' << empty << ": " << out << endl;
        }
    }

    return 0;
}
