/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-21 23:12:43
 * @LastEditTime: 2022-05-29 16:04:22
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
    vector<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> load;
        allsort(nums,load,0);
        vector<vector<int>> ans(load.begin(),load.end());
        return ans;
    }
    void allsort(vector<int>& nums,set<vector<int>>load,int index){
        if(index + 1 == nums.size())
        {
            load.insert(nums);
            return ;
        }

        for(int i = index ;i < nums.size();++i)
        {
            swap(nums[i],nums[index]);
            allsort(nums,load,index+1);
            swap(nums[i],nums[index]);
        }
    }
};