#include<stdio.h>
#include<windows.h>
#include<process.h>
 
#define N 5                          //哲学家个数
#define LEFT(i) ((i) + N - 1) % N    //左边哲学家编号
#define RIGHT(i) ((i) + 1) % N       //右边哲学家编号
#define THINKING 0                   //思考状态
#define HUNGRY 1                     //饥饿状态
#define EATING 2                     //就餐状态
 
int state[N];                        //哲学家状态数组
HANDLE mutex;                        //状态访问互斥量，保证任一时刻，只有一个哲学家线程在检查左右两边状态
HANDLE semaphore[N];                 //哲学家线程信号量，标识哲学家是否获取了筷子，否则线程阻塞
HANDLE semPar;                       //线程同步信号量，
 
void thinking(int i);  //思考
void eating(int i);   //吃饭
void take_chopsticks(int i);  
void put_chopsticks(int i);    
void test(int i);        //判断左右是否有空筷子
 
unsigned int __stdcall philosopher(void *pM)
{
    int i,cnt =20;
    i = *(int*)pM;
    //线程编号，同步
    ReleaseSemaphore(semPar, 1, NULL);
    while(cnt--)// 规定每位哲学家用用餐20次后结束 
    {
        thinking(i);
        take_chopsticks(i);
        eating(i);
        put_chopsticks(i);
    }
    return 0;
}
 
void take_chopsticks(int i)
{
    //互斥修改及检查哲学家状态
    WaitForSingleObject(mutex, INFINITE);
    state[i] = HUNGRY;
    test(i);
    ReleaseSemaphore(mutex, 1, NULL);
    //若获得了两只筷子，则继续执行，否则阻塞在此处，等待邻居放下筷子
    WaitForSingleObject(semaphore[i], INFINITE);
}
 
void put_chopsticks(int i)
{
    WaitForSingleObject(mutex, INFINITE);
    state[i] = THINKING;
    test(LEFT(i));                         //检查左边哲学家是否可以就餐
    test(RIGHT(i));                        //检查右边哲学家是否可以就餐
    ReleaseSemaphore(mutex, 1, NULL);
}
 
void test(int i)
{
    if(state[i] == HUNGRY && state[LEFT(i)] != EATING && state[RIGHT(i)] != EATING)
    {
        state[i] = EATING;
        ReleaseSemaphore(semaphore[i], 1, NULL);
    }
}
 
void eating(int i)
{
    printf("哲学家[%d]正在吃饭\n", i);
    Sleep(3000);
    printf("哲学家[%d]已经吃完 放下筷子\n\n", i);
}
 
void thinking(int i)
{   printf("哲学家[%d]正在思考\n", i);
    Sleep(3000);
	printf("哲学家[%d]思考完饿了\n\n", i);
 }
 
 
int main()
{
    int i;
    HANDLE thread[N];
	printf("--------------------------------\n");
	printf("-         模拟哲学家进餐       -\n");
	printf("********************************\n");
    mutex = CreateSemaphore(NULL, 1, 1, NULL);  //设定每个哲学家在思考
    for(i = 0;i < N;i++)
    {
        semaphore[i] = CreateSemaphore(NULL, 0, 1, NULL);    //将每个信号量赋值
    }
 
    semPar = CreateSemaphore(NULL, 0, 1, NULL);
 
    for(i = 0;i <N;i++)
    {
        thread[i] = (HANDLE)_beginthreadex(NULL, 0,philosopher, &i, 0, NULL);
        WaitForSingleObject(semPar, INFINITE);
    }
    WaitForMultipleObjects(N, thread, TRUE, INFINITE);
	return 0;
}