#include<bits/stdc++.h>
using namespace std;
int main()
{
    int cou=0,a,b,source;
    multimap<int,int>alist;
    scanf("%d %d",&a,&b);
    while(a!=-1 && b!=-1)
    {
        int flag=0;
        alist.clear();
        cou++;
        while(a!=0&&b!=0)
        {
            alist.insert(a,b);
            scanf("%d %d",&a,&b);
        }
        multimap<int,int>::iterator it;

        for(it = alist.begin();it!=alist.end();++it)
        {

        }

        stack<int> st;
        source= vec.front().first;
        st.push(vec.front().second);
        vec.erase(vec.begin()+0);
        while(!vec.empty())
        {
             if(st.empty())
             {
                source=vec.at(0).first;st.push(vec.at(0).second);vec.erase(vec.begin()+0);
             }
             else{
                    source=st.top();
                    st.pop();
             }
             if(visited_first[source]==0)
             {
                visited_first[source]=1;
                for(int i=0;i<vec.size();i++)
                {
                    if(vec.at(i).first==source){st.push(vec.at(i).second);vec.erase(vec.begin()+i);}
                }
             }
             else{
                flag=1;
                break;
             }
        }
        if(flag==1){printf("Case %d is not a tree\n",cou);}
        else{
            printf("Case %d is a tree\n",cou);
        }
    }
}
