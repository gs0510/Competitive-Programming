#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int arr[100001];
long long sum[100001];
int main()
{
    ios::sync_with_stdio(false);
    int n,k,k1;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    for(int i=0;i<n;i++)
    {
        if(i>0)sum[i] = sum[i-1]+arr[i];
        else sum[0] = arr[0];
    }
    cin >> k;
    for(int j=0;j<k;j++)
    {
        cin >> k1;
        int sum1 = sum[(int)ceil((float)n/(k1+1))-1];
        cout << sum1 << endl;

    }
    return 0;
}
