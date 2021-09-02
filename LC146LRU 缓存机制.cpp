/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-08-18 23:58:46
 * @LastEditTime: 2021-08-19 23:47:50
 * @LastEditors: Aspirin
 */
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache {
    unordered_map<int,int> load;
    list<int> temp;
    int SIZE = INT_MIN;
public:
    LRUCache(int capacity) {
        SIZE = capacity;
    }
    
    int get(int key) {
        if(load.find(key) == load.end())
            return -1;
        else{
            temp.remove(key);
            temp.push_front(key);
            return load[key];
        }
    }
    
    void put(int key, int value) {
        if(temp.size() == SIZE){
            if(load.find(key) != load.end()){
                temp.remove(key);
                temp.push_front(key);
                load[key] = value;
            }
            else
            {
            load.erase(temp.back());
            temp.pop_back();
            temp.push_front(key);
            load[key] = value;
            }
        }
        else{
            if(load.find(key) != load.end()){
                temp.remove(key);
                temp.push_front(key);
                load[key] = value;
            }
            else{
                temp.push_front(key);
                load[key] = value;
            }
        }
    }
};
