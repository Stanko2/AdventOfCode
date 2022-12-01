#include <bits/stdc++.h>

using namespace std;
char lineBreak;

char getPixel(int x, int y, deque<string> &img)
{
    if (y < 0 || y >= img.size())
        return lineBreak;
    if (x < 0 || x >= img[0].size())
        return lineBreak;
    return img[y][x];
}

deque<string> prepareImage(deque<string> img)
{
    deque<string> d;
    for (int i = 0; i < img.size(); i++)
        d.push_back(img[i]);
    d.push_back(string(img[0].size(), lineBreak));
    d.push_back(string(img[0].size(), lineBreak));
    d.push_back(string(img[0].size(), lineBreak));
    d.push_front(string(img[img.size() - 1].size(), lineBreak));
    d.push_front(string(img[img.size() - 1].size(), lineBreak));
    d.push_front(string(img[img.size() - 1].size(), lineBreak));
    for (int i = 0; i < d.size(); i++)
    {
        d[i] = string(3, lineBreak) + d[i] + string(3, lineBreak);
    }
    return d;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    int smerX[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    int smerY[9] = {-1, -1, -1, 0, 0, 0, 1, 1, 1};
    deque<string> img;
    while (true)
    {
        string line;
        cin >> line;
        if (line == "exit")
            break;
        img.push_back(line);
    }
    lineBreak = '.';
    for (int i = 0; i < 50; i++)
    {
        deque<string> newImg = prepareImage(img);
        for (int j = 0; j < newImg.size(); j++)
        {
            for (int k = 0; k < newImg[j].size(); k++)
            {
                int val = 0;
                for (int l = 0; l < 9; l++)
                {
                    val = getPixel(k + smerX[l] - 3, j + smerY[l] - 3, img) == '#' ? val + 1 : val;
                    val = val << 1;
                }
                val = val >> 1;
                newImg[j][k] = s[val];
            }
        }
        img = newImg;
        lineBreak = lineBreak == '.' ? s[0] : s[511];
    }

    int litPixels = 0;
    for (int i = 0; i < img.size(); i++)
    {
        for (int j = 0; j < img[i].size(); j++)
        {
            if (img[i][j] == '#')
            {
                litPixels++;
            }
        }
    }

    cout << "litPixels: " << litPixels << endl;
    return 0;
}
