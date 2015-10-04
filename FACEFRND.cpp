#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,fr,fof,i;
    scanf("%d",&n);
    set<int> friends;
    for(i=0;i<n;i++)
    {
        scanf("%d",&fr);
        friends.insert(fr);
        scanf("%d",&fof);
        while(fof--)
        {
            scanf("%d",&fr);
            friends.insert(fr);
        }
    }
    printf("%d\n",(int)friends.size()-n);
    return 0;
}
