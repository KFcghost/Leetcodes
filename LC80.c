/*
 * @Author: Aspirin
 * @Date: 2022-08-24 23:09:11
 * @LastEditTime: 2022-08-28 18:59:46
 * @FilePath: /Leetcode/Leetcodes/LC80.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
#include <stdio.h>

int removeDuplicates(int* nums, int numsSize){
    if (numsSize <= 2) {
        return numsSize;
    }

    int slow = 2,fast = 2;
    while (fast != numsSize) {
        if (nums[slow - 2] != nums[slow]) {
            nums[slow] = nums[fast];
            ++slow;
        }
        ++fast;
    }
    return slow;
}