/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-07-28 22:23:13
 * @LastEditTime: 2021-07-28 23:11:17
 * @LastEditors: Aspirin
 */

#include <vector>
#include <unordered_map>
using namespace std;

 struct TreeNode {
 	int val;
 	struct TreeNode *left;
 	struct TreeNode *right;
 };

class Solution {
public:
    /**
     * 
     * @param root TreeNode类 
     * @return bool布尔型
     */
    bool ans=true;
    bool isSymmetric(TreeNode* root) {
        // write code here
        if(root==nullptr)
            return true;
        bfs(root->left,root->right);
        return ans;
    }
    void bfs(TreeNode *left,TreeNode *right){
        if(left==nullptr&&right==nullptr)
            return ;
        if(left->val!=right->val||left==nullptr||right==nullptr){
            ans=false;
            return ;
        }
        bfs(left->right,right->left);
        bfs(left->left,right->right);
    }
};


