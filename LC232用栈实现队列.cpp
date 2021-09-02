/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-22 19:01:21
 * @LastEditTime: 2021-08-22 19:23:42
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

class MyQueue {
    stack<int> temp1;
    stack<int> temp2;
public:
    /** Initialize your data structure here. */
    MyQueue() {}
    
    /** Push element x to the back of queue. */
    void push(int x) {
        temp1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(temp2.empty())
        {
            while(!temp1.empty())
            {
                temp2.push(temp1.top());
                temp1.pop();
            }
        }
        int x = temp2.top();
        temp2.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        if(temp2.empty())
        {
            while(!temp1.empty())
            {
                temp2.push(temp1.top());
                temp1.pop();
            }
        }
        int x = temp2.top();
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(temp1.empty() && temp2.empty())
            return true;
        return false;
    }
};
