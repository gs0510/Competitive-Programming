#include<bits/stdc++.h>
using namespace std;
int arr[101][501];
int main()
{
    int party_max,no_party;
    scanf("%d %d",&party_max,&no_party);
    while(party_max!=0){
    for(int i=0;i<=party_max;i++)
    {
        for(int j=0;j<=no_party;j++)
         {arr[j][i]=0;}
    }
    int coun=0,a,b;

    for(int k=0;k<no_party;k++)
    {
        scanf("%d %d",&a,&b);
        coun++;
        for(int i=1;i<=party_max;i++)
        {
            if( i < a){arr[coun][i]=arr[coun-1][i];}
            else {
                arr[coun][i]=max(arr[coun-1][i],arr[coun-1][i-a]+b);
            }
        }
    }

    int last= arr[no_party][party_max];
    int j=party_max;
    while(arr[no_party][j]==last)
    {
        j--;
    }
    printf("%d %d\n",j+1,arr[no_party][j+1]);
    scanf("%d %d",&party_max,&no_party);
    }
}
