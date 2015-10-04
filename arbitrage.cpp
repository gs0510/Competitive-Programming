#include<stdio.h>
#include<string>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<string,int> nodes;
double dp[32][32];
int main()
{
    int n,num=0,flag;
    scanf("%d",&n);
    while(n!=0)
    {
        flag=0;
        num++;
        string a,b;
        for(int i=0;i<n;i++)
        {
            cin >> a;
            nodes[a]=i;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=0;
            }
        }
        int m;
        scanf("%d",&m);
  //      printf("%d m\n",m);
        int i,j; double wt;
        for(int k=0;k<m;k++)
        {
            cin >> a >> wt >> b;
            i = nodes.find(a)->second;
            j = nodes.find(b)->second;
            dp[i][j]=wt;
        }

        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dp[i][j]= max(dp[i][j],dp[i][k]*dp[k][j]);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            if(dp[i][i]>1.0)
            {
                flag=1;
                break;
            }
        }
        if(flag)printf("Case %d: Yes\n",num);
        else printf("Case %d: No\n",num);

        scanf("%d",&n);
    }

}
