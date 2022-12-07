#include <bits/stdc++.h>

using namespace std;

long long output = 0;
long long maxSize = LONG_LONG_MAX;
long long needToFree = LONG_LONG_MAX;
class Directory
{
public:
    map<string, Directory *> dirs;
    map<string, int> files;
    Directory *parent;
    Directory()
    {
        this->dirs = map<string, Directory *>();
        this->files = map<string, int>();
    }

    long long get_size()
    {
        long long s = 0;
        for (auto i : files)
            s += i.second;
        for (auto i : dirs)
            s += i.second->get_size();
        if (s < 100000)
            output += s;
        if (s > needToFree)
        {
            maxSize = min(maxSize, s);
        }
        return s;
    }
};

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    output = 0;
    Directory *root = new Directory();
    Directory *curr = root;
    while (true)
    {
        if (s == "$end")
            break;
        string a, b;
        cin >> a;
        if (a == "ls")
        {
            while (true)
            {
                cin >> s;
                if (s == "$" || s == "$end")
                    break;
                cin >> b;
                if (s == "dir")
                {
                    curr->dirs[b] = new Directory();
                    curr->dirs[b]->parent = curr;
                }
                else
                    curr->files[b] = stoi(s);
            }
        }
        else if (a == "cd")
        {
            cin >> b;
            if (b == "/")
                curr = root;
            else if (b == "..")
                curr = curr->parent;
            else
                curr = curr->dirs[b];

            cin >> s;
        }
    }

    needToFree = root->get_size() - 40000000;
    root->get_size();
    cout << output << endl;
    cout << maxSize << endl;
    return 0;
}
