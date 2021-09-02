/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-22 10:14:04
 * @LastEditTime: 2021-08-22 18:53:40
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        
        vector<int> dp(nums.size(),0);
        for(int i = 0;i < nums.size(); ++i)
        {
            dp[i] = 1;
            for(int j = 0;j < nums.size(); ++j)
            {
                if(nums[j] < nums[i])
                {
                    dp[i] = max(dp[i],dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};