#include<bits/stdc++.h>

using namespace std;

int isDigitWord(string s, int i) {
    if(s.substr(i, 3) == "one") return 1;
    if(s.substr(i, 3) == "two") return 2;
    if(s.substr(i, 5) == "three") return 3;
    if(s.substr(i, 4) == "four") return 4;
    if(s.substr(i, 4) == "five") return 5;
    if(s.substr(i, 3) == "six") return 6;
    if(s.substr(i, 5) == "seven") return 7;
    if(s.substr(i, 5) == "eight") return 8;
    if(s.substr(i, 4) == "nine") return 9;
    return 0;
}

int main(int argc, char const *argv[])
{
    int ans = 0;
    while (true)
    {
        string s;
        cin >> s;
        if(s == "end") break;
        for (int i = 0; i < s.size(); i++)
        {
            if(isdigit(s[i])){
                ans+= (s[i] - '0') * 10;
                break;
            }
            
            if(isDigitWord(s, i)){
                ans+= isDigitWord(s, i) * 10;
                break;
            }
        }
        
        for (int i = s.size() - 1; i >= 0; i--)
        {
            if(isdigit(s[i])){
                ans+= s[i] - '0';
                break;
            }

            if(isDigitWord(s, i)){
                ans+= isDigitWord(s, i);
                break;
            }
        }
        cout << ans << endl;
    }

    cout << ans << endl;
    return 0;
}
