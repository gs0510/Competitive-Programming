#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    pair<long,int> a[MAX];
    pair<long,int> b[MAX];
    int n,i;
    int ncase=0;
    while(cin>>n)
    {
        ncase++;
        long long g;
        for(i=0;i<n;i++)
        {
            cin>>g;
            a[i] = make_pair(g,i);
        }
        for(i=0;i<n;i++)
        {
            cin>>g;
            b[i] = make_pair(g,i);
        }
        sort(a,a+n);
        sort(b,b+n);
        for(i=n-1;i>=0;i--)
        {
            if(b[i].second!=a[i].second)break;
        }
        if(i!=-1) cout <<"Case "<<ncase<<": "<<n-i<<endl;
        else cout <<"Case "<<ncase<<": "<<"agree"<<endl;
    }
    return 0;
}
