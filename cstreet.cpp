#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int visited[1001];

class CompareDist
{
        public:
            bool operator()(pair<int,int>lhs, const pair<int,int> rhs){
        return lhs.second > rhs.second;}
};

int main() {

   priority_queue<pair<int,int>,vector<pair<int,int> >,CompareDist> pQ;
    int t,price,m,n,a,b,wt,source;
    scanf("%d",&t);
    while(t--)
    {
        int sum=0;
        scanf("%d",&price);
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&a,&b,&wt);
            arr[a][b] = wt;
            arr[b][a] = wt;
        }
        source=1;
        do
        {
            //printf("hello\n");
            //printf("%d source",source);
            visited[source]=1;
            for(int i=1;i<=n;i++)
            {
                if(arr[source][i]!=0 && visited[i]==0)
                {
                    pQ.push(make_pair(i,arr[source][i]));
                }
            }
            while(1)
            {
                source=pQ.top().first;
                //printf("%d ---------- SOURCE",source);
                if(visited[source]==1)pQ.pop();
                else if(visited[source]==0){
                    sum +=pQ.top().second;
                    pQ.pop();
                    break;
                }
                if(pQ.empty())break;
            }
        }while(!pQ.empty());
        printf("%d",sum*price);
    }
    return 0;
}
