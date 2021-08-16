/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-15 00:29:11
 * @LastEditTime: 2021-08-15 15:26:00
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int> > subsets(vector<int> &S) {
        vector<int> tmp;
        sort(S.begin(),S.end());
        sub(S,0,tmp); 
        return ans;
    }
    void sub(vector<int> &s,int index,vector<int> &tmp){
        ans.push_back(tmp);
        for(int i=index;i<s.size();++i){
            tmp.push_back(s[i]);
            sub(s,i+1,tmp);
            tmp.pop_back();
        }
    }
};