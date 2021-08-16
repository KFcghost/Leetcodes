/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-16 21:33:48
 * @LastEditTime: 2021-08-16 21:44:29
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> load(100001,0);
        int l=0;
        int sum=0;
        int ans=0;

        for(int i=0;i<nums.size();++i){
            sum += nums[i];
            load[nums[i]]++;

            while(load[nums[i]]>1){
                sum -= nums[l];
                load[nums[l]]--;
                l++;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};