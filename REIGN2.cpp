#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

long long int a[5000],b[5000];
long long int dp[5011][5011];

int sort_pred(pair<long long int,long long int>A,pair<long long int,long long int>B)
{
    if((A.first>B.first) || (A.first==B.first && A.second > B.second)) return 1;
    return 0;
}

int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a[i]);
        }
        for(i=0;i<n;i++)
        {
            scanf("%lld",&b[i]);
        }
        vector<pair<int,int> > val;
        val.clear();
        for(i=0;i<n;i++)
        {
            val.push_back(make_pair(b[i],a[i]));
        }
        sort(val.begin(),val.end(),sort_pred);
        memset(dp,0,sizeof dp);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
            {
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]+val[i-1].second + (j-1)*val[i-1].first);
            }
        }
        for(i=1;i<=n;i++)
        {
            printf("%lld ",dp[n][i]);
        }
        printf("\n");
    }
}
