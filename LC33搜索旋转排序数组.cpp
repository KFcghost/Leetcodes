/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-21 17:19:05
 * @LastEditTime: 2021-08-21 23:12:30
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
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l != r)
        {
            int mid = (r - l)/2 + l;
            if(nums[mid] == target)
                return mid;
            if(nums[mid] >= nums[0])
            {
                if(nums[0] <= target && target < nums[mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
            else
            {
                if(nums[mid] < target && target <= nums[r])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};