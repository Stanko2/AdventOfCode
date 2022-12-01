#include <bits/stdc++.h>

using namespace std;

struct Box
{
    int x1, y1, x2, y2, z1, z2;
    bool on;
    bool exists = true;

    long long getVolume()
    {
        return (x2 - x1 + 1) * (y2 - y1 + 1) * (z2 - z1 + 1);
    }
};

pair<int, int> null = make_pair(INT16_MAX, INT16_MAX);

pair<int, int> get_intersect(int a1, int a2, int b1, int b2)
{
    if (a1 < b1)
    {
        if (a2 < b1)
            return null;
        else
        {
            if (a2 < b2)
                return make_pair(b1, a2);
            else
                return make_pair(b1, b2);
        }
    }
    else
    {
        if (b2 < a1)
            return null;
        else
        {
            if (b2 < a2)
                return make_pair(a1, b2);
            else
                return make_pair(a1, a2);
        }
    }
}

Box box_intersection(Box a, Box b)
{
    Box res;
    pair<int, int> iX = get_intersect(a.x1, a.x2, b.x1, b.x2);
    res.x1 = iX.first;
    res.x2 = iX.second;

    pair<int, int> iY = get_intersect(a.y1, a.y2, b.y1, b.y2);
    res.y1 = iY.first;
    res.y2 = iY.second;

    pair<int, int> iZ = get_intersect(a.z1, a.z2, b.z1, b.z2);
    res.z1 = iZ.first;
    res.z2 = iZ.second;

    if (iX == null || iY == null || iZ == null)
    {
        res.exists = false;
    }

    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<Box> boxes;
    for (int i = 0; i < n; i++)
    {
        Box box;
        string str;
        cin >> str >> box.x1 >> box.x2 >> box.y1 >> box.y2 >> box.z1 >> box.z2;
        box.on = str == "on";
        vector<Box> added;
        for (auto &j : boxes)
        {
            Box intersection = box_intersection(box, j);
            if (!intersection.exists)
            {
                continue;
            }
            intersection.on = !j.on;
            added.push_back(intersection);/
        }
        for (auto &j : added)
            boxes.push_back(j);
        if (box.on)
            boxes.push_back(box);
    }
    unsigned long long on = 0;
    for (auto &i : boxes)
    {
        if (i.on)
        {
            on += i.getVolume();
        }
        else
        {
            on -= i.getVolume();
        }
    }

    cout << "on " << on << endl;
    return 0;
}
