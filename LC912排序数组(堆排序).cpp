/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-05 19:49:57
 * @LastEditTime: 2021-09-05 23:48:58
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <random>
#include <time.h>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int length = nums.size();
        for(int i = length/2 -1;i >= 0;--i)
        {
            down(nums,i,length);
        }
        for(int i = length - 1;i != 0;--i)
        {
            swap(nums[0],nums[i]);
            down(nums,0,i);
        }
        return nums;
    }
    void down(vector<int>& nums,int base,int length)
    {
        int max = base;
        int lchild = base * 2 + 1;
        int rchild = base * 2 + 2;
        if(lchild < length && nums[lchild] > nums[max])
        {
            max = lchild;
        }
        if(rchild < length && nums[rchild] > nums[max])
        {
            max = rchild;
        }
        if(max != base)
        {
            swap(nums[base],nums[max]);
            down(nums,max,length);
        }
    }
};
