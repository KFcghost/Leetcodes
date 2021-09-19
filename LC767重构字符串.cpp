/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-09 16:05:50
 * @LastEditTime: 2021-09-09 16:16:20
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
    string reorganizeString(string s) {
        int length = s.size();
        if(length < 2)
            return s;
        
        int temp[26] = {0};
        int max_value = 0;
        for(int i = 0;i < s.size();++i)
        {
            temp[s[i]-'a']++;
            max_value = max(max_value,temp[s[i]-'a']);
        }
        if(max_value >(length + 1)/2)
        {
            return "";
        }

        string ans(length,' ');
        int oddindex = 0,lddindex = 1;
        for(int i = 0;i < 26;++i)
        {
            char a = i + 'a';
            while(temp[i] <= length / 2 && lddindex < length && temp[i] != 0)
            {
                ans[lddindex] = a;
                lddindex += 2;
                temp[i]--;
            }
            while(temp[i] != 0 && oddindex < length)
            {
                ans[oddindex] = a;
                oddindex += 2;
                temp[i]--;
            }
        }
        return ans;
    }
};