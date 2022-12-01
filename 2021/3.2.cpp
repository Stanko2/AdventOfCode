#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int k = 12;
    int counts[k];
    int n = 0;
    vector<string> dataOxygen;
    vector<string> dataCO2;
    for (int i = 0; i < k; i++)
    {
        counts[i] = 0;
    }
    while (true)
    {
        string str;
        cin >> str;
        if (str == "exit")
            break;
        dataOxygen.push_back(str);
        dataCO2.push_back(str);
    }

    for (int i = 0; i < k; i++)
    {
        int ones = 0;
        int zeros = 0;
        if (dataOxygen.size() == 1)
            break;
        for (int j = 0; j < dataOxygen.size(); j++)
        {
            if (dataOxygen[j][i] == '1')
                ones++;
            else
                zeros++;
        }
        if (ones >= zeros)
        {
            int j = 0;
            while (j < dataOxygen.size())
            {
                if (dataOxygen[j][i] == '0')
                    dataOxygen.erase(dataOxygen.begin() + j);
                else
                    j++;
            }
        }
        else
        {
            int j = 0;
            while (j < dataOxygen.size())
            {
                if (dataOxygen[j][i] == '1')
                    dataOxygen.erase(dataOxygen.begin() + j);
                else
                    j++;
            }
        }
    }

    for (int i = 0; i < k; i++)
    {
        int ones = 0;
        int zeros = 0;
        if (dataCO2.size() == 1)
            break;
        for (int j = 0; j < dataCO2.size(); j++)
        {
            if (dataCO2[j][i] == '1')
                ones++;
            else
                zeros++;
        }
        if (ones >= zeros)
        {
            int j = 0;
            while (j < dataCO2.size())
            {
                if (dataCO2[j][i] == '1')
                    dataCO2.erase(dataCO2.begin() + j);
                else
                    j++;
            }
        }
        else
        {
            int j = 0;
            while (j < dataCO2.size())
            {
                if (dataCO2[j][i] == '0')
                    dataCO2.erase(dataCO2.begin() + j);
                else
                    j++;
            }
        }
    }

    for (int i = 0; i < dataOxygen.size(); i++)
    {
        cout << dataOxygen[i] << endl;
    }
    cout << "CO2: " << endl;
    for (int i = 0; i < dataCO2.size(); i++)
    {
        cout << dataCO2[i] << endl;
    }

    return 0;
}