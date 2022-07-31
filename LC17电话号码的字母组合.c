/*
 * @Author: Aspirin
 * @Date: 2022-07-31 15:28:25
 * @LastEditTime: 2022-07-31 21:10:38
 * @FilePath: /Leetcode/Leetcodes/LC17电话号码的字母组合.cpp
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <ctype.h>
#include <math.h>
#include <string.h>

char *Str = NULL;
int len = 0;

char **combutions = NULL;
int combutions_size = 0;

char *combution = NULL;
int combution_size = 0;

char Load[12][5] = {
    "\0",
    "\0",
    "abc\0",
    "def\0",
    "ghi\0",
    "jkl\0",
    "mno\0",
    "pqrs\0s",
    "tuv\0",
    "wxyz\0",
    "\0",
    "\0"
};

void str(int index)
{
    if (len == index) {
        char *temp = (char *)malloc(sizeof(char) * (combution_size + 1));
        memcpy(temp, combution, sizeof(char) * (combution_size + 1));
        combutions[combutions_size++] = temp;
    } else {
        char t = Str[index];
        char *T = Load[t - '0'];
        int x = strlen(T);
        for (int i = 0;i < x; ++i) {
            combution[combution_size++] = T[i];
            combution[combution_size] = 0;
            str(index + 1);
            combution[--combution_size] = 0;
        }
    }
}

char ** letterCombinations(char * digits, int* returnSize)
{
    len = strlen(digits);
    if (len == 0) {
        *returnSize = 0;
        return combutions;
    }
    int lens = pow(4, len);
    Str = digits;
    combution = malloc(sizeof(char *) * len);
    combutions = malloc(sizeof(char *) * lens);
    combutions_size = 0;
    combutions_size = 0;
    str(0);
    *returnSize = combutions_size;
    return combutions;    
}