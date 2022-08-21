/*
 * @Author: Aspirin
 * @Date: 2022-08-21 17:36:04
 * @LastEditTime: 2022-08-21 17:51:09
 * @FilePath: /Leetcode/Leetcodes/LC56.c
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
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>

int cmp(const void *a,const void *b)
{
    int *_a = *(int **)a;
    int *_b = *(int **)b;
    if (_a[0] == _b[0]) {
        return _a[1] - _b[1];
    }
    return _a[0] - _b[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    *returnColumnSizes = malloc(sizeof(int *) * intervalsSize);
    int ansSize = 0;
    int **ans = malloc(sizeof(int *) * intervalsSize);
    bool flag = false;
    
    qsort(intervals, intervalsSize, sizeof(intervals[0]), cmp);
    int temp[2] = {intervals[0][0], intervals[0][1]};

    for (int i = 1; i < intervalsSize; ++i) {
        if (intervals[i][0] <= temp[1]) {
            temp[0] = fmin(temp[0], intervals[i][0]);
            temp[1] = fmax(temp[1], intervals[i][1]);
            flag = true;
        } else {
            int *t = malloc(sizeof(int) * 2);
            t[0] = temp[0];
            t[1] = temp[1];
            ans[ansSize] = t;
            (*returnColumnSizes)[ansSize++] = 2;
            temp[0] = intervals[i][0];
            temp[1] = intervals[i][1];
            flag = false;
        }
    }

    int *t = malloc(sizeof(int) * 2);
    t[0] = temp[0];
    t[1] = temp[1];
    ans[ansSize] = t;
    (*returnColumnSizes)[ansSize++] = 2;
    *returnSize = ansSize;
    return ans;
}