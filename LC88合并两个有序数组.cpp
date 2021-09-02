/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-21 10:31:39
 * @LastEditTime: 2021-08-21 17:18:18
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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        m = m - 1;
        n = n - 1;
        int cur = m + n + 1;

        while(cur >= 0)
        {
            if(m < 0)
            {
                while(cur >= 0)
                {
                    nums1[cur--] = nums2[n--];
                }
                break;
            }
            if(n < 0)
            {
                while(cur >= 0)
                {
                    nums1[cur--] = nums1[m--];
                }
                break;
            }
            if(nums1[m] > nums2[n])
                nums1[cur--] = nums1[m--];
            else
            {
                nums1[cur--] = nums2[n--];
            }
        }
    }
};