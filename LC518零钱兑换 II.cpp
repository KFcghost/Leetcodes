/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-07 15:52:30
 * @LastEditTime: 2021-09-07 17:00:21
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
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1);
        dp[0] = 1;

        for(auto &x:coins)
        {
            for(int i = x;i <= amount;++i)
            {
                dp[i] += dp[i - x];
            }
        }
        return dp[amount];
    }
};