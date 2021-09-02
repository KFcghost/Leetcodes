/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-22 19:24:27
 * @LastEditTime: 2021-08-22 19:27:55
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    vector<int> ans;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        inorder(root);
        return ans;
    }
    void inorder(TreeNode* root){
        if(root == nullptr)
            return ;
        inorder(root -> left);
        ans.push_back(root -> val);
        inorder(root -> right);
    }
};