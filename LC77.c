/*
 * @Author: Aspirin
 * @Date: 2022-08-22 23:58:34
 * @LastEditTime: 2022-08-23 19:04:17
 * @FilePath: /Leetcode/Leetcodes/LC77.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>

int **ans;
int anssize;

int *temp;
int tempindex;

void dfs(int cur,int n,int k)
{
    if (tempindex + (n - cur + 1) < k) {
        return ;
    }
    if (tempindex == k) {
        int *t = malloc(sizeof(int) * k);
        for (int i = 0;i < k;++i) {
            t[i] = temp[i];
        }
        ans[anssize++] = t;
        return ;
    }
    temp[tempindex++] = cur;
    dfs(cur + 1,n,k);
    tempindex--;
    dfs(cur + 1,n,k);
}

int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    ans = malloc(sizeof(int *) * 10001);
    temp = malloc(sizeof(int) * k);
    tempindex = anssize = 0;
    dfs(1,n,k);
    *returnSize = anssize;
    *returnColumnSizes = malloc(sizeof(int) * anssize);
    for (int i = 0;i < anssize;++i) {
        (*returnColumnSizes)[i] = k;
    }
    return ans;
}