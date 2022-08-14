/*
 * @Author: Aspirin
 * @Date: 2022-08-06 17:42:21
 * @LastEditTime: 2022-08-14 09:53:10
 * @FilePath: /Leetcode/Leetcodes/LC49.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <malloc/malloc.h>
#include <stdio.h>
#include "inc/uthash.h"

struct mystruct
{
    int ikey;
    int now;
    int indexi[1000];
    UT_hash_handle hh;
};
struct mystruct *ge = NULL;

struct mystruct *findload(int key) {
    struct mystruct *temp;
    HASH_FIND_INT(ge, &key, temp);
    return temp;
}

struct mystruct *addload(int ikey, int indexi) {
    struct mystruct *temp = NULL;
    temp = findload(ikey);
    if (temp == NULL) {
        temp = (struct mystruct*)malloc(sizeof(struct mystruct));
        temp->ikey = ikey;
        temp->indexi[0] = indexi;
        temp->now = 1;
        HASH_ADD_INT(ge, ikey, temp);
    } else {
        temp->indexi[temp->now] = indexi;
        temp->now++;
    }
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    for (int i = 0; i < strsSize; ++i) {
        int allnums = 0;
        for (int j = 0; j< strlen(strs[i]); ++j) {
            allnums += strs[i][j];
        }
        addload(allnums, i);
    }
    
    int Num = HASH_COUNT(ge);
    struct mystruct *s = NULL;
    char ***ans = (char ***)malloc(sizeof(char **) * Num);
    *returnSize = Num;
    (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    for (s = ge; s != NULL; s = (struct mystruct *)s->hh.next) {
        int all = s->now;
        ans[i++] = (char **)malloc(sizeof(char **) * all);
        for (int j = 0; j < all; ++j) {
            ans[i][j] = strs[s->indexi[j]];
        }
        (*returnColumnSizes)[i] = all;
    }
    return ans;
}
