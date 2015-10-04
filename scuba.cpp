#include<bits/stdc++.h>
using namespace std;

int ox,nit,n;
int ni[1001],o[1001],wt[1001];
int dp[1001][22][80],visited[1001][22][80];


int solve(int i,int ox,int nit)
{
    if(dp[i][ox][nit]!=-1)
    {
        return dp[i][ox][nit];
    }
    if(nit==0&&ox==0)
    {
        dp[i][ox][nit]=0;
    }
    else if(i==0)
    {
        dp[i][ox][nit]=99999;
    }
    else{
        dp[i][ox][nit] = min(solve(i-1,ox,nit),solve(i-1,max(ox-o[i-1],0),max(nit-ni[i],0))+wt[i-1]);
    }
    return dp[i][ox][nit];
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&ox,&nit);
        scanf("%d",&n);
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<ox+1;j++)
            {
                for(int k=0;k<nit+1;k++)
                {
                    dp[i][j][k]=-1;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            scanf("%d %d %d",&o[i],&ni[i],&wt[i]);
        }
        printf("%d\n",solve(n,ox,nit));
    }
}
