#include <iostream>
using namespace std;

int main()
{
    long long int n;
    cin>>n;
    int in[42];
    long long int m;
    in[0]=0;
    in[1]=0;
    in[2]=1;
    in[3]=2;
    for(int r=4;r<42;r++)
    {
       in[r]=in[r-1]+in[r-2];
    }
    for(long long int r=0;r<n;r++)
    {
        cin>>m;
        cout<<in[m]<<'\n';
    }
    return 0;
}