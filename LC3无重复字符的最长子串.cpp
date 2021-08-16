/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-16 21:03:38
 * @LastEditTime: 2021-08-16 21:18:47
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
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> load;
        int j=0;
        int ans=0;

        for(int i=0;i<s.size();++i){
            
            while(load.find(s[i])!=load.end()){
                load.erase(s[j]);
                j++;
            }
            
            ans=max(ans,i-j+1);
            load.insert(s[i]);
        }
        return ans;
    }
};