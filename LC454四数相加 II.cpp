/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-11-15 16:44:47
 * @LastEditTime: 2021-11-15 16:45:58
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> load;
        for(auto &x : nums1)
        {
            for(auto &y : nums2)
            {
                load[x+y]++;
            }
        }

        int ans = 0;
        for(auto &x : nums3)
        {
            for(auto &y : nums4)
            {
                ans += load[-(x+y)];
            }
        }
        return ans;
    }
};