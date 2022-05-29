/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2022-01-23 15:45:56
 * @LastEditTime: 2022-01-23 22:33:14
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

class StockPrice {
public:
    StockPrice() {
        this->maxTimestamp = 0;
    }
    
    void update(int timestamp, int price) {
        maxTimestamp = max(maxTimestamp, timestamp);
        timePriceMap[timestamp] = price;
        pqMax.emplace(price, timestamp);
        pqMin.emplace(price, timestamp);
    }
    
    int current() {
        return timePriceMap[maxTimestamp];
    }
    
    int maximum() {
        while (true) {
            int price = pqMax.top().first, timestamp = pqMax.top().second;
            if (timePriceMap[timestamp] == price) {
                return price;
            }
            pqMax.pop();
        }
    }
    
    int minimum() {
        while (true) {
            int price = pqMin.top().first, timestamp = pqMin.top().second;
            if (timePriceMap[timestamp] == price) {
                return price;
            }
            pqMin.pop();
        }
    }
private:
    int maxTimestamp;
    unordered_map<int, int> timePriceMap;
    priority_queue<pii, vector<pii>, less<pii>> pqMax;
    priority_queue<pii, vector<pii>, greater<pii>> pqMin;
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */