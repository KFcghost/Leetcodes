/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-15 15:26:26
 * @LastEditTime: 2021-08-17 23:42:26
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int l = 0;
        unordered_map<char,int> load;
        int flag = 0;
        int ans = INT_MIN;

        for(int i = 0;i < s.size(); ++i){
            while(load.size() >= k && load.find(s[i]) == load.end()){
                load[s[l]]--;
                if(load[s[l]] == 0)
                    load.erase(s[l]);
                l++;
            }
            load[s[i]]++;
            ans = max(ans,i-l+1);
        }
        if(k == 0)
            return 0;
        return ans;
    }
};