/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2022-01-19 10:56:18
 * @LastEditTime: 2022-01-20 09:01:56
 * @LastEditors: Aspirin
 */

#include <iostream>
#include "vector"

using namespace std;

class un
{
    vector<int> load;

public:
    void makesize(int i)
    {
        load.resize(i);
        for(int j = 0;j < i;++j)
        {
            load[j] = j;
        }
    }

    int find(int x)
    {
        return load[x];
    }

    void unionx(int x,int y)
    {
        int xx = find(x);
        int yy = find(y);
        if(xx != yy)
        {
            for(int i = 0;i < load.size();++i)
            {
                if(load[i] == yy)
                    load[i] = xx;
            }
        }
    }

    bool isparents(int x,int y)
    {
        if(find(x) == find(y))
            return true;
        return false;
    }
};

int main()
{
    un temp;
    temp.makesize(10);
    temp.unionx(1, 2);
    temp.unionx(2, 5);
    temp.unionx(5, 6);
    temp.unionx(6, 7);
    temp.unionx(3, 8);
    temp.unionx(8, 9);
    cout <<temp.isparents(1, 5) << endl; // true
    cout <<temp.isparents(7, 5) << endl; // true
    cout <<temp.isparents(4, 9) << endl; // true
    // 1-2-5-6-7 3-8-9-4
    temp.unionx(9, 4);
    cout <<temp.isparents(4, 9) << endl; // true
}