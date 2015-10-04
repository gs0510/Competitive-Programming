#include<stdio.h>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
int dp[2][5000];
int n;
char s[5001];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%s",s);
        string s1;
        for(int i=0;i<n;i++)
        {
            s1[i] = s[n-i-1];
        }
        s1[n]='\0';
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<=n;j++)
            {
                dp[i][j]=0;
            }
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0) dp[i%2][j]=0;
                else if(s[i-1]==s1[j-1]) dp[i%2][j]= dp[(i-1)%2][j-1]+1;
                else dp[i%2][j] = max(dp[(i-1)%2][j] , dp[i%2][j-1]);
            }
        }
        int h=n-dp[n%2][n];
        printf("%d\n",h);
    }
    return 0;
}
