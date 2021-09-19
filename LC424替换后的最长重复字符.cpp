/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-09 16:16:38
 * @LastEditTime: 2021-09-09 16:48:29
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int r = 0;
        int length = s.size();
        vector<int> load(26,0);
        int max_value = 0;

        while(r != length)
        {
            load[s[r]-'A']++;
            max_value = max(max_value,load[s[r]-'A']);
            if(r - l + 1 - max_value > k)
            {
                load[s[l]-'A']--;
                l++;
            }
            r++;
        }
        return r - l;
    }
};