/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-08 10:12:00
 * @LastEditTime: 2021-09-08 11:33:08
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>> ans;

        priority_queue<pair<int,vector<int>>> temp;
        for(int i = 0; i < min(n1,k);++i)
        {
            for(int j = 0; j < min(n2,k);++j)
            {
                if(temp.size() < k)
                {
                    temp.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                }
                else if(nums1[i] + nums2[j] < temp.top().first)
                {
                    temp.pop();
                    temp.push({nums1[i]+nums2[j],{nums1[i],nums2[j]}});
                }
            }
        }
        while(k && !temp.empty())
        {
            ans.push_back(temp.top().second);
            temp.pop();
            k--;
        }
        return ans;
    }
};