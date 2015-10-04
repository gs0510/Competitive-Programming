#include<stdio.h>
#include<queue>
#include<string.h>
#include<algorithm>
using namespace std;
struct dat{
        int p,dis;
        bool operator <(const dat &b) const {return dis > b.dis;}
};
priority_queue<dat>q;
int ans[6000][2] , t[6000];
int li[100000][3],deg[6000],*e[6000],*c[6000],m,n;
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
    int i;
    for(memset(deg,0,sizeof(deg)) , i=0;i<m;i++)
    {
        scanf("%d %d %d",&li[i][0],&li[i][1],&li[i][2]);
        li[i][0]--;li[i][1]--; deg[li[i][0]]++; deg[li[i][1]]++;
    }
    for( i=0;i<n;e[i] = new(int[deg[i]]),c[i] = new(int[deg[i]]),deg[i]=0,i++);
    for( i=0;i<m;i++)
    {
        e[li[i][0]][deg[li[i][0]]]=li[i][1];
        c[li[i][0]][deg[li[i][0]]]=li[i][2];
        deg[li[i][0]]++;
        e[li[i][1]][deg[li[i][1]]]=li[i][0];
        c[li[i][1]][deg[li[i][1]]]=li[i][2];
        deg[li[i][1]]++;
    }
    struct dat dat2;
    dat2.p=0;dat2.dis=0;
    q.push(dat2);
    int p,d;
    for(memset(t,0,sizeof(t));!q.empty();q.pop())
    {
        p = q.top().p;
        d=q.top().dis;
        if(t[p]<2)
        {
            ans[p][t[p]]=d; t[p]++;
            for(i=0;i<deg[p];i++)
            {
                if(t[e[p][i]]<2)
                {
                    struct dat dat1 ;
                    dat1.p= e[p][i]; dat1.dis = d + c[p][i];
                    q.push(dat1);
                }
            }
        }
    }
    printf("%d\n",ans[n-1][1]);
    }
}
