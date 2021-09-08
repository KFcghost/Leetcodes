/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-05 11:04:00
 * @LastEditTime: 2021-09-05 11:13:09
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
    int area;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0;i < grid.size();++i)
        {
            for(int j = 0;j < grid[0].size();++j)
            {
                if(grid[i][j] == 1)
                {
                    area = 0;
                    dfs(grid,i,j);
                    ans = max(ans,area);
                }
            }
        }
        return ans;
    }
    void dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i < 0 || j < 0)
            return ;
        if(i >= grid.size() || j >= grid[0].size())
            return ;
        if(grid[i][j] == 0)
            return;
        area++;
        grid[i][j] = 0;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);
    }
};