/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-05 10:10:08
 * @LastEditTime: 2021-09-05 10:30:43
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
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];

        vector<int> dp(n,0);
        dp[0] = nums[0];
        dp[1] = max(dp[0],nums[1]);
        for(int i = 2;i < n;++i)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[n-1];
    }
};