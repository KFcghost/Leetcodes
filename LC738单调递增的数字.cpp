/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-10 21:22:53
 * @LastEditTime: 2021-09-10 21:35:06
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <string>

using namespace std;

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string temp = to_string(n);

        int i = 0;
        for(;i < temp.size() - 1;++i)
        {
            if(temp[i] > temp[i+1])
                break;
        }
        if(i < temp.size() - 1)
        {
            while(i > 0 && temp[i] <= temp[i-1])
                i--;
            if(temp[i] > '0')
            temp[i]--;
            i++;
            while(i < temp.size())
            {
                temp[i++] = '9';
            }
        }
        return stoi(temp);
    }
};