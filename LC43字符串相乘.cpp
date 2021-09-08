/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-02 17:58:41
 * @LastEditTime: 2021-09-03 15:49:08
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <string.h>
#include <string>
#include <list>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();

        if(num1 == "0" || num2 == "0")
            return "0";

        vector<int> temp(n1 + n2,0);
        for(int i = n1-1;i >= 0;--i)
        {
            int add1 = num1[i] - '0';
            for(int j = n2-1;j >= 0;--j)
            {
                int add2 = num2[j] - '0';
                temp[i+j+1] += add1 * add2;
            }
        }

        for(int i = n1 + n2 -1;i > 0;--i)
        {
            temp[i-1] += temp[i] / 10;
            temp[i] = temp[i] % 10;
        }
        string ans;
        int index = 0;
        while(temp[index] == 0)
            index++;
        for(int i = index;i < temp.size();++i)
        {
            ans = ans + to_string(temp[i]);
        }
        return ans;
    }
};