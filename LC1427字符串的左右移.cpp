/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-11-15 17:47:46
 * @LastEditTime: 2021-11-15 18:57:58
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int move = 0;
        for(int i = 0;i < shift.size();++i)
        {
            int to = shift[i][0];
            int size = 0;
            if(to)
            {
                move -= shift[i][1];
            }
            if(!to)
            {
                move += shift[i][1];
            }
        }
        int n = s.size();
        move = (move % n + n) % n;
        return s.substr(move , n - move) + s.substr(0 , move);
    }
};