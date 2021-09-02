/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-21 23:42:00
 * @LastEditTime: 2021-08-22 00:24:05
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
    string longestPalindrome(string s) {
        if(s.length() == 0)
            return "";

        int start = 0;
        int end = 0;
        for(int i = 0;i < s.size();++i)
        {
            auto [left1,right1] = isrom(s,i,i);
            auto [left2,right2] = isrom(s,i,i+1);
            if(right1 - left1 > end - start)
            {
                start = left1;
                end = right1;
            }
            if(right2 - left2 > end - start)
            {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start,end-start+1);
    }
    pair<int,int> isrom(string& s,int i,int j)
    {
        while(i >= 0 && j < s.size() && s[i] == s[j])
        {
            i--;
            j++;
        }
        return {i+1,j-1};
    }
};
