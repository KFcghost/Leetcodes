/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-18 23:34:55
 * @LastEditTime: 2021-08-18 23:46:31
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;


struct ListNode {
      int val;
     ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
            return nullptr;
        
        ListNode* newhead = nullptr;
        ListNode* temp = head -> next;
        while(head){
            temp = head ->next;
            head -> next =newhead;
            newhead = head;
            head = temp;
        }
        return newhead;
    }
};