#include<stdio.h>
#include<algorithm>
using namespace std;
int arr[101][101];
int main(){
    int N,b,wt,n,min_time,m,share;
    while(1)
    {
        scanf("%d",&N);
        if(N==0)break;
        for(int i=1;i<=N;i++) fill(arr[i],arr[i]+N,(1<<20));
        for(int i=1;i<N;i++) {arr[i][i]=0;arr[i][N]=(1<<20);arr[N][i]=(1<<20);}

        for(int i=1;i<=N;i++)
        {
            scanf("%d",&n);
            for(int j=1;j<=n;j++)
            {
                scanf("%d %d",&b,&wt);
                arr[i][b]=wt;
            }
        }
        for(int k=1;k<=N;k++)
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++)
                {
                    arr[i][j]= min(arr[i][j],arr[i][k]+arr[k][j]);
                }

        min_time =(1<<20);

        for(int i=1;i<=N;i++)
        {
            m=-1;
            for(int j=1;j<=N;j++)
            {
                m = max(m,arr[i][j]);
            }
            if(m<min_time)
            {
                share= i;
                min_time = m;
            }
        }
        printf("%d %d\n",share,min_time);
    }

}
