/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-10-04 15:48:50
 * @LastEditTime: 2021-10-04 16:18:26
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    unordered_map<Node*, Node*> cachedNode;

    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }
        
        if(cachedNode.count(head))
        {
            Node *newhead = new Node(head->val);
            cachedNode[head] = newhead;
            newhead->next = copyRandomList(head->next);
            newhead->random = copyRandomList(head->random);
        }
        return cachedNode[head];
    }
};