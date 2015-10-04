#include<stdio.h>
int dp[32];
int main()
{
    int n;

    int a[40]={0},d[40]={0};
    a[0]=d[1]=0;
    a[1]=d[0]=1;
    for(int i=2;i<=31;i++)
    {
        a[i] = d[i-1]+a[i-2];
        d[i] = 2*a[i-1]+ d[i-2];
    }
    scanf("%d",&n);
    while(n!=-1)
    {
        printf("%d\n",d[n]);
        scanf("%d",&n);
    }
}

