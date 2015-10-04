#include<bits/stdc++.h>
using namespace std;
#define INF
int visited[100001];
int dist[100001];

struct compare
{
  bool operator()(const int& l, const int& r)
  {
      return dist[l] > dist[r];
  }
};

int main()
{
    int t,a,b,wt,vertex,edges,source,dest;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&vertex,&edges);
        int arr[vertex+1][vertex+1];
        priority_queue<int,vector<int>,compare> pq;
        for(int i=1;i<=vertex;i++)
        {
            dist[i]=999999;
            visited[i]=0;
        }
        for(int i=0;i<=vertex;i++)
        {
            for(int j=0;j<=vertex;j++)
            {
                arr[i][j]=999999;
            }
        }
        for(int i=1;i<=edges;i++)
        {
            scanf("%d %d %d",&a,&b,&wt);
            arr[a][b]=wt;
        }
        scanf("%d %d",&source,&dest);
        pq.push(source);
        dist[source]=0;
        visited[source]=1;
        while(!pq.empty() && visited[dest]!=1)
        {
            int current = pq.top();
            pq.pop();
            visited[current]=1;
            for(int i=1;i<=vertex;i++)
            {
                if(visited[i]!=1 && arr[current][i]!=999999)
                {
                    dist[i] = min(dist[i],dist[current]+arr[current][i]);
                    pq.push(i);
                }
            }
        }
        if(visited[dest]==1)printf("%d\n",dist[dest]);
        else printf("NO\n");
    }
}
