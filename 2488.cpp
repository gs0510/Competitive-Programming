#include<stack>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<queue>
#include<utility>
#include<stdlib.h>
using namespace std;
char map1[30][2];
int visited[30][30];
int p,q;
int jx[] ={-2,-2,-1,-1,1,1,2,2};
int jy[] ={-1,1,-2,2,-2,2,-1,1};

int dfs(int x,int y,int cnt)
{
    int i;
    if(cnt==p*q) return 1;

    for(i=0;i<8;i++)
    {
        int dx= x+ jx[i];
        int dy = y+ jy[i];
        if(dx>=1 && dx<=q && dy >=1 && dy<=p && !visited[dx][dy])
        {
            map1[cnt][0] = dx+'A'-1;
            map1[cnt][1] = dy+'0';
            visited[dx][dy]=1;
            if(dfs(dx,dy,cnt+1))
            {
                return 1;
            }
            visited[dx][dy]=0;
        }
    }
    return 0;
}

int main()
{
    int t,case1=0;
    scanf("%d",&t);
    while(t--)
    {
        case1++;
        memset(visited,0,sizeof visited);
        memset(map1,0,sizeof map1);
        scanf("%d %d",&p,&q);
        int i,j;
        visited[1][1]=1;
        map1[0][0]='A';
        map1[0][1]='1';
        printf("Scenario #%d: \n",case1);
        if(dfs(1,1,1)){
            for(i=0;i<p*q;i++)
            {
                printf("%c%c",map1[i][0],map1[i][1]);
            }
            printf("\n\n");
        }
        else{printf("impossible\n\n");}

    }

}
