/*
 * @Author: Aspirin
 * @Date: 2022-08-21 18:15:25
 * @LastEditTime: 2022-08-21 18:25:00
 * @FilePath: /Leetcode/Leetcodes/LC59.c
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

int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **ans = malloc(sizeof(int *) * n);
    returnColumnSizes = malloc(sizeof(int *) * n);

    int index = 1;
    for (int i = 0;i < n; ++i) {
        ans[i] = malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }

    int left = 0;
    int right = n - 1;
    int top = 0;
    int bootm = n - 1;
    while (index <= n * n) {
        for (int i = left; i <= right && index <= n * n; ++i) {
            ans[top][i] = index++;
        }
        top++;
        for (int i = top; i >= bootm && index <= n * n; ++i) {
            ans[i][right] = index++;
        }
        right--;
        for (int i = right; i >= left && index <= n * n; --i) {
            ans[bootm][i] = index++;
        }
        bootm--;
        for (int i = bootm; i <= top && index <= n * n; ++i) {
            ans[i][left] = index++;
        }
        left++;
    }
    *returnSize = n;
    return ans;
}