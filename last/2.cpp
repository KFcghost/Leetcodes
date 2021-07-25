#include <iostream>
using namespace std;

int main()
{
	int max,r;
	int in[56] = { 0 };
	int out[100];
    in[1]=1;
	in[2]=2;
	in[3]=3;
	in[4]=4;
	for(r=5;r<56;r++)
	{
		in[r]=in[r-1]+in[r-3];
	}
	for (int i=0; i < 1000; i++)
	{
			cin >> out[i];
			if(out[i]==0)
			break;
	}
	for(int i=0;i<1000;i++)
	{
		if(out[i]!=0)
		{
				cout << in[out[i]]<<'\n';
				continue;
		}
				else
				break;
	}
	return 0;
}