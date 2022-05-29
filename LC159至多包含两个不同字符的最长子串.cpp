/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-15 16:06:52
 * @LastEditTime: 2021-08-16 21:00:15
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int l=0,r=0;
        int flags=0;
        unordered_map<char,int> load;
        int ans=0;

        while(r!=s.size()){
            if(load.find(s[r]) == load.end() || load[s[r]]==0)
            {
                flags++;
            }
            load[s[r]]++;
            
            if(flags <= 2){
                ans=max(r-l+1,ans);
            }
            while(flags ==3){
                    load[s[l]]--;
                    if(load[s[l]]==0)
                        flags--;
                    l++;
            }
            r++;
        }
        return ans;
    }
};