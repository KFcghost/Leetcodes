/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-10-24 23:44:25
 * @LastEditTime: 2021-11-09 09:43:31
 * @LastEditors: Aspirin
 */
#include <processthreadsapi.h>
#include <iostream>

//懒汉模式,知道第一次用到类的实例时才去实例化
//方法1，加锁方式
class singlenton
{
private:
    /* data */
    //懒汉模式线程安全
    // static pthread_mutex_t mutex;
    static singlenton *instance;
    singlenton(){
        //pthread_mutex_int(&mutex,NULL);
    }
    singlenton(const singlenton &temp){}
    singlenton& operator=(const singlenton& temp){}
public:
    static singlenton* geisingin()
    {
        //pthread_mutex_lock(&mutex);
        //每次需要对对象判空
        if(instance == nullptr)
            instance = new singlenton();
        //pthread_mutex_unlock(&mutex);
        return instance;
    }
};
singlenton * singlenton::instance = nullptr;
//pthread_mutex_t singlenton::mutex;


//懒汉模式，方式2，内部静态变量
class singleton
{
private:
    /* data */
    //static pthread_mutex_t mutex;
    singleton(){
        //pthread_mutex_lock(&mutex);
    }
    singleton(const singlenton& temp){}
    singleton& operator=(const singleton& temp){}
public:
    static singleton* getsinglen()
    {
        static singleton instance;
        return &instance;
    }
};
//pthread_mutex_t singlenton::mutex;

//饿汉模式，本身线程安全无需加锁
class singlenton1
{
private:
    /* data */
    static singlenton1* instance;
    singlenton1(const singlenton1& temp){}
    singlenton1& operator=(const singlenton1& temp){}
protected:
    singlenton1(){}
public:
    static singlenton1* getinstance()
    {
        return instance;
    }
};
singlenton1* singlenton1::instance = new singlenton1();
