#include<bits/stdc++.h>
#define MAX 100005
using namespace std;
vector<vector<int> > adj(100005);
int visited[MAX];
void dfs(int n,int u)
{
    if(visited[u]==1)return;
    visited[u]=1;
    for(vector<int>::iterator it=adj[u].begin();it!=adj[u].end();it++){
		if(!visited[*it])
		dfs(n,*it);
	}
}

int main()
{
    long long t,n,rel,a,b;
    scanf("%lld",&t);
    while(t--)
    {
        int connect=0;
        scanf("%lld",&n);

        scanf("%lld",&rel);
        memset(visited,0,sizeof visited);
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
        }
        for(int i=0;i<rel;i++)
        {
            scanf("%lld %lld",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

          {  for(int i=0;i<n;i++)
            {
                if(visited[i]==0)
                {
                    connect++;
                    dfs(n,i);
                }
            }
        }
        printf("%d\n",connect);
    }
    return 0;
}


