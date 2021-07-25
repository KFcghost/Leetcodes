#include <stdc++.h>
#include <process.h>
#include <Windows.h>
#include <iostream>

void  OK(void *)
{
    for(int i=0;i!=10;++i)
    {
        std::cout<<i<<std::endl;
    }
    _endthread();
}

void  OK1(void*)
{
    for(int i=60;i!=50;--i)
    {
        std::cout<<i<<std::endl;
    }
    _endthread();

}

int mian()
{
     _beginthread(OK,0,NULL);
    _beginthread(OK1,0,NULL);
    std::cout<<"程序结束\n";
    getchar();
    return 0;
}