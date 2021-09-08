/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-04 17:55:27
 * @LastEditTime: 2021-09-04 18:24:41
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <queue>
#include <numeric>


using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<int> temp;
        char pren = '+';

        int num = 0;
        for(int i = 0;i < s.size();++i)
        {
            if(isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            if(!isdigit(s[i]) && s[i] != ' ' || i == s.size()-1)
            {
                switch (pren)
                {
                case '+':
                    temp.push_back(num);
                    break;
                case '-':
                    temp.push_back(-num);
                    break;
                case '*':
                    temp.back() *= num;
                    break;     
                default:
                    temp.back() /= num;
                    break;
                }
                num = 0;
                pren = s[i];
            }
        }
        return accumulate(temp.begin(),temp.end(),0);
    }
};