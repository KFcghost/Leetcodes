/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-11-10 10:26:22
 * @LastEditTime: 2021-11-10 11:21:58
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        vector<int> load(arr.size()+1);
        load[0] = 0;
        int ans = 0;

        for(int i = 0;i < arr.size();++i)
        {
            sum += arr[i];
            load[i+1] = sum;
            int now = i + 1;
            int pre = now - 2;
            while(now >= 1 && pre >= 1)
            {
                int temp = load[now] - load[pre-1];
                ans += (load[now] - load[pre-1]);
                pre -= 2;
            }
        }
        ans += sum;
        return ans;
    }
};

//数学方法，左右数量乘2得出在多少个奇数数组中出现过
/* class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int sum = 0;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int leftCount = i, rightCount = n - i - 1;
            int leftOdd = (leftCount + 1) / 2;
            int rightOdd = (rightCount + 1) / 2;
            int leftEven = leftCount / 2 + 1;
            int rightEven = rightCount / 2 + 1;
            sum += arr[i] * (leftOdd * rightOdd + leftEven * rightEven);
        }
        return sum;
    }
}; */