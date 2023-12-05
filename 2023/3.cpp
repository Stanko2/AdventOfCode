#include<bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    long long ans = 0;
    vector<string> in;
    while (true)
    {
        string s;
        cin >> s;
        if(s == "end") break;
        in.push_back(s);
    }

    vector<vector<int>> isPart(in.size(), vector<int>(in[0].size(), false));
    set<pair<int, int>> gears;
    int dirX[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    int dirY[8] = {1, 1, 0, -1, -1, -1, 0, 1};
    for (int i = 0; i < in.size(); i++)
    {
        for (int j = 0; j < in[0].size(); j++)
        {
            for (int k = 0; k < 8; k++)
            {
                int x = i + dirX[k];
                int y = j + dirY[k];
                if(x >= 0 && x < in.size() && y >= 0 && y < in[0].size()){
                    if(in[x][y] != '.' && !isdigit(in[x][y])){
                        isPart[i][j] = true;
                        break;
                    }
                }
            }
            if (in[i][j] == '*'){
                gears.insert({i, j});
            }
        }
    }

    for (int i = 0; i < in.size(); i++)
    {
        string curr = "";
        bool hasPart = false;
        for (int j = 0; j < in[0].size(); j++)
        {
            if(isdigit(in[i][j])){
                curr += in[i][j];
                if(isPart[i][j]){
                    hasPart = true;  
                }
            }
            else if(curr != ""){
                if(hasPart)
                    ans+= stoi(curr);
                curr = "";
                hasPart = false;
            }
        }
        if(curr != "" && hasPart)
            ans+= stoi(curr);
    }

    cout << ans << endl;
    ans = 0;
    for (auto &i : gears)
    {
        int num1 = 0, num2 = 0;
        for (int j = 0; j < 8; j++)
        {
            int x = i.first + dirX[j];
            int y = i.second + dirY[j];
            if(x >= 0 && x < in.size() && y >= 0 && y < in[0].size()){
                if(isdigit(in[x][y])){
                    int a = y, b = y;
                    while (a > 0 && isdigit(in[x][a-1])) a--;
                    while (b < in[0].size() -1 && isdigit(in[x][b+1])) b++;
                    int curr = stoi(in[x].substr(a, b - a + 1));
                    if(num1 == 0 && num2 != curr)
                        num1 = curr;
                    else if(num1 != curr && num2 == 0)
                        num2 = curr;
                    else if (num1 != curr && num2 != curr) {
                        num1 = 0;
                        break;
                    }
                }
            }

        }
        if(num1 > 0 && num2 > 0){
            ans+= num1 * num2;
        }
    }
    
    cout << ans << endl;
    return 0;
}
