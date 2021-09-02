/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-19 23:48:09
 * @LastEditTime: 2021-08-21 00:01:07
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
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return {};
        
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;

        for(int i = 0;i < nums.size(); ++i){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            int target = -nums[i];
            int r = nums.size()-1;
            for(int l = i+1;l < nums.size();++l){
                if(l > i+1 && nums[l] == nums[l-1])
                    continue;
                while(r > l && nums[l] + nums[r] > target)
                    r--;
                if(l == r)
                    break;
                if(nums[l] + nums[r] == target)
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                }
            }
        }
        return ans;
    }
};