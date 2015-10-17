#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int MAX = 501;
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int ncase=0,n,co,T,a;
    int task[MAX];
    while(cin>>n)
    {
        ncase++;
        cin>>T;
        int sum=0;co=0;
        int flag=1;
        for(int i=0;i<n;i++)
        {
            cin>>task[i];
        }
        co=0;
        for(int i=0;i<n;i++)
        {
            if(task[i]<=T)co++;
            T-=task[i];
            if(T<=0)break;
        }
        cout<<"Case "<<ncase<<": "<<co<<endl;
    }
    return 0;
}
