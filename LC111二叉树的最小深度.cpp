/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-09 16:58:47
 * @LastEditTime: 2021-09-09 17:08:13
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
    int minDepth(TreeNode* root) {
        if(root == nullptr)
            return 0;
        return dfs(root)+1;
    }
    int dfs(TreeNode* root)
    {
        if(root == nullptr)
            return INT_MAX-10;
        if(root -> left == nullptr && root -> right == nullptr)
            return 0;
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        return min(l,r)+1;
    }
};