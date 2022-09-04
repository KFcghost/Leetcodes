/*
 * @Author: Aspirin
 * @Date: 2022-08-21 11:42:59
 * @LastEditTime: 2022-09-04 10:01:52
 * @FilePath: /Leetcode/Leetcodes/LC57.c
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
#include <stdbool.h>
#include <math.h>

int** insert(int** intervals, int intervalsSize, int* intervalsColSize, int* newInterval, int newIntervalSize, int* returnSize, int** returnColumnSizes){
    int **ans = malloc(sizeof(int *) * (intervalsSize + 1));
    int ansSize = 0;
    int **returnSize = malloc(sizeof(int *) * (intervalsSize + 1));
    int temp[2];
    temp[0] = intervals[0][0];
    temp[1] = intervals[0][1];
    bool flag = false;

    for (int i = 0; i < intervalsSize; ++i) {
        if (temp[1] < intervals[i][0]) {
            if (!flag) {
                int *t = malloc(sizeof(int) * 2);
                t[0] = temp[0];
                t[1] = temp[1];
                ans[ansSize] = t;
                returnSize[ansSize++] = 2;
            }
            int *t = malloc(sizeof(int) * 2);
            t[0] = intervals[i][0];
            t[1] = intervals[i][1];
            ans[ansSize] = t;
            returnSize[ansSize++] = 2;
        } else if (temp[0] > intervals[i][1]) {
            int *t = malloc(sizeof(int) * 2);
            t[0] = intervals[i][0];
            t[1] = intervals[i][1];
            ans[ansSize] = t;
            returnSize[ansSize++] = 2;
        } else {
            temp[0] = fmin(temp[0],intervals[i][0]);
            temp[1] = fmax(temp[1],intervals[i][1]);
        }
    }
    if (!flag) {
        int *t = malloc(sizeof(int) * 2);
        t[0] = temp[0];
        t[1] = temp[1];
        ans[ansSize] = t;
        returnSize[ansSize++] = 2;
    }
    *returnSize = ansSize;
    return ans;
}