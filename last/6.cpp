#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
long long int in[100][100];
long long int 
a1[1005][1005]={0},
a2[1005][1005]={0},
a3[1005][1005]={0},
a4[1005][1005]={0};

void get()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int r=1;r<=m;r++)
        {
            cin>>in[i][r];
        }
    }
}
long int algorithm()
{
     for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        a1[i][j]=in[i][j]+max(a1[i-1][j],a1[i][j-1]);}}
    for(int i=n;i>=1;i--){
        for(int j=m;j>=1;j--){
        a2[i][j]=in[i][j]+max(a2[i+1][j],a2[i][j+1]);}}
    for(int i=n;i>=1;i--){
        for(int j=1;j<=m;j++){
        a3[i][j]=in[i][j]+max(a3[i+1][j],a3[i][j-1]);}}
    for(int i=1;i<=n;i++){
        for(int j=m;j>=1;j--){
        a4[i][j]=in[i][j]+max(a4[i-1][j],a4[i][j+1]);}}
    long long int x=0;
    for(int i=2;i<n;i++)
    {
        for(int j=2;j<m;j++)
        {
        x=max(x,a1[i][j-1]+a2[i][j+1]+a3[i+1][j]+a4[i-1][j]);
        x=max(x,a1[i-1][j]+a2[i+1][j]+a3[i][j-1]+a4[i][j+1]);    
        }
    }
    return x;
}

int main()
{
      long long int max1;
      get();
      max1=algorithm();
      cout << max1;
      return 0;
}
