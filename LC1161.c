/*
 * @Author: Aspirin
 * @Date: 2022-07-31 22:48:49
 * @LastEditTime: 2022-08-06 16:26:40
 * @FilePath: /Leetcode/Leetcodes/LC1161.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */

#define MAX_NODE_SIZE 10000


struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};


int maxLevelSum(struct TreeNode* root){
    int ans = 1, maxSum = root->val;
    struct TreeNode **q = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_NODE_SIZE);
    struct TreeNode **nq = (struct TreeNode **)malloc(sizeof(struct TreeNode *) * MAX_NODE_SIZE);
    int qSize = 0;
    q[qSize++] = root;
    for (int level = 1; qSize > 0; ++level) {
        int sum = 0, nqSize = 0;
        for (int i = 0; i < qSize; i++) {
            sum += q[i]->val;
            if (q[i]->left) {
                nq[nqSize++] = q[i]->left;
            }
            if (q[i]->right) {
                nq[nqSize++] = q[i]->right;
            }
        }
        if (sum > maxSum) {
            maxSum = sum;
            ans = level;
        }
        struct TreeNode *tmp = q;
        q = nq;
        nq = tmp;
        qSize = nqSize;
    }
    free(q);
    free(nq);
    return ans;
}