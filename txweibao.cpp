/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-23 15:17:04
 * @LastEditTime: 2021-09-23 16:39:32
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
     * @param M int整型 初始给定的淘汰数字
     * @param N int整型 猴子数量
     * @return int整型
     */
    int DoPermute(int M, int N) {
        // write code here
        int res = 0;
        int n = M;
        for(int i = 1;i <= N;++i)
        {
            res = (res + M++) % i;
        }
        return res - 1;
    }
};

int main()
{
    Solution t;
    cout << t.DoPermute(3,5);
}