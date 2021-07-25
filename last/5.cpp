#include <iostream>
using namespace std;

int main()
{
    long long int w;
    cin>>w;
    long long int n;
    for(long long int r=0;r<w;r++)
    {
        cin>>n;
        n=2*n*n+1-n;
        cout<<n<<'\n';
    }
    return 0;
}