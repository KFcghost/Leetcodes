/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-21 00:01:45
 * @LastEditTime: 2021-08-21 00:20:38
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if(n % 2 == 1)
            return false;

        unordered_map<char,char> load=
        {
            {')' , '('},
            {'}' , '{'},
            {']' , '['}
        };

        stack<char> temp;
        for(auto &x : s)
        {
            if(load.find(x) != load.end())
            {
                if(temp.empty() || temp.top() != load[x])
                    return false;
                temp.pop();
            }
            else
            {
                temp.push(x);
            }
        }
        return temp.empty();           
    }
};