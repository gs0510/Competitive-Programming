#include<bits/stdc++.h>
using namespace std;
priority_queue<int, std::vector<int>, std::greater<int> >  chef;
int last=0;


int main()
{
    int t,n,cooks,r,prata,roti,time=0,val;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&prata);
        scanf("%d",&cooks);
        for(int i=0;i<cooks;i++)
        {
            scanf("%d",&r);
            chef.push(r);
        }
        roti=0;
        while(roti < prata)
        {
            val= chef.top();
            printf("VAL %d\n",val);
            chef.pop();
            time +=val;
            chef.push(2*val);
            printf("%d ROTI %d CEIL\n",roti,ceil(time*1.0/val));
            roti = roti + ceil(time*1.0/val);
            printf("%d ROTI %d CEIL %f\n",roti,(int)ceil(time*1.0/val),time*1.0/val);
        }
        printf("%d\n",time);
    }
    return 0;
}
