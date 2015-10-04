#include<bits/stdc++.h>
using namespace std;
int arr[2][2000001];
int main()
{
    int max_wt,no;
    scanf("%d %d",&max_wt,&no);

  for(int i=0;i<2;i++)
    {
        for(int j=0;j<=max_wt;j++)
        {
            arr[i][j]=0;
        }
    }
    int val,wt;
    for(int i=1;i<=no;i++)
    {

        scanf("%d %d",&val,&wt);
        for(int j=1;j<=max_wt;j++)
        {
            if(j<wt){ arr[i%2][j]=arr[(i+1)%2][j];}
            else{
                arr[i%2][j]=max(arr[(i+1)%2][j],arr[(i+1)%2][j-wt]+val);
            }
        }
    }
    printf("%d\n",arr[no%2][max_wt]);
}
