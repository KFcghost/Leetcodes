/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-16 21:10:03
 * @LastEditTime: 2021-10-04 21:05:04
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <string>

using namespace std;

struct Tirenode
{
    /* data */
    string word;
    unordered_map<char,Tirenode *> next;
    Tirenode(){
        this->word = "";
    }
};

void insertword(Tirenode *root,const string word)
{
    Tirenode *newroot = root;

    for(auto x : word)
    {
        if(!newroot->next.count(x))
        {
            newroot->next[x] = new Tirenode();
        }
        newroot = newroot->next[x];
    }
    newroot->word = word;
}


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();

        for(int i = 0;i < m;++i)
        {
            for(int j = 0;j < n;++j)
            {
                
            }
        }
    }
};
