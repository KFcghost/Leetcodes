/*
 * @Author: Aspirin
 * @Date: 2022-08-22 22:36:18
 * @LastEditTime: 2022-08-22 23:28:54
 * @FilePath: /Leetcode/Leetcodes/LC75.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
#include <stdio.h>

void swap(int *a,int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sortColors(int* nums, int numsSize){
    int p0 = 0,p2 = numsSize - 1;
    for (int i = 0; i <= p2;++i) {
        while (i <= p2 && nums[i] == 2)
        {
            swap(&nums[i],&nums[p2]);
            p2--;
        }
        if (nums[i] == 0) {
            swap(&nums[i],&nums[p0]);
            p0++;
        }
    }
}
