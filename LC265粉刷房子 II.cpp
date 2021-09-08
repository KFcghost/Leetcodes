/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-05 15:56:13
 * @LastEditTime: 2021-09-05 16:40:40
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
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int m = costs[0].size();

        for(int i = 1;i < n;++i)
        {
            int mindex = min_element(costs[i-1].begin(),costs[i-1].end()) - costs[i-1].begin();
            int mincost = costs[i-1][mindex];
            costs[i-1][mindex] = INT_MAX;
            int secondmin = *min_element(costs[i-1].begin(),costs[i-1].end());
            for(int j = 0;j < m;++j)
            {
                if(j != mindex)
                {
                    costs[i][j] += mincost;
                }
                else
                    costs[i][j] += secondmin;
            }
        }
        return *min_element(costs[n-1].begin(),costs[n-1].end());
    }
};