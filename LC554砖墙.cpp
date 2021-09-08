/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-07 15:18:43
 * @LastEditTime: 2021-09-07 15:25:24
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <random>
#include <time.h>
#include <queue>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int,int> load;
        int n = wall[0].size();

        for(auto &x:wall)
        {
            int sum = 0;
            for(int i = 0;i < x.size() - 1;++i)
            {
                sum += x[i];
                load[sum]++;
            }
        }
        int ans = 0;
        for(auto &w : load)
        {
            ans = max(ans,w.second);
        }
        return wall.size() - ans;
    }
};