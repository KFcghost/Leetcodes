/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-09 17:11:28
 * @LastEditTime: 2021-09-09 17:26:24
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


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp1;
        ListNode* temp2 = l2;
        ListNode* newhead = new ListNode(0);
        temp1 = newhead;
        int de = 0;
        while(l1 && l2)
        {
            int dev = l1 -> val + l2 -> val + de;
            de = dev / 10;
            dev = dev % 10;
            newhead -> next = new ListNode(dev);
            newhead = newhead -> next;
            l1 = l1 -> next;
            l2 = l2 -> next;
        }
        while(l1)
        {
            int dev = l1 -> val + de;
            de = dev / 10;
            dev = dev % 10;
            newhead -> next = new ListNode(dev);
            newhead = newhead -> next;
            l1 = l1 -> next;
        }
        while(l2)
        {
            int dev = l2 -> val + de;
            de = dev / 10;
            dev = dev % 10;
            newhead -> next = new ListNode(dev);
            newhead = newhead -> next;
            l2 = l2 -> next;           
        }
        if(de)
        {
            newhead -> next = new ListNode(de);
        }
        return temp1 -> next;
    }
};