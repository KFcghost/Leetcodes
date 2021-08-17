/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-17 00:23:55
 * @LastEditTime: 2021-08-17 00:24:09
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int A=0;
        int L=0;

        for(int i=0;i<s.length();++i){
            if(s[i]=='A')
            {
                A++;
            }
            if(s[i]=='L')
            {
                L++;
                if(L==3)
                    return false;
                continue;
            }
            L=0;
        }
        if(A>=2)
            return false;
        return true;
    }
};