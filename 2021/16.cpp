#include <bits/stdc++.h>

using namespace std;

map<char, string> hex2bin = {
    {'0', "0000"},
    {'1', "0001"},
    {'2', "0010"},
    {'3', "0011"},
    {'4', "0100"},
    {'5', "0101"},
    {'6', "0110"},
    {'7', "0111"},
    {'8', "1000"},
    {'9', "1001"},
    {'A', "1010"},
    {'B', "1011"},
    {'C', "1100"},
    {'D', "1101"},
    {'E', "1110"},
    {'F', "1111"},
};

struct Packet
{
    int v;
    int t;
    long long val;
    int size;
};

pair<long long, int> parsePacket(string data)
{
    int v = stoi(data.substr(0, 3), 0, 2);
    int id = stoi(data.substr(3, 3), 0, 2);
    long long val = 0;
    if (id == 2)
        val = LONG_LONG_MAX;
    if (id == 1)
        val = 1;
    int pos = 6;
    if (id == 4)
    {
        while (data[pos] == '1')
        {
            val += stoi(data.substr(pos + 1, 4), 0, 2);
            val = val << 4;
            pos += 5;
        }
        val += stoi(data.substr(pos + 1, 4), 0, 2);
        pos += 5;
        return make_pair(val, pos);
        if (pos % 4 > 0)
        {
            pos += 4 - pos % 4;
        }
    }
    else
    {
        bool I = stoi(data.substr(pos, 1), 0, 2);
        pos++;
        if (I)
        {
            int num = stoi(data.substr(pos, 11), 0, 2);
            pos += 11;
            int values[2];
            for (size_t i = 0; i < num; i++)
            {
                pair<long long, int> a = parsePacket(data.substr(pos));
                if (i < 2)
                    values[i] = a.first;
                pos += a.second;
                switch (id)
                {
                case 0:
                    val += a.first;
                    break;
                case 1:
                    val *= a.first;
                    break;
                case 2:
                    val = min(a.first, val);
                    break;
                case 3:
                    val = max(a.first, val);
                    break;
                }
            }
            switch (id)
            {
            case 5:
                val = values[0] > values[1];
                break;
            case 6:
                val = values[0] < values[1];
                break;
            case 7:
                val = values[0] == values[1];
                break;
            }
        }
        else
        {
            int len = stoi(data.substr(pos, 15), 0, 2);
            pos += 15;
            int start = pos;
            int values[2];
            int i = 0;
            while (pos - start < len)
            {
                pair<long long, int> a = parsePacket(data.substr(pos));
                if (i < 2)
                    values[i] = a.first;
                pos += a.second;
                switch (id)
                {
                case 0:
                    val += a.first;
                    break;
                case 1:
                    val *= a.first;
                    break;
                case 2:
                    val = min(a.first, val);
                    break;
                case 3:
                    val = max(a.first, val);
                    break;
                }
                i++;
            }
            switch (id)
            {
            case 5:
                val = values[0] > values[1];
                break;
            case 6:
                val = values[0] < values[1];
                break;
            case 7:
                val = values[0] == values[1];
                break;
            }
        }
        return make_pair(val, pos);
    }
}

int main(int argc, char const *argv[])
{
    string hex;
    cin >> hex;
    string bin;
    for (int i = 0; i < hex.size(); i++)
    {
        bin += hex2bin[hex[i]];
    }
    size_t pos = 0;
    long long sum = parsePacket(bin).first;
    cout << sum << endl;
    return 0;
}
