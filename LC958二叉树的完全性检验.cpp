/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-03 15:49:26
 * @LastEditTime: 2021-09-04 17:01:08
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


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode *> temp;
        bool all = false;

        temp.push(root);
        while(!temp.empty())
        {
            TreeNode *t = temp.front();
            temp.pop();
            if(t == nullptr)
            {
                all = true;
                continue;
            }
            if(all)
                return false;
            temp.push(t->left);
            temp.push(t->right);
        }
        return true;
    }
};