/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-22 00:42:22
 * @LastEditTime: 2021-08-22 00:49:39
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
    int trap(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int lm = 0;
        int rm = 0;
        int ans = 0;

        while(l != r)
        {
            lm = max(height[l],lm);
            rm = max(height[r],rm);

            if(height[l] < height[r])
            {
                ans += lm -height[l];
                l++;
            }
            else
            {
                ans += rm -height[r];
                r--;
            }
        }
        return ans;
    }
};