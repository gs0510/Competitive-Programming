#include<stdio.h>
#include<string>
#include<cstring>
#include<map>
#include<iostream>
using namespace std;
map <string,int> mp;
int main()
{
        std::ios::sync_with_stdio(false);
        int total=0;
        string name;
        while((getline(cin,name)) )
        {
            if(name=="")break;
            total++;
            if(mp.find(name)!=mp.end())
            {
                mp[name]++;
            }
            else{
                mp[name]=1;
            }
        }
     //   map<string, int>::
       map<string,int>::iterator it;
        it = mp.begin();
       while ( it != mp.end())
        {
               //printf << ;
               printf("%s %.4f\n",it->first.c_str(),100*(it->second)/(total*1.0));
               ++it;
        }
}
