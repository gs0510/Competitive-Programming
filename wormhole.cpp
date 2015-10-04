#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<vector>
int arr[501][501];
int dist[501];
using namespace std;
int main()
{
        while(1)
        {int t,n,s,e,time,m,w;
       scanf("%d %d %d",&n,&m,&w);
        int flag=0,flag2=0;
        vector<pair<pair<int,int>,int> > edge;
        for(int i=0;i<=n;i++){dist[i]=(1<<20);}
        dist[1]=0;
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&s,&e,&time);
            edge.push_back(make_pair(make_pair(s,e),time));
        }
        for(int i=0;i<w;i++)
        {
            scanf("%d %d %d",&s,&e,&time);
           edge.push_back(make_pair(make_pair(e,s),-time));
        }
        for(int i=1;i<=n-1;i++)
        {
            for(int j=0;j<edge.size();j++)
            {
                if(dist[edge.at(j).first.second] > dist[edge.at(j).first.first]+edge.at(j).second)
                {
                        dist[edge.at(j).first.second] = dist[edge.at(j).first.first]+edge.at(j).second;
                }
            }
            for(int i1=0;i1<=n;i1++)
         {
            printf("%d\t",dist[i1]);
         }
         printf("\n");
        }
        for(int j=0;j<edge.size();j++)
            {
                if(dist[edge.at(j).first.second] > dist[edge.at(j).first.first]+edge.at(j).second)
                {
                   flag=1;
                   break;
                }
            }

        if(flag==0){
            if(dist[n]!=(1<<20))
            printf("%d\n",dist[n]);
            else{
                printf("-2\n");
            }
        }
        else if(flag==-1) printf("-1\n");}
}
