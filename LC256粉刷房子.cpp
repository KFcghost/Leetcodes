/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-05 11:41:40
 * @LastEditTime: 2022-05-29 15:56:28
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        vector<vector<int>> dp(costs.size(),vector<int>(3,0));

        for(int i = 0;i < 3;++i)
        {
            dp[0][i] = costs[0][i];
        }

        for(int i = 1;i < costs.size();++i)
        {
            dp[i][0] = min(dp[i-1][1],dp[i-1][2]) + costs[i][0];
            dp[i][1] = min(dp[i-1][0],dp[i-1][2]) + costs[i][1];
            dp[i][2] = min(dp[i-1][0],dp[i-1][1]) + costs[i][2];
        }
        return min(min(dp[costs.size()-1][0],dp[costs.size()-1][1]),dp[costs.size()-1][2]);
    }
};