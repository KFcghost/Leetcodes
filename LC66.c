/*
 * @Author: Aspirin
 * @Date: 2022-08-21 20:46:03
 * @LastEditTime: 2022-08-21 21:02:46
 * @FilePath: /Leetcode/Leetcodes/LC66.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>

int* plusOne(int* digits, int digitsSize, int* returnSize){
    *returnSize = digitsSize;
    for (int i = digitsSize - 1; i >= 0; --i) {
        digits[i]++;
        if (digits[i] == 10) {
            digits[i] = 0;
            continue;
        }
        break;
    }
    if (digits[0] != 0)
        return digits;
    int *ans = malloc(sizeof(int) * (digitsSize + 1));
    memset(ans,0,sizeof(int) * (digitsSize + 1));
    ans[0] = 1;
    *returnSize = (digitsSize+1);
    return ans;

}