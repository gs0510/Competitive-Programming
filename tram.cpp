#include<stdio.h>
#include<algorithm>
#include <queue>
#include <vector>
using namespace std;
int arr[101][101];
int visited[101];
int dist[101];
struct compare
{
  bool operator()(const int& l, const int& r)
  {
      return dist[l] > dist[r];
  }
};
int main()
{
    int N,source,dest,n,b;

    while(scanf("%d%d%d",&N,&source,&dest)!=EOF)
    {
        priority_queue<int,vector<int>,compare> pq;
        for(int i=1;i<=N;i++) fill(arr[i],arr[i]+N,(1<<20));
        for(int i=1;i<N;i++) {arr[i][i]=0;arr[i][N]=(1<<20);arr[N][i]=(1<<20);}
        for(int i=1;i<=N;i++) dist[i]=(1<<20);
        for(int i=1;i<=N;i++) visited[i]=0;
        for(int i=1;i<=N;i++)
        {
            scanf("%d",&n);
            for(int j=0;j<n;j++)
            {
                scanf("%d",&b);
                if(j!=0)arr[i][b]=1;
                else arr[i][b]=0;
            }
        }

    pq.push(source);
    dist[source]=0;
    visited[source]=1;
    while(!pq.empty()&& visited[dest]==0)
    {
        int current = pq.top();
        pq.pop();
        visited[current]=1;
        for(int i=1;i<=N;i++)
            {
                if(visited[i]!=1 && arr[current][i]!=(1<<20))
                {
                    dist[i] = min(dist[i],dist[current]+arr[current][i]);
                    pq.push(i);
                }
            }
    }
    if(visited[dest]==1)printf("%d\n",dist[dest]);
    else printf("-1\n");
    }
    return 0;
}


