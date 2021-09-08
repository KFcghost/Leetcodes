/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-09-07 19:24:05
 * @LastEditTime: 2021-09-08 10:10:05
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:
    static constexpr int TARGET = 24;
    static constexpr double EPSILON = 1e-6;
    static constexpr int ADD = 0, MULTIPLY = 1, SUBTRACT = 2, DIVIDE = 3;

    bool judgePoint24(vector<int>& cards) {
        vector<double> temp;
        for(int i = 0;i < cards.size();++i)
        {
            temp.emplace_back(static_cast<double> (cards[i]));
        }
        return get24(temp);
    }

    bool get24(vector<double> temp)
    {
        if(temp.size() == 0)
        {
            return false;
        }
        if(temp.size() == 1)
        {
            return fabs(temp[0] - TARGET) < EPSILON;
        }
        for(int i = 0;i < temp.size();++i)
        {
            for(int j = 0;j < temp.size();++j)
            {
                if(i != j)
                {
                    vector<double> temp2;
                    for(int k = 0;k < temp.size();++k)
                    {
                        if(k != i && k != j)
                        {
                            temp2.emplace_back(temp[k]);
                        }
                    }
                    for(int k = 0;k < 4;++k)
                    {
                        if(k < 2 && i > j)
                            continue;
                        if(k == ADD)
                        {
                            temp2.emplace_back(temp[i] + temp[j]);
                        }
                        else if(k == MULTIPLY)
                        {
                            temp2.emplace_back(temp[i] * temp[j]);
                        }
                        else if(k == SUBTRACT)
                        {
                            temp2.emplace_back(temp[i] - temp[j]);
                        }
                        else if(k == DIVIDE)
                        {
                            if(fabs(temp[j]) < EPSILON)
                                continue;
                            temp2.emplace_back(temp[i] / temp[j]);
                        }
                        if(get24(temp2))
                            return true;
                        temp2.pop_back();
                    }
                }
            }
        }
        return false;
    }

    bool solve(vector<double> &l) {
        if (l.size() == 0) {
            return false;
        }
        if (l.size() == 1) {
            return fabs(l[0] - TARGET) < EPSILON;
        }
        int size = l.size();
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j) {
                    vector<double> list2 = vector<double>();
                    for (int k = 0; k < size; k++) {
                        if (k != i && k != j) {
                            list2.emplace_back(l[k]);
                        }
                    }
                    for (int k = 0; k < 4; k++) {
                        if (k < 2 && i > j) {
                            continue;
                        }
                        if (k == ADD) {
                            list2.emplace_back(l[i] + l[j]);
                        } else if (k == MULTIPLY) {
                            list2.emplace_back(l[i] * l[j]);
                        } else if (k == SUBTRACT) {
                            list2.emplace_back(l[i] - l[j]);
                        } else if (k == DIVIDE) {
                            if (fabs(l[j]) < EPSILON) {
                                continue;
                            }
                            list2.emplace_back(l[i] / l[j]);
                        }
                        if (solve(list2)) {
                            return true;
                        }
                        list2.pop_back();
                    }
                }
            }
        }
        return false;
    }
};