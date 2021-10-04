/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-25 19:05:41
 * @LastEditTime: 2021-09-26 18:38:01
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    long N,Q;
    cin >> N >> Q;
    getchar();
    string t;
    getline(cin, t);
    stringstream temp(t);
    
    vector<long> xl(N, 0);
    vector<long> xx(N, 0);
    for (int i = 0; i < N; ++i)
    {
        temp >> xl[i];
        if (i == 0)
            xx[i] = xl[i];
        else
            xx[i] = xx[i - 1] + xl[i];
    }

    for (int i = 0; i < Q; ++i)
    {
        getline(cin, t);
        if (t[0] == 'Q')
        {
            stringstream tt(t.substr(1, t.size() - 1));
            long begin;
            long end;
            tt >> begin >> end;
            long sum = 0;
            if (begin != end)
            {
                if (begin == 1)
                    sum = xx[end - 1];
                else
                    sum = xx[end - 1] - xx[begin - 2];
                cout << (int)sum / (end - begin + 1) << "\n";
            }
            else
            {
                if (begin == 1)
                    cout << xx[0] << "\n";
                else
                    cout << xx[begin - 1] - xx[begin-2] <<"\n";
            }
        }
        else
        {
            stringstream tt(t.substr(1, t.size() - 1));
            long begin;
            long end;
            tt >> begin;
            tt >> end;
            for (int i = begin - 1; i < N; ++i)
            {
                xx[i] += end;
            }
            xl[begin - 1] += end;
        }
    }
    return 0;
}