/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-07 15:28:44
 * @LastEditTime: 2021-09-07 15:33:53
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
    int maxSubArray(vector<int>& nums) {
        int temp = nums[0];
        int ans = nums[0];
        for(int i = 1;i < nums.size();++i)
        {
            if(temp > 0)
            {
                temp += nums[i];
            }
            else
            {
                temp = nums[i];
            }
            ans = max(ans,temp);
        }
        return ans;
    }
};