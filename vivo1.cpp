/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-22 15:02:06
 * @LastEditTime: 2021-09-22 15:24:26
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 未来空闲工作日
     * @return int整型
     */
    int ans = 0;
    int workSchedule(int n) {
        // write code here
        vector<int> works = {1,2,4};
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        dfs(works,n,0);
        return ans;
    }
    void dfs(vector<int> works,int n,int now)
    {
        if(now == n)
        {
            ans++;
            return ;
        }
        if(now > n)
            return ;
        for(int i = 0;i < 3;++i)
        {
            now = now + works[i];
            dfs(works,n,now);
            now = now - works[i];
        }
    }
};

int main()
{
    int x = 3;
    Solution t;
    cout << t.workSchedule(x);
}