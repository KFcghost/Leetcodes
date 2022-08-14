/*
 * @Author: Aspirin
 * @Date: 2022-08-06 17:10:38
 * @LastEditTime: 2022-08-06 17:26:06
 * @FilePath: /Leetcode/Leetcodes/LC38.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
#include <malloc/malloc.h>
#include <string.h>


char * countAndSay(int n){
    char *first = malloc(sizeof(char) * 5000);
    char *now = malloc(sizeof(char) * 5000);
    char *t = first;
    first[0] = '1';
    first[1] = '\0';
    for (int i = 2; i <= n; ++i) {
        int num = 0;
        char key = first[0];
        int index = 0;
        while (*t != '\0') {
            if (*t == key) {
                num++;
            } else {
                now[index++] = num + '0';
                now[index++] = key;
                key = *t;
                num = 1;
            }
            *t++;
        }
        strcpy(first, now);
    }
    return first;
}