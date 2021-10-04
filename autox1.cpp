/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-24 20:40:33
 * @LastEditTime: 2021-09-24 21:26:16
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> keys(3);
    for(int i = 0;i < 3;++i)
    {
        cin >> keys[i];
    }
    vector<long long> nums(N);
    nums[0] = 0;
    nums[1] = 0;
    nums[2] = 1;
    unsigned long int sum = 1;
    for(int j = 3;j < N;++j)
    {
        nums[j] = (keys[0] * nums[j-1])%1000000009 +( keys[1] * nums[j-2])%1000000009 + (keys[2] * nums[j-3])%1000000009;
        sum += nums[j];
        sum %= 1000000009;
    }
    cout << nums[N-1] <<" ";
    cout << sum;
}