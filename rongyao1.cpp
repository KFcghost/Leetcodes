/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-25 18:04:28
 * @LastEditTime: 2021-09-25 18:48:59
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<vector<long>> getok(vector<long> a, vector<long> b, long R)
{
    vector<vector<long>> ans;
    for (long i = 0; i < a.size(); ++i)
    {
        bool flags = false;
        for (long j = 0; j < b.size(); ++j)
        {
            if (a[i] > b[j])
                continue;
            if (a[i] <= b[j] && abs(a[i] - b[j]) <= R)
            {
                ans.push_back({ a[i],b[j] });
                flags = true;
            }
            if (abs(a[i] - b[j]) > R)
            {
                if (flags == false)
                    ans.push_back({ a[i],b[j] });
                break;
            }
        }
    }
    return ans;
}

int main()
{
    string str;
    cin >> str;
    string a1;
    string b1;
    long R = 0;
    string RR;
    vector<long> a;
    vector<long> b;
    for (long i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'A')
        {
            long start = i + 2;
            long j = i + 1;
            while (str[j] != '}')
            {
                if (str[j] == ',')
                    str[j] = ' ';
                j++;
            }
            a1 = str.substr(start + 1, j - start - 1);
            i = j + 1;
        }
        if (str[i] == 'B')
        {
            long start = i + 2;
            long j = i + 1;
            while (str[j] != '}')
            {
                if (str[j] == ',')
                    str[j] = ' ';
                j++;
            }
            b1 = str.substr(start + 1, j - start - 1);
            i = j + 1;
        }
        if (str[i] == 'R')
        {
            i = i + 2;
            RR = str.substr(i, str.size() - i);
        }
    }
    stringstream temp(a1);
    long x;
    while (temp >> x)
    {
        a.push_back(x);
    }
    stringstream temp2(b1);
    while (temp2 >> x)
    {
        b.push_back(x);
    }
    stringstream temp3(RR);
    temp3 >> R;

    vector<vector<long>> ans = getok(a, b, R);
    for (auto& x : ans)
    {
        cout << "(" << x[0] << "," << x[1] << ")";
    }
    return 0;
}