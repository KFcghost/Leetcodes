/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-08 17:09:12
 * @LastEditTime: 2021-09-08 17:13:25
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class Solution {
public:
    int numWays(int n) {
        if(n == 0 || n == 1)
            return 1;
        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;
        for(int i = 3;i <= n;++i)
        {
            dp[i] =  (dp[i-1] + dp[i-2])%(1000000007);
        }
        return dp[n];
    }
};