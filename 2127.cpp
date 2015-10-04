#include<stdio.h>
#include<algorithm>
using namespace std;
long arr1[501],arr2[501],arr3[501];
int dp[501][501];
int lcs(int n1,int n2);
int k=-1;
int main()
{
    int p1,p2,n1,n2;
    while(1)
    {
        scanf("%d",&n1);
        for(int i=0;i<n1;i++)
        {
            scanf("%ld",&arr1[i]);
        }
        scanf("%d",&n2);
        for(int i=0;i<n2;i++)
        {
            scanf("%ld",&arr2[i]);
        }
        printf("%d\n",lcs(n1,n2));
        if(k!=-1)printf("%ld",arr3[0]);
        for(int i=1;i<=k;i++)
        {
            printf("\t%ld",arr3[i]);
        }
        if(k!=-1)printf("\n");
    }
    return 0;
}

int lcs(int n1,int n2)
{
    for(int i =0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0||j==0) dp[i][j]=0;
            else if(arr1[i-1]==arr2[j-1]) {dp[i][j] = dp[i-1][j-1]+1; arr3[++k]=arr1[i-1];}
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n1][n2];
}
