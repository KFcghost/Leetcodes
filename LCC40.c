/*
 * @Author: Aspirin
 * @Date: 2022-08-20 23:30:33
 * @LastEditTime: 2022-08-21 05:59:13
 * @FilePath: /Leetcode/Leetcodes/LCC40.c
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
#include <stdlib.h>
#include <string.h>
#include <math.h>

int **ans;
int *ansLen;
int anssize;

int *squeue;
int squeueSize;

int **fre;
int freSize;

int cmp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

void dfs(int now, int target)
{
    if (target == 0) {
        int *temp = malloc(sizeof(int) * squeueSize);
        memcpy(temp,squeue,sizeof(int) * squeueSize);
        ans[anssize] = temp;
        ansLen[anssize++] = squeueSize;
        return ;
    }

    if (now == freSize || target < fre[now][0]) {
        return ;
    }
    dfs(now + 1, target);

    int max = fmin(target/fre[now][0] , fre[now][1]);
    for (int i = 1;i <= max;++i) {
        squeue[squeueSize++] = fre[now][0];
        dfs(now + 1,target - i * fre[now][0]);
    }
    squeueSize -= max;
}

int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes){
    qsort(candidates,candidatesSize,sizeof(int),cmp);
    ans = (int **)malloc(sizeof(int *) * 2001);
    ansLen = (int *)malloc(sizeof(int) * 2001);
    squeue = (int *)malloc(sizeof(int) * 2001);
    fre= (int **)malloc(sizeof(int *) * 2001);
    anssize = squeueSize = freSize = 0;

    for (int i = 0; i < candidatesSize; ++i) {
        if (i == 0 || candidates[i] != candidates[i - 1]) {
            fre[freSize] = malloc(sizeof(int) * 2);
            fre[freSize][0] = candidates[i];
            fre[freSize++][1] = 1;
        } else {
            fre[freSize - 1][1]++;
        }
    }
    dfs(0 , target);
    *returnSize = anssize;
    *returnColumnSizes = ansLen;
    return ans;
}