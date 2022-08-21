/*
 * @Author: Aspirin
 * @Date: 2022-08-21 18:41:58
 * @LastEditTime: 2022-08-21 20:39:26
 * @FilePath: /Leetcode/Leetcodes/LC63.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
#include <stdio.h>

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    int dp[m][n];
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) {
        return 0;
    }

    for (int i = 0; i< m; ++i) {
        for (int j = 0; j < n;++j) {
            if (i == 0 && j == 0) {
                dp[i][j] = 1;
                continue;
            }
            if (obstacleGrid[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
            if (j == 0) {
                dp[i][j] = dp[i - 1][j];
                continue;;
            }
            if (i == 0) {
                dp[i][j] = dp[i][j-1];
                continue;
            }
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[m-1][n-1];
}