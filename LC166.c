/*
 * @Author: Aspirin
 * @Date: 2022-08-14 18:08:02
 * @LastEditTime: 2022-08-14 19:11:40
 * @FilePath: /Leetcode/Leetcodes/LC166.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
#include <stdio.h>
#include "inc/uthash.h"
#include <malloc/malloc.h>
#include <string.h>
#include <math.h>

#define INT_LEN 1024

struct mystruct
{
    int key;
    int valve;
    UT_hash_handle hh;
};
struct mystruct *ge = NULL;

int ADD_NUM(int key, int pos)
{
    struct mystruct *temp;
    HASH_FIND_INT(ge, &key, temp);
    if (temp != NULL) {
        return temp->valve;
    }
    temp = (struct mystruct *)malloc(sizeof(struct mystruct));
    temp->key = key;
    temp->valve = pos;
    HASH_ADD_INT(ge, key, temp);
    return -1;
}

char * fractionToDecimal(int numerator, int denominator){
    char *buf = (char *)malloc(sizeof(char) * INT_LEN);
    long num = labs(numerator), den = labs(denominator);
    if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0)) {
        sprintf(buf, "-%ld", num / den);
    } else {
        sprintf(buf, "%ld", num / den);
    }
    int pos = strlen(buf);
    int start = -1;
    num = num % den;
    if (num) {
        buf[pos++] = '.';
        while (num && (start = ADD_NUM(num, pos)) == -1) {
            buf[pos++] = (num * 10 / den) + '0';
            num = num * 10 % den;
        }
        if(start != -1){
            for(int i = pos++; i > start; i--){
                buf[i] = buf[i-1];
            }
            buf[start] = '(';
            buf[pos++] = ')';
        }
    }
    buf[pos] = '\0';
    ge = NULL;
    return buf;
}