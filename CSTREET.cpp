#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u,v;
    int wt;
};

Edge E[300000];
int V[1005];
int R[1005];

int Edge_cmp(const void *a,const void *b)
{
    const Edge* A = (const Edge *)a;
    const Edge* B = (const Edge *)b;
    return (A->wt < B->wt)? -1:(A->wt > B->wt)? 1 : 0;
}


int findSet(int v)
{
    if(V[v]!=v)
    {
        V[v]=findSet(V[v]);
    }
    return V[v];
}

void linkSet(int u,int v)
{
    if(R[u]>R[v])
    {
        V[v]=u;
    }
    else {
        V[u]=v;
    }
    if(R[u]==R[v])
    {
        R[v]++;
    }

}

int main()
{
    int t,p,m,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&p,&n,&m);
        for(int i=0;i<m;i++)
        {scanf("%d %d %d",&E[i].u,&E[i].v,&E[i].wt);}

        qsort(E,m,sizeof(Edge),Edge_cmp);
         for(int i=0;i<n;i++){
            V[i] = i;
            R[i] = 0;
        }
        int c=0;
        int l=1;
        int i=0;
        while(l<n)
        {
            int U= findSet(E[i].u);
            int V= findSet(E[i].v);
            if(U!=V)
            {
                c += E[i].wt;
                linkSet(U,V);
                l++;
            }
            i++;
        }
        printf("%d\n",p*c);
    }

}
