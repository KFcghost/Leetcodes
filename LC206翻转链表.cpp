/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-18 23:34:55
 * @LastEditTime: 2022-02-22 09:37:40
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
 
 //迭代
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

//递归
class solution1{
    ListNode *reverslist(ListNode *head)
    {
        if(!head || !head->next)
            return nullptr;
        
        ListNode *newhead = reverslist(head -> next);;
        head -> next -> next = head;
        head -> next = nullptr;
        return newhead;
    }
};