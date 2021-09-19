/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-09 20:34:41
 * @LastEditTime: 2021-09-09 20:58:37
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
    bool isHappy(int n) {
        int slowhead = n;
        int quickhead = gethappy(n);
        while(slowhead != quickhead && slowhead !=  1 && quickhead != 1)
        {
            slowhead = gethappy(slowhead);
            quickhead = gethappy(gethappy(quickhead));
        }
        if(slowhead == 1 || quickhead == 1)
            return true;
        return false;
    }
    int gethappy(int n)
    {
        int totalSum = 0;
        while (n > 0) {
            int d = n % 10;
            n = n / 10;
            totalSum += d * d;
        }
        return totalSum;
    }
};