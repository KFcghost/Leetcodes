/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2022-01-19 09:16:15
 * @LastEditTime: 2022-01-19 09:29:51
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> load;
        for(int i = 0;i < nums.size();++i)
        {
            if(load.find(nums[i]) != load.end())
            {
                if(i - load[nums[i]] <= k)
                    return true;                
            }
            load[nums[i]] = i;
        }
        return false;
    }
};