/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2022-01-22 15:35:53
 * @LastEditTime: 2022-01-22 15:42:47
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removePalindromeSub(string s) {
        int size = s.size();
        int t = --size;
        for(int i = 0;i < size/2;++i)
        {
            if(s[i] != s[t--])
                return 2;
        }
        return 1;
    }
};