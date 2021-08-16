/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-16 21:45:29
 * @LastEditTime: 2021-08-16 22:12:42
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=p.size();
        int m=s.size();

        vector<int> ans;
        vector<char> ss(26,0);
        vector<char> pp(26,0);


        if(n>m)
            return {};

        int i;
        for(i=0;i<n;++i){
            ss[s[i]-'a']++;
            pp[p[i]-'a']++;
        }
        if(pp==ss)
            ans.push_back(0);
        
        for(;i < m; ++i){
            ss[s[i]-'a']++;
            ss[s[i-n]-'a']--;
            if(ss==pp)
                ans.push_back(i-n+1);
        }
        return ans;
    }
};