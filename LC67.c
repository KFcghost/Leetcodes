/*
 * @Author: Aspirin
 * @Date: 2022-08-21 21:04:18
 * @LastEditTime: 2022-08-21 22:24:28
 * @FilePath: /Leetcode/Leetcodes/LC67.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
#include <stdio.h>
#include <string.h>

char * addBinary(char * a, char * b){
    if (strcmp(a,"0") == 0) {
        return b;
    }
    if (strcmp(b,"0") == 0) {
        return a;
    }

    int a1 = strlen(a) - 1;
    int b1 = strlen(b) - 1;
    char *temp = malloc(sizeof(char) * 10020);
    memset(temp,'0',10020);
    int index = 10018;
    temp[10019] = '\0';
    int flag = 0;
    while (a1 != -1 || b1 != -1) {
        int num1 = 0;
        int num2 = 0;
        if (a1 != -1) {
            num1 = a[a1--] - '0';
        }
        if (b1 != -1) {
            num2 = b[b1--] - '0';
        }
        int num = num1 + num2 + flag;
        flag = num / 2;
        num = num % 2;
        temp[index--] = '0' + num;
    }
    if (flag) {
        temp[index--] = '0' + 1;
    }
    char *temp1 = malloc(sizeof(char) * 10020);
    memcpy(temp1,(temp + index + 1),10019 - index);
    return temp1;
}