/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-07 16:45:15
 * @LastEditTime: 2021-09-07 16:52:09
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
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,amount + 1);

        dp[0] = 0;
        for(int i = 1;i <= amount;++i)
        {
            for(int j = 0;j < coins.size();++j)
            {
                if(coins[j] <= i)
                {
                    dp[i] = min(dp[i],dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};