/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-07 15:37:55
 * @LastEditTime: 2021-09-07 15:42:46
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
    int maxProduct(vector<int>& nums) {
        int max_value = nums[0];
        int min_value = nums[0];

        int ans = nums[0];
        for(int i = 1;i < nums.size();++i)
        {
            int t = max_value;
            max_value = max(max_value * nums[i],max(nums[i],nums[i] * min_value));
            min_value = min(min_value * nums[i],min(t * nums[i],nums[i]));
            ans = max(ans,max_value);
        }
        return ans;
    }
};