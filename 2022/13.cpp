#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    vector<Node *> elements;
    bool isNum = false;
    int val = -1;
    Node *p;

    Node(int val, bool isNum, Node *p)
    {
        this->val = val;
        this->isNum = isNum;
        this->p = p;
    }

    Node(Node *element)
    {
        val = -1;
        isNum = false;
        elements.push_back(element);
    }

    void addItem(Node *item)
    {
        elements.push_back(item);
    }

    bool equal(Node *&a)
    {
        if (isNum && a->isNum)
            return val == a->val;
        else if (isNum)
        {
            Node *thisList = new Node(this);
            return thisList->equal(a);
        }
        else if (a->isNum)
        {
            Node *aList = new Node(a);
            return equal(aList);
        }
        else
        {
            if (elements.size() != a->elements.size())
                return false;
            for (int i = 0; i < elements.size(); i++)
            {
                if (!elements[i]->equal(a->elements[i]))
                    return false;
            }
            return true;
        }
    }

    bool compare(Node *&a)
    {
        if (isNum && a->isNum)
        {
            return val < a->val;
        }
        else if (isNum)
        {
            Node *thisList = new Node(this);
            return thisList->compare(a);
        }
        else if (a->isNum)
        {
            Node *aList = new Node(a);
            return compare(aList);
        }
        for (int i = 0; i < min(elements.size(), a->elements.size()); i++)
        {
            if (elements[i]->equal(a->elements[i]))
                continue;
            return elements[i]->compare(a->elements[i]);
        }
        return elements.size() <= a->elements.size();
    }
};

bool is_number(const string &s)
{
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it))
        ++it;
    return !s.empty() && it == s.end();
}

int main(int argc, char const *argv[])
{
    fstream in;
    in.open("sample13");
    Node *root = new Node(-1, false, nullptr);
    Node *curr = root;
    while (!in.eof())
    {
        string s;
        in >> s;
        if (s == "[")
        {
            Node *x = new Node(-1, false, curr);
            curr->addItem(x);
            curr = x;
        }
        else if (s == "]")
        {
            curr = curr->p;
        }
        else if (is_number(s))
        {
            Node *x = new Node(stoi(s), true, curr);
            curr->elements.push_back(x);
        }
    }

    long long dobre = 0;
    for (int i = 0; i < root->elements.size(); i += 2)
    {
        if (root->elements[i]->compare(root->elements[i + 1]))
        {
            dobre += i / 2 + 1;
        }
    }

    cout << dobre << endl;
    return 0;
}
