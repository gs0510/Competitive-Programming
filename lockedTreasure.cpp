#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
long dp[31][31];
long pop(int n,int k)
{
    if(n==k)return 1;
    if(k==0)return 1;
    if(dp[n][k]>0)return dp[n][k];
    dp[n][k]=pop(n-1,k-1) +pop(n-1,k);
    return dp[n][k];
}

int main() {
    int ncase,n,k;
    cin>>ncase;
    for(int i=1;i<=ncase;i++)
    {
        cin>>n>>k;
        cout<<"Case "<<i<<": "<<pop(n,k-1)<<endl;
    }
    return 0;
}
