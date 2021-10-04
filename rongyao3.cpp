/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-25 19:05:41
 * @LastEditTime: 2021-10-04 15:48:38
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int mindep(string word1, string word2)
{
    int n = word1.size();
    int m = word2.size();

    if (n * m == 0)
        return n + m;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n + 1; ++i)
    {
        dp[i][0] = i;
    }
    for (int j = 0; j < m + 1; ++j)
    {
        dp[0][j] = j;
    }

    for (int i = 1; i < n + 1; ++i)
    {
        for (int j = 1; j < m + 1; ++j)
        {
            int left = dp[i - 1][j] + 1;
            int down = dp[i][j - 1] + 1;
            int left_down = dp[i - 1][j - 1];
            if (word1[i - 1] != word2[j - 1])
                left_down += 1;
            dp[i][j] = min(left, min(down, left_down));
        }
    }
    return dp[n][m];
}

int main()
{
    long N;
    cin >> N;
    vector<string> befor;
    vector<string> after;
    string temp;
    for (int i = 0; i < N; ++i)
    {
        cin >> temp;
        befor.push_back(temp);
    }
    for (int j = 0; j < N; ++j)
    {
        cin >> temp;
        after.push_back(temp);
    }
    long ans = 0;
    for (int i = 0; i < N; ++i)
    {
        ans += mindep(befor[i], after[i]);
    }
    cout << ans;
    return 0;
}