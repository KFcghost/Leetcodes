/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-11-15 18:59:47
 * @LastEditTime: 2021-11-15 19:43:18
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> load;

        for(int i = 0; i < s.size();++i)
        {
            load[s[i]]++;
        }
        int singles = 0;
        int fushu = 0;
        int ans = 0;
        for(auto &x : load)
        {
            int v =  x.second;
            ans += v / 2 * 2;
            if(v % 2 == 1 && ans % 2 == 0)
                ans++;
        }
        return ans;
    }
};