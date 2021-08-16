/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-16 23:57:14
 * @LastEditTime: 2021-08-17 00:13:16
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int flags=0;
        int tempindex=0;
        int ans=0;
        int l=0;

        for(int i=0;i<nums.size();++i){
            if(flags==1&&nums[i]==0)
            {   
                l=tempindex+1;
                flags=1;
                tempindex=i;
                continue;
            }
            if(nums[i]==0)
            {
                tempindex=i;
                flags=1;
            }
            ans = max(ans,i-l+1);
        }
        return ans;
    }
};