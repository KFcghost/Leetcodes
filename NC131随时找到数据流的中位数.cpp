
#include <vector>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    priority_queue<int> low;//最大堆，存的是较小一半元素
    priority_queue<int,vector<int>,greater<int>> high;//最小堆，存的是较大一半元素
    /**
     * the medians
     * @param operations int整型vector<vector<>> ops
     * @return double浮点型vector
     */
    vector<double> flowmedian(vector<vector<int> >& operations) {
        // write code here
        vector<double> ans;
        for(int i=0;i<operations.size();i++){
            //添加操作
            if(operations[i].size()==2&&operations[i][0]==1)
                add(operations[i][1]);
            //寻找中位数
            else if(operations[i].size()==1&&operations[i][0]==2)
                ans.push_back(findMedian());
        }
        return ans;
    }
    void add(int num){
        low.push(num);
        int tmp=low.top();
        low.pop();
        high.push(tmp);
        //当high中元素为n+2,low中元素为n->需要从high中移一个元素到low
        if(high.size()>low.size()+1){
            low.push(high.top());
            high.pop();
        }
    }
    double findMedian(){
        //MedianHolder结构为空
        if(high.size()==0)
            return -1;
        //分别为n,n+1
        else if(low.size()<high.size())
            return high.top();
        //分别为n,n
        else{
            double ans=high.top()+low.top();
            return ans/2.0;
        }
    }
};

int main(){
    Solution T;
    vector<vector<int>> temp={{1,5},{2},{1,3},{2},{1,6},{2},{1,7},{2}};
    T.flowmedian(temp);
    cout<<"OKOK";
}