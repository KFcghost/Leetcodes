/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-05 10:30:36
 * @LastEditTime: 2021-09-05 11:03:46
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
        int n = nums.size();
        if(n == 0)
            return 0;
        if(n == 1)
            return nums[0];
        if(n == 2)
            return max(nums[0],nums[1]);

        return max(dj(nums,0,n-2),dj(nums,1,n-1));
    }
    int dj(vector<int>& nums,int i,int j)
    {
        vector<int> dp(nums.size());
        dp[i++] = nums[i];
        dp[i++] = max(nums[i],nums[i-1]);
        for(;i <= j;++i)
        {
            dp[i] = max(dp[i-1],dp[i-2]+nums[i]);
        }
        return dp[j];
    }
};