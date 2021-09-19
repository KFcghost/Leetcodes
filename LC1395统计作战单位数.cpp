/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-09 18:44:59
 * @LastEditTime: 2021-09-09 20:34:28
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <set>

using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) {

        int ans = 0;
        for(int i = 0;i < rating.size();++i)
        {
            int l = i - 1;
            int r = i + 1;
            int lhight = 0;
            int llow = 0;
            int rhight = 0;
            int rlow = 0;
            while(l >= 0)
            {
                if(rating[l] < rating[i])
                {
                    llow++;
                }
                else
                {
                    lhight++;
                }
                l--;
            }
            while(r < rating.size())
            {
                if(rating[r] < rating[i])
                {
                    rlow++;
                }
                else
                {
                    rhight++;
                }
                r++;
            }
            ans += llow * rhight + lhight * rlow;
        }
        
        return ans;
    }
};
