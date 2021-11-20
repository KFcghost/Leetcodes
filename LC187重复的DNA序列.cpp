/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-11-15 19:47:46
 * @LastEditTime: 2021-11-15 19:53:32
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string,int> load;
        vector<string> ans;

        for(int i = 0;i < s.size() - 10;++i)
        {
            string t = s.substr(i,i+9);
            load[t]++;
        }
        for(auto &x : load)
        {
            if(x.second >= 2)
                ans.push_back(x.first);
        }
        return ans;
    }
};