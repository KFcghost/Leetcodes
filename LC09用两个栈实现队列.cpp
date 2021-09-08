/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-05 16:44:06
 * @LastEditTime: 2021-09-05 17:01:41
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class CQueue {
public:
    stack<int> load1;
    stack<int> load2;
    CQueue() {}
    
    void appendTail(int value) {
        load2.push(value);
        if(load1.empty())
        {
            while(!load2.empty())
            {
                load1.push(load2.top());
                load2.pop();
            }
        }
    }
    
    int deleteHead() {
        if(load1.empty())
            return -1;
        int x = load1.top();
        load1.pop();
        return x;
    }
};
