/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-04 19:32:41
 * @LastEditTime: 2021-09-05 10:03:23
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
    int ans = INT_MIN;
    int temp;
public:
    int kthLargest(TreeNode* root, int k) {
        temp = k;
        dfs(root);
        return ans;
    }
    void dfs(TreeNode* root){
        if(root == nullptr)
            return;          
        dfs(root -> right);
        temp--;
        if(temp == 0)
        {
            ans = root -> val;
            return ;
        }
        dfs(root -> left);
    }
};