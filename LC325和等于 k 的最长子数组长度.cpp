/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-11-09 19:59:03
 * @LastEditTime: 2021-11-09 20:54:24
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>


using namespace std;

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> load;                    //哈希表存放之前的前缀和
        int prosum = 0;
        load[0] = 0;
        for(int i = 0;i < nums.size();++i)
        {
            prosum += nums[i];
            if(load.find(prosum - k) != load.end())     //根据公式进行查找即可
                ans = max(ans,i-load[prosum - k]+1);
            load.insert(make_pair(prosum,i+1));         //之后的前缀和进行插入，如果之前存在相应的前缀和
        }                                               //则会插入失败
        return ans;
    }
};