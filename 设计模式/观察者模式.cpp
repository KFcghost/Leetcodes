/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-11-09 17:36:56
 * @LastEditTime: 2021-11-09 19:04:52
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <string>
#include <list>

using namespace std;

class subject;

//观察者
class observer
{
protected:
    string name;
    subject* sub;
public:
    observer(string name, subject* sub)
    {
        this->name = name;
        this->sub = sub;
    }
    //纯虚函数
    virtual void update() = 0;
};

class stockobserver : public observer
{
public:
    stockobserver(string name, subject* sub) : observer(name, sub) {}
    void update();
};

class nbaobserver : public observer
{
public:
    nbaobserver(string name, subject* sub) : observer(name, sub) {}
    void update();
};

//被观察者 基类（内部存放了所有观察者以便状态发生变化时，给观察者发送消息）
class subject
{
protected:
    list<observer*> observers;
public:
    string action;
    virtual void attach(observer*) = 0;
    virtual void detach(observer*) = 0;
    virtual void notify() = 0;
};

class secretary : public subject
{
    void attach(observer* obser)
    {
        observers.push_back(obser);
    }
    void detach(observer* obser)
    {
        list<observer*>::iterator iter = observers.begin();
        while (iter != observers.end())
        {
            if ((*iter) == obser)
            {
                observers.erase(iter);
                return;
            }
            ++iter;
        }
    }
    void notify()
    {
        list<observer*>::iterator iter = observers.begin();
        while (iter != observers.end())
        {
            (*iter)->update();
            ++iter;
        }
    }
};

void stockobserver::update()
{
    cout << name << " 收到消息：" << sub->action << endl;
    if (sub->action == "所长来了")
    {
        cout << "我马上关闭股票，装做很认真工作的样子！" << endl;
    }
}

void nbaobserver::update()
{
    cout << name << " 收到消息：" << sub->action << endl;
    if (sub->action == "所长来了")
    {
        cout << "我马上关闭NBA，装做很认真工作的样子！" << endl;
    }
}


int main()
{
    subject* temp = new secretary();
    observer* x = new nbaobserver("xiaoshuai", temp);
    observer* y = new nbaobserver("zuoyue", temp);
    observer* z = new stockobserver("limin", temp);

    temp->attach(x);
    temp->attach(y);
    temp->attach(z);

    temp->action = "去吃饭";
    temp->notify();
    cout << "\n";
    temp->action = "所长来了";
    temp->notify();
    return 0;
}