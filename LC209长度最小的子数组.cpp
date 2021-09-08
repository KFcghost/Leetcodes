/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-16 21:19:37
 * @LastEditTime: 2021-08-16 21:31:15
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int ans=INT_MAX;
        int l=0;

        for(int i=0;i<nums.size();++i){
            sum += nums[i];

            while(sum >= target){
                ans = min(ans,i-l+1);
                sum -= nums[l];
                l++;
            }
            
        }
        if(ans == INT_MAX)
            return 0;
        return ans;
    }
};