/*
 * @Author: Aspirin
 * @Date: 2022-08-14 11:39:02
 * @LastEditTime: 2022-08-14 16:01:59
 * @FilePath: /Leetcode/Leetcodes/LC71.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
#include <string.h>
#include <stdio.h>
#include <malloc/malloc.h>

static char **split(const char* str, char deilm, int *returnSize)
{
    int n = strlen(str);
    char **ans = (char **)malloc(sizeof(char *) * n);
    int pos = 0;
    int curr= 0;
    int index = 0;

    while(pos < n) {
        while(pos < n && str[pos] == deilm) {
            pos++;
        }
        curr = pos;
        while(pos < n && str[pos] != deilm) {
            pos++;
        }
        if (curr < n)
        {
            char *temp = (char *)malloc(sizeof(char) * (pos - curr + 1));
            strncpy(temp, str + curr, pos - curr);
            temp[pos - curr] = '\0';
            ans[index++] = temp;
        }
    }
    *returnSize = index;
    return ans;
}

char * simplifyPath(char * path){
    int nameSize = 0;
    char **names = split(path, '/', &nameSize);
    char **stack = (char **)malloc(sizeof(char *) * nameSize);
    int stacksize = 0;
    int n =  strlen(path);

    for (int i = 0; i < nameSize; ++i) {
        if (!strcmp(names[i], "..")) {
            if (stacksize > 0)
                stacksize--;
        } else if (strcmp(names[i], ".")) {
            stack[stacksize++] = names[i];
        }
    }

    char *ans = (char *)malloc(sizeof(char) * (n + 1));
    int cur = 0;
    if (stacksize == 0) {
        ans[cur++] = '/';
    } else {
        for(int i = 0; i < stacksize; ++i) {
            ans[cur++] = '/';
            strcpy(ans + cur, stack[i]);
            cur += strlen(stack[i]);
        }
    }
    ans[cur]= '\0';
    for (int i = 0; i < nameSize; ++i) {
        free(names[i]);
    }
    free(names);
    free(stack);
    return ans;
}