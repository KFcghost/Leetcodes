/*
 * @Author: Aspirin
 * @Date: 2022-06-11 20:29:24
 * @LastEditTime: 2022-06-28 17:50:01
 * @FilePath: /Leetcode/Leetcodes/LC6z字形变换.cpp
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length(), r = numRows;
        if (r == 1 || r >= n) {
            return s;
        }
        vector<string> mat(r);
        for (int i = 0, x = 0, t = r * 2 - 2; i < n; ++i) {
            mat[x] += s[i];
            i % t < r - 1 ? ++x : --x;
        }
        string ans;
        for (auto &row : mat) {
            ans += row;
        }
        return ans;
    }
};

// @lc code=end

