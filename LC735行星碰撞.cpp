/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-10 20:37:39
 * @LastEditTime: 2021-09-10 21:14:28
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> temp;
        int n = asteroids.size();
        temp.push_back(asteroids[0]);
        for(int i = 1;i < n;++i)
        {
            if(asteroids[i] > 0)
            {
                temp.push_back(asteroids[i]);
                continue;
            }
           if(asteroids[i] < 0 && !temp.empty())
           {
               if(temp.back() < 0)
                {
                    temp.push_back(asteroids[i]);
                    continue;
                }
               if(abs(temp.back()) == abs(asteroids[i]))
                {
                    temp.pop_back();
                    continue;
                }
                else if(abs(temp.back()) > abs(asteroids[i]))
                {
                    continue;
                }
                else
                {
                    bool flags = false;
                    while(!temp.empty() && temp.back() > 0 && abs(temp.back()) <= abs(asteroids[i]))
                    {
                        if(abs(temp.back()) == abs(asteroids[i]))
                        {
                            flags = true;
                            temp.pop_back();
                            break;
                        }
                        temp.pop_back();
                    }
                    if((temp.empty() || temp.back() < 0) && !flags)
                    {
                        temp.push_back(asteroids[i]);
                        continue;
                    }
                    else
                        continue;
                }
           }
           temp.push_back(asteroids[i]);
        }
        vector<int> ans;
        while(!temp.empty())
        {
            ans.push_back(temp.front());
            temp.pop_front();
        }
        return ans;
    }
};