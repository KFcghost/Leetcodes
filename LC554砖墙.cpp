/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-07 15:18:43
 * @LastEditTime: 2021-11-10 17:42:57
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <unordered_map>

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
                sum += x[i];                        //在该层求其前缀和
                load[sum]++;
            }
        }
        int ans = 0;
        for(auto &w : load)
        {
            ans = max(ans,w.second);                //判断哪个位置砖块最右边出现次数最多
        }
        return wall.size() - ans;
    }
};