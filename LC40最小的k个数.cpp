/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-06 23:43:31
 * @LastEditTime: 2021-09-07 09:43:08
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
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if(arr.size() <= k)
            return arr;
        
        priority_queue<int,vector<int>,greater<int>> Q;
        for(int i = 0;i < arr.size();++i)
        {
            Q.push(arr[i]);
        }
        vector<int> ans;
        for(int i = 0;i < k;++i)
        {
            ans.push_back(Q.top());
            Q.pop();
        }
        return ans;
    }
};