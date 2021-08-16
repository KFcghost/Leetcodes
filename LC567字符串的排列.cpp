/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-16 23:47:11
 * @LastEditTime: 2021-08-16 23:56:12
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        if(n>m)
            return false;

        vector<char> ss1(26,0);
        vector<char> ss2(26,0);
        int i;

        for(i = 0;i<n;++i){
            ss1[s1[i]-'a']++;
            ss2[s2[i]-'a']++;
        }
        if(ss1==ss2)
            return true;
        
        for(;i<m;++i){
            ss2[s2[i]-'a']++;
            ss2[s2[i-n]-'a']--;
            if(ss1==ss2)
                return true;
        }
        return false;
    }
};