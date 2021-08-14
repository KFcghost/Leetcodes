/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-07-28 23:21:04
 * @LastEditTime: 2021-08-11 22:49:29
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    /**
     * 
     * @param s string字符串 
     * @return int整型
     */
    int longestValidParentheses(string s) {
        // write code here
        stack<int> temp;
        int Max=0,last=-1;
        for(int i=0;i<s.size();++i){
            if(s[i]=='('){
                temp.push(i);
            }
            else{
                if(temp.empty()){
                    last=i;
                }
                else{
                    temp.pop();
                    Max= temp.empty()?max(Max,i-last):max(Max,i-temp.top());
                }
            }
        }
        return Max;
    }
};