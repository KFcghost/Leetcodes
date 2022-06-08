/*
 * @Author: Aspirin
 * @Date: 2022-06-08 14:58:13
 * @LastEditTime: 2022-06-08 15:13:48
 * @FilePath: /Leetcode/Leetcodes/LC9.回文数.cpp
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */

/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        unsigned int temp = 0,temp1 = x;
        if (x < 0)
        {
            return false;
        }

        while(x)
        {
            temp += x % 10;
            if(x >= 10)
                temp *= 10;
            x /= 10;
        }

        if(temp == temp1)
            return true;
        return false;
    }
};
// @lc code=end

