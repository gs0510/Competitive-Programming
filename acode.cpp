#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<iostream>
#define MAX 1000
using namespace std;
int main()
{
    string arr;
    cin >> arr;
    while(arr[0]!='0')
    {
        int len = arr.length();
        long long dp[5001];
        dp[0]=1;dp[1]=1;
        for(int i=2;i<=len;i++)
        {
            dp[i]=0;
            int c1 = (int)arr[i-2]-'0' ;
            int c2 =(int)arr[i-1]-'0';
            if(c1==1 || (c1== 2 && c2<=6))
            {
                dp[i]+=dp[i-2];
            }
            if(c2!=0) {dp[i]+= dp[i-1];}
        }
        printf("%lld\n",dp[len]);
        cin >> arr;
    }
    return 0;
}
