#include <stdio.h>

int main()
{
    long long int in[52];
    long long int a,b;
    long long int n;
    in[0]=0;
    in[1]=1;
    in[2]=2;
    scanf("%lld",&n);
    for(int r=3;r<52;r++)
    {
        in[r]=in[r-1]+in[r-2];
    }
    for(long long int r=0;r<n;r++)
    {
        scanf("%lld %lld", &a, &b);
		printf("%lld\n", in[b - a]);
    }
    return 0;
}
