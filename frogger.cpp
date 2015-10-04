#include<stdio.h>
#include<algorithm>
#include<vector>
#include<math.h>
#define INF (1<<20)
#define MAX 201
#define GRAY 0
#define BLACK 1

using namespace std;
bool visited[MAX];
double dist[MAX];
int x[MAX],y[MAX];
int color[MAX]={GRAY};

double calculate(int i,int j)
{
    return sqrt((double)(((x[i]-x[j])*(x[i]-x[j]))+((y[i]-y[j])*(y[i]-y[j]))));
}

int main()
{
    int n,scenario=0;
    scanf("%d",&n);
    while(n!=0)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&x[i],&y[i]);
            color[i]=GRAY;
        }
        dist[0]=0;
        color[0]=BLACK;
        for(int i=1;i<n;i++)
        {
            dist[i] = calculate(i,0);
        }
        int i,j;
        while(color[1]==GRAY)
        {
            for(i=1;color[i]!=GRAY;i++);
            for(j=i+1;j<n;j++)
            {
                if(color[j]==GRAY && dist[j]<dist[i]) i=j;
            }

            color[i]=BLACK;

            for(j=0;j<n;j++)
            {
                if(color[j]==GRAY)
                {
                    dist[j]=min(dist[j],max(dist[i],calculate(i,j)));
                }
            }
        }
        printf("Scenario #%d\n",++scenario);
        printf("Frog Distance = %.3f\n\n",dist[1]);
        scanf("%d",&n);
    }
    return 0;
}
