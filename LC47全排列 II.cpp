/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-08 17:29:49
 * @LastEditTime: 2021-09-08 17:33:13
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    set<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums,0);
        vector<vector<int>> a(ans.begin(),ans.end());
        return a;
    }
    void dfs(vector<int>& nums,int index)
    {
        if(index == nums.size())
        {
            ans.insert(nums);
            return;
        }
        for(int i = index;i < nums.size();++i)
        {
            swap(nums[i],nums[index]);
            dfs(nums,index + 1);
            swap(nums[i],nums[index]);
        }
    }
};