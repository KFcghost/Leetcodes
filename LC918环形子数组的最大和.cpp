/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-08 16:55:48
 * @LastEditTime: 2021-09-08 17:03:52
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
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_t(n);
        vector<int> max_t(n);
        int sum = nums[0];
        min_t[0] = nums[0];
        max_t[0] = nums[0];
        for(int i = 1;i < n;++i)
        {
            max_t[i] = max(max_t[i-1] + nums[i],nums[i]);
            min_t[i] = min(min_t[i-1] + nums[i],nums[i]);
            sum += nums[i];
        }
        int mm = *max_element(max_t.begin(),max_t.end());
        int nn = *min_element(min_t.begin(),min_t.end());
        return max(mm , sum-nn == 0?mm:sum-nn);
    }
};