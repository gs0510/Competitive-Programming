#include<bits/stdc++.h>
using namespace std;
struct activity{
    int  start,finish;
};

activity ac[100000];
int sel[100000];

int finish_compare(const void * a, const void *b)
{
    const activity* A = (const activity*)a;
    const activity* B = (const activity*)b;
    return (A->finish < B->finish)?-1 : (A->finish > B->finish) ? 1: 0;
}

int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&ac[i].start,&ac[i].finish);
        }
        qsort(ac,n,sizeof(activity),finish_compare);
        sel[0]=1;
        int j=0,c=1;
        for(int i=1;i<n;i++)
        {
            if(ac[i].start >= ac[j].finish)
            {
                sel[i]=1;
                c++;
                j=i;
            }
        }
        printf("%d\n",c);
    }
}
