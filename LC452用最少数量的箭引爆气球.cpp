/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-11-10 11:37:03
 * @LastEditTime: 2021-11-10 17:15:43
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end(),[](const vector<int> &x,const vector<int> &y){
            return x[1] < y[1];
        });                         //使用lambda表达式进行排序
        
        int pos = points[0][1];     //首先使用最右坐标最小气球作为初始值
        int ans = 0;

        for(auto &x : points)
        {
            if(x[0] > pos)          //若该气球无法被射爆，就将下一个气球的右坐标作为下一个定值
            {
                pos = x[1];
                ans++;
            }
        }
        return ans;
    }
};