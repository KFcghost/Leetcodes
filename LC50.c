/*
 * @Author: Aspirin
 * @Date: 2022-08-21 11:27:03
 * @LastEditTime: 2022-08-21 11:35:41
 * @FilePath: /Leetcode/Leetcodes/LC50.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */

#include <stdio.h>

double myPow(double x, int n){
    if (n == 0) return 1;
    if (n == 1) return x;
    if (n == -1) return 1/x;

    double helf = myPow(x, n / 2);
    double rest = myPow(x, n % 2);
    return rest * helf * helf;
}