/*
 * @Description: LEETCODE
 * @Author: Aspirin
 * @Date: 2021-11-09 10:02:29
 * @LastEditTime: 2021-11-09 10:24:29
 * @LastEditors: Aspirin
 */
#include <iostream>
#include <vector>

using namespace std;

class Operator
{
public:
    int val1,val2;
    virtual double getresult()
    {
        double res = 0;
        return res;
    }
};

class add_Operator : public Operator
{
public:
    virtual double getresult()
    {
        return val1 + val2;
    }
};

class sub_Operator : public Operator
{
public:
    virtual double getresult()
    {
        return val1 - val2;
    }
};

class mul_Operator : public Operator
{
public:
    virtual double getresult()
    {
        return val1 * val2;
    }
};

class div_Operator : public Operator
{
public:
    virtual double getresult()
    {
        return val1 / val2;
    }
};


class factorysample
{
public:
    static Operator *createprodect(char op)
    {
        switch (op)
        {
        case '+':
            return new add_Operator();
            break;
        case '-':
            return new sub_Operator();
            break;
        case '*':
            return new mul_Operator();
            break;
        case '/':
            return new div_Operator();
            break;

        default:
            return new add_Operator();
            break;
        }
    }
};

int main()
{
    int a,b;
    a = 10;
    b = 20;
    Operator *p = factorysample::createprodect('+');
    p->val1 = a;
    p->val2 = b;
    cout << p->getresult() << endl;

    p = factorysample::createprodect('/');
    p->val1 = a;
    p->val2 = b;
    cout << p->getresult() << endl;
}