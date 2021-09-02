/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-22 00:26:18
 * @LastEditTime: 2021-08-22 00:42:03
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
    int numIslands(vector<vector<char>>& grid) {
        int flags = 0;
        for(int i = 0;i < grid.size();++i)
        {
            for(int j = 0;j < grid[0].size();++j)
            {
                if(grid[i][j] == '1')
                {
                    flags++;
                    bfs(grid,i,j);
                }
            }
        }
        return flags;
    }
    void bfs(vector<vector<char>>& grid,int i,int j)
    {
        if(i < 0 || j < 0)
            return ;
        if(i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1')
            return ;
        grid[i][j] = '0';
        bfs(grid,i-1,j);
        bfs(grid,i+1,j);
        bfs(grid,i,j-1);
        bfs(grid,i,j+1);
    }
};