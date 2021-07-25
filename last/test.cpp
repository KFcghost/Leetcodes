#include<stdio.h>
#include<windows.h>
#include<process.h>
 
#define N 5                          //��ѧ�Ҹ���
#define LEFT(i) ((i) + N - 1) % N    //�����ѧ�ұ��
#define RIGHT(i) ((i) + 1) % N       //�ұ���ѧ�ұ��
#define THINKING 0                   //˼��״̬
#define HUNGRY 1                     //����״̬
#define EATING 2                     //�Ͳ�״̬
 
int state[N];                        //��ѧ��״̬����
HANDLE mutex;                        //״̬���ʻ���������֤��һʱ�̣�ֻ��һ����ѧ���߳��ڼ����������״̬
HANDLE semaphore[N];                 //��ѧ���߳��ź�������ʶ��ѧ���Ƿ��ȡ�˿��ӣ������߳�����
HANDLE semPar;                       //�߳�ͬ���ź�����
 
void thinking(int i);  //˼��
void eating(int i);   //�Է�
void take_chopsticks(int i);  
void put_chopsticks(int i);    
void test(int i);        //�ж������Ƿ��пտ���
 
unsigned int __stdcall philosopher(void *pM)
{
    int i,cnt =20;
    i = *(int*)pM;
    //�̱߳�ţ�ͬ��
    ReleaseSemaphore(semPar, 1, NULL);
    while(cnt--)// �涨ÿλ��ѧ�����ò�20�κ���� 
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
    //�����޸ļ������ѧ��״̬
    WaitForSingleObject(mutex, INFINITE);
    state[i] = HUNGRY;
    test(i);
    ReleaseSemaphore(mutex, 1, NULL);
    //���������ֻ���ӣ������ִ�У����������ڴ˴����ȴ��ھӷ��¿���
    WaitForSingleObject(semaphore[i], INFINITE);
}
 
void put_chopsticks(int i)
{
    WaitForSingleObject(mutex, INFINITE);
    state[i] = THINKING;
    test(LEFT(i));                         //��������ѧ���Ƿ���ԾͲ�
    test(RIGHT(i));                        //����ұ���ѧ���Ƿ���ԾͲ�
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
    printf("��ѧ��[%d]���ڳԷ�\n", i);
    Sleep(3000);
    printf("��ѧ��[%d]�Ѿ����� ���¿���\n\n", i);
}
 
void thinking(int i)
{   printf("��ѧ��[%d]����˼��\n", i);
    Sleep(3000);
	printf("��ѧ��[%d]˼�������\n\n", i);
 }
 
 
int main()
{
    int i;
    HANDLE thread[N];
	printf("--------------------------------\n");
	printf("-         ģ����ѧ�ҽ���       -\n");
	printf("********************************\n");
    mutex = CreateSemaphore(NULL, 1, 1, NULL);  //�趨ÿ����ѧ����˼��
    for(i = 0;i < N;i++)
    {
        semaphore[i] = CreateSemaphore(NULL, 0, 1, NULL);    //��ÿ���ź�����ֵ
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