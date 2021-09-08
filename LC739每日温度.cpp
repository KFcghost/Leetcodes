/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-07 10:55:23
 * @LastEditTime: 2021-09-07 11:09:14
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <random>
#include <time.h>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> temp;
        vector<int> ans(temperatures.size());

        temp.push(0);
        for(int i = 1;i < temperatures.size();++i)
        {
            while(!temp.empty() && temperatures[i] > temperatures[temp.top()])
            {
                ans[temp.top()] = i - temp.top();
                temp.pop();
            }
            temp.push(i);
        }
        if(!temp.empty())
        {
            temperatures[temp.top()] = 0;
            temp.pop();
        }
        return ans;
    }
};