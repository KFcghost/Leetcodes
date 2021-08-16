/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-16 20:21:44
 * @LastEditTime: 2021-08-16 21:31:30
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum=0;
        double ans=0;

        int r=0;
        int l=0;
        while(r!=nums.size()){
            sum += nums[r];
            while(r-l == k-1){
                ans=max(ans,sum/k);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return ans;
    }
};