/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-23 15:41:21
 * @LastEditTime: 2021-09-23 15:55:46
 * @LastEditors: Aspirin
 */
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param seed char字符型vector 字符种子
     * @param size int整型 验证码长度
     * @return string字符串vector
     */
    set<string> ans;
    map<char,int> load;
    vector<string> Permutation(vector<char>& seed, int size) {
        // write code here
        sort(seed.begin(),seed.end());
        string temp = "";
        bfs(seed,0,size,temp);
        vector<string> t(ans.begin(),ans.end());
        return t;
    }
    void bfs(vector<char>& seed,int index,int size,string temp)
    {
        if(temp.size() == size)
        {
            ans.insert(temp);
            return ;
        }
        if(temp.size() > size)
            return ;
        
        for(int i = 0;i < seed.size();++i)
        {
            if(load.find(seed[i]) != load.end())
                continue;
            load[seed[i]] = 1;
            temp += seed[i];
            bfs(seed,i+1,size,temp);
            temp.pop_back();
            load.erase(seed[i]);
        }
    }
};

int main()
{
    vector<char> t = {'0','1','2','3','A'};
    Solution tt;
    tt.Permutation(t,3);
}