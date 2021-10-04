/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-22 15:50:43
 * @LastEditTime: 2021-09-22 15:56:06
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 返回最多能挑选出多少个武将，使得两两之间均存在碾压关系。
     * @param heroes int整型vector<vector<>> 武将属性值列表
     * @return int整型
     */
    int maxRollingHeroes(vector<vector<int> >& heroes) {
        // write code here
        sort(heroes.begin(),heroes.end());
        int ans = 1;
        int m = heroes.size();
        int n = heroes[0].size();
        vector<int> dp(m,0);
        dp[0] =  1;
        bool flags;
        for(int i = 1;i < m;++i)
        {
            dp[i] = 1;
            for(int j = 0;j < i;++j)
            {
                flags = true;
                for(int w = 0;w < n;++w)
                {
                    if(heroes[j][w] > heroes[i][w])
                        flags = false;
                }
                if(flags)
                    dp[i] =  max(dp[i],dp[j]+1);
            }
            ans = max(ans,dp[i]);
        }
        if(ans == 1)
            return 0;
        return ans;
    }
};