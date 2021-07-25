#include<stdio.h>
#include<Windows.h>
#define productor 2
#define consumers 3
#define buffers 10
#define P(S)  WaitForSingleObject(S,INFINITE) 
#define V(S)  ReleaseSemaphore(S,1,NULL)	  

int nextp1 = 1000;
int nextp2=2000;						
int in = 0, out = 0;				
int buf[buffers] = { 0 };	
FILE *fpWrite=fopen("D:\\4.txt","w");  

HANDLE empty, full;			
HANDLE huchu;				
									
DWORD WINAPI producer(LPVOID pM)
{
	while (true)
	{
		int id = *((int*)(pM));	
		Sleep(100);
		P(empty);
		P(huchu);

		Sleep(100);
		if(id==1)
		{
		buf[in] = nextp1;
		fprintf(fpWrite,"������%d ������%d ���뻺����%d\n", id, nextp1, in);
		nextp1++;
		}
		else
		{
			buf[in]=nextp2;
			fprintf(fpWrite,"������%d ������%d ���뻺����%d\n", id, nextp2, in);
            nextp2++;
		}
				
		in = (in + 1) % buffers;

		V(huchu);
		V(full);
		if (nextp1 > 1200||nextp2>2200)
		{
		    fclose(fpWrite);
			break;
		}
	}
	return 0;
}
DWORD WINAPI consumer(LPVOID pM)

{
	while (true)
	{
		int id = *((int*)(pM));	
		Sleep(100);
		P(full);
		P(huchu);

		Sleep(100);
		int num = buf[out];
		buf[out] = 0;
		fprintf(fpWrite,"\t\t\t\t\t\t������%d ������%d ȡ��������%d\n", id, num, out);
		out = (out + 1) % buffers;

		V(huchu);
		V(empty);
		
		if (nextp1 > 1200||nextp2>2200)
		{
			fclose(fpWrite);
			break;
		}
	}
	return 0;
}
int main()
{
	fprintf(fpWrite,"\t\t\t���������������⣺%d������ %d������ %d������\n\n", productor, consumers, buffers);
	empty = CreateSemaphore(NULL, buffers, buffers, NULL);
	full = CreateSemaphore(NULL, 0, buffers, NULL);
	huchu = CreateSemaphore(NULL, 1, 1, NULL);

	const int num_of_thread = consumers + productor;
	HANDLE hThread[num_of_thread];

	int pID[2];
	for (int i = 0; i < productor; i++)
	{
		pID[i]= i + 1;
		hThread[i] = CreateThread(NULL, 0, producer, (LPVOID*)&pID[i], 0, NULL);
	}
	int cID[2];
	for (int i = 0; i < consumers; i++)
	{
		cID[i] = i + 1;
		hThread[i + productor] = CreateThread(NULL, 0, consumer, (LPVOID*)&cID[i], 0, NULL);
	}
	WaitForMultipleObjects(num_of_thread, hThread, TRUE, INFINITE);
	printf("д�����\n");
	getchar();
	return 0;
}

