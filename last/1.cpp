#include <iostream>
using namespace std;

int main()
{
	int max,r;
	int in[100][100] = { 0 };
	int max2[100][100] = { 0 };
	cin >> r;
	for (int i=0; i < r; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			cin >> in[i][j];
		}
	}
	max2[0][0] = in[0][0];
	for (int i = 1; i < r; i++)
	{
		max2[i][0] = in[i][0]+max2[i-1][0];
		for (int j = 1; j <= i; j++)
		{
			if (i != j)
				(max2[i - 1][j] + in[i][j]) > (max2[i - 1][j - 1] + in[i][j]) ? max2[i][j] = max2[i - 1][j] + in[i][j] : max2[i][j] = max2[i - 1][j - 1] + in[i][j];
			else
				max2[i][j] = max2[i - 1][j - 1]+in[i][j];
		}
	}
	max = in[0][0];
	for (int i = 0; i <=r ; i++)
	{
		if (max2[r-1][i] > max)
			max = max2[r-1][i];
	}
	cout << max;
	return 0;
}