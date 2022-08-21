/*
 * @Author: Aspirin
 * @Date: 2022-08-20 23:12:47
 * @LastEditTime: 2022-08-20 23:28:20
 * @FilePath: /Leetcode/Leetcodes/LC36.c
 * @Description: self Leetcodes
 * 
 * Copyright (c) 2022 by $ Aspirin, All Rights Reserved. 
 */
#include <stdio.h>
#include <stdbool.h>


bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    int Loadi[9][10] = {0};
    int Loadj[9][10] = {0};
    int Load[3][3][10] = {0};
    
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (board[i][j] != '.') {
                int temp = board[i][j] - '0';
                if (Loadi[i][temp] == 1) {
                    return false;
                }
                Loadi[i][temp] = 1;
                if (Loadj[j][temp] == 1) {
                    return false;
                }
                Loadj[j][temp] = 1;
                if (Load[i/3][j/3][temp] == 1) {
                    return false;
                }
                Load[i/3][j/3][temp] = 1;
            }
        }
    }
    return true;
}