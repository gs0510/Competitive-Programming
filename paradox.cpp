#include<stdio.h>
#include<bits/stdc++.h>
#include<string>
using namespace std;
stack<int> st;
int n;
int visited[101];
int state[101];
int fal=0;
int arr[101][101];


bool dfs(int source)
{
    if(visited[source]==1){
        if(fal%2==0){return true;}
        else return false;
    }
    visited[source]=1;

    for(int i=1;i<=n;i++)
    {
        if(arr[source][i]==1||arr[source][i]==-1)
        {
            if(source==i && arr[source][i]==-1){return false;}
            else if(source==i && arr[source][i]==1){return true;}
            else {
                if(arr[source][i]==-1){
                    fal++;
                }
                st.push(i);
            }
        }
    }
    if(!st.empty())
    {
        int a=st.top();
        st.pop();
        return dfs(a);
    }
}


int main()
{
    int a,b;
    char val[6];
    int flag=0;
    scanf("%d",&n);
    while(n!=0)
    {
        while(!st.empty())st.pop();
        flag=0;
        for(int i=1;i<=n;i++)
        {
            visited[i]=0;
            state[i]=0;
            for(int j=1;j<=n;j++)
            {
                arr[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++)
        {
            scanf("%d %s",&a,val);
            if(strcmp(val,"true")==0){arr[i][a]=1;}
            if(strcmp(val,"false")==0)arr[i][a]=-1;
        }
        for(int i=1;i<=n;i++)
        {
            if(visited[i]!=1)
            {
                fal=0;
                bool la=dfs(i);
                if(!la){flag=1;break;}
            }
        }
        if(flag==1){printf("PARADOX\n");}
        else printf("NOT PARADOX\n");
        scanf("%d",&n);
    }
}

