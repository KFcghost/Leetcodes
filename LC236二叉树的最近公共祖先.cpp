/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-21 10:20:37
 * @LastEditTime: 2021-08-21 10:31:19
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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
    TreeNode* dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(root == nullptr || root == p || root == q)
            return root;
        TreeNode * left = dfs(root -> left,p,q);
        TreeNode* right = dfs(root ->right,p,q);
        if(left && right)
            return root;
        return left == nullptr ? right : left;
    }
};