#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define MAX 10000000
using namespace std;
int count1[MAX+1];
int n;
long long calc(int n)
{
   if(n<2) return n;
   if(count1[n]>0) return count1[n];
   count1[n] = n + calc(n/2) + calc(n- n/2-1);
   return count1[n];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int c=0;
    while(cin>>n)
    {
        for(int i=0;i<=n;i++)
        {
            count1[i]=0;
        }
        cout <<"Case "<<++c<<": "<< calc(n) << endl;
    }
    return 0;
}