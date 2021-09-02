/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-21 00:20:59
 * @LastEditTime: 2021-08-21 00:34:53
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
    string addStrings(string num1, string num2) {
        int n = num1.size()-1 , m = num2.size()-1;

        int flags = 0;
        int a,b,x;
        string ans = "";
        while(n >= 0 || m >= 0 || flags != 0)
        {
            a = n >= 0 ? num1[n] - '0': 0;
            b = m >= 0 ? num2[m] - '0': 0;
            x = a + b + flags;
            flags = x / 10;
            x = x % 10;
            n--;
            m--;
            ans.push_back('0' + x);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};