/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-08 16:26:02
 * @LastEditTime: 2021-09-08 16:50:32
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
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans(4);
        int lefttopi;
        int lefttopj;
        int max_sum = INT_MIN;
        int sum;
        for(int i = 0;i < n;++i)
        {
            vector<int> b(m,0);
            for(int j = i;j < n;++j)
            {
                sum = 0;
                for(int k = 0;k < m;++k)
                {
                    b[k] += matrix[j][k];
                    if(sum > 0)
                    {
                        sum += b[k];
                    }
                    else
                    {
                        sum = b[k];
                        lefttopi = i;
                        lefttopj = k;
                    }
                    if(sum > max_sum)
                    {
                        max_sum = sum;
                        ans[0] = lefttopi;
                        ans[1] = lefttopj;
                        ans[2] = j;
                        ans[3] = k;
                    }
                }
            }
        }
        return ans;
    }
};