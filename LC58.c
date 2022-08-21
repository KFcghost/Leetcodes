/*
 * @Author: Aspirin
 * @Date: 2022-08-21 18:11:32
 * @LastEditTime: 2022-08-21 18:13:36
 * @FilePath: /Leetcode/Leetcodes/LC58.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char * s){
    int start = strlen(s) - 1;
    while (start >= 0 && s[start] == ' ') {
        start--;
    }
    int end = start - 1;
    while (end >= 0 && s[end] != ' ') {
        end--;
    }
    return start - end;
}