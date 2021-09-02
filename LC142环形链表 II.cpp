/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-21 23:32:04
 * @LastEditTime: 2021-08-21 23:41:48
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* quick = head;
        ListNode* slow = head;

        while(quick && quick ->next)
        {
            quick = quick ->next->next;
            slow = slow ->next;
            if(quick == slow)
            {
                quick = head;
                while(quick != slow)
                {
                    quick = quick ->next;
                    slow = slow ->next;
                }
                return quick;
            }
        }
        return nullptr;
    }
};