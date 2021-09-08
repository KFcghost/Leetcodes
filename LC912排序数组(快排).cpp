/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-05 19:14:06
 * @LastEditTime: 2021-09-06 20:26:10
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
        int l = 0;
        int r = nums.size() - 1;
        srand(time(0));
        my_sort(nums,l,r);
        return nums;
    }
    void my_sort(vector<int>& nums,int l,int r)
    {
        if(l < r)
        {
            int pos = random_index(nums,l,r);
            my_sort(nums,l,pos-1);
            my_sort(nums,pos+1,r);
        }
    }
    int random_index(vector<int>& nums,int l,int r)
    {
        int index = rand() %(r - l + 1) + l;
        swap(nums[index],nums[r]);
        return myquick_sort(nums,l,r);
    }
    int myquick_sort(vector<int>&nums,int l,int r)
    {
        int base = nums[r];
        int i = l - 1;
        for(int j = l;j < r;++j)
        {
            if(nums[j] <= base)
            {
                i++;
                swap(nums[i],nums[j]);
            }
        }
        swap(nums[i+1],nums[r]);
        return i+1;
    }
};