/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-11-15 17:34:18
 * @LastEditTime: 2021-11-15 17:43:19
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(auto &x : nums)
        {
            int y = (x - 1) % n;
            nums[y] += n;
        }

        vector<int> ans;
        for(int i = 0;i < nums.size();++i)
        {
            if(nums[i] <= n)
                ans.push_back(i+1);
        }
        return ans;
    }
};