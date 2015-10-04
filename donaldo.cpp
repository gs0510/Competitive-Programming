#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    queue<int> q;
    int t,n,i,minsec;
    scanf("%d",&t);
    for(int j = 0;j<t;j++)
    {
        int gf=0;
        scanf("%d",&n);
        int arr[n];
        int hh,mm,ss;
        char a;
        for(int i=0;i<n;i++)
        {
            scanf("%d%c%d%c%d",&hh,&a,&mm,&a,&ss);
            arr[i]= hh*3600+ mm*60+ss;
        }
        if(n==0)printf("Case %d: 0\n",j);

        scanf("%d",minsec);
        sort(arr,arr+n);
        q.push(arr[0]);
        int i=0;
        while(i < n)
        {
            while(i<n && arr[i]-q.front() < minsec)
            {
               i++;
                q.push(arr[i]);
            }
            int len = q.size()-1;
            gf =  max(gf,len);
             int temp =  q.front();
             q.pop();
             while(!q.empty() && q.front()==temp)
             {
                q.pop();
             }
        }
        printf("Case %d: %d",j,gf);
    }
return 0;

}
