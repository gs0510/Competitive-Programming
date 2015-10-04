#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
        int no,len,count=0,sum=0;
        scanf("%d %d",&no,&len);
        int arr[len];
        for(int i=0;i<len;i++)
        {
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+len);
        int i=len-1;
        while(sum < no && i >=0)
        {
            sum+=arr[i];
            i--;
            count++;
        }
        if(sum < no )printf("Scenario #%d:\nimpossible\n",j);
        else{
            printf("Scenario #%d:\n%d\n",j,count);
        }
    }
    return 0;
}
