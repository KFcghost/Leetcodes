/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-04 17:14:54
 * @LastEditTime: 2021-09-04 17:23:14
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
    Node* head;
    Node* pre;
public:
    Node* treeToDoublyList(Node* root) {
        if(root == nullptr)
            return nullptr;
        dfs(root);
        head -> left = pre;
        pre -> right = head;
        return head;
    }
    void dfs(Node* root){
        if(root == nullptr)
            return;
        dfs(root -> left);
        if(pre ==  nullptr)
            head = root;
        else
            pre -> right = root;
        root -> left = pre;
        pre = root;
        dfs(root -> right);
    }
};