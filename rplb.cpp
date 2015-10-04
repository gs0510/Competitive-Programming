#include<bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int main()
{
    int t;
    scanf("%d",&t);
    for(int scene=1;scene<=t;scene++)
    {
        int bush,berry,no_berr;
        scanf("%d %d",&bush,&berry);
        for(int i=0;i<=bush;i++)
        {
          for(int j=0;j<=berry;j++)
        {
                arr[i][j]=0;
        }}
        scanf("%d",&no_berr);
        for(int j=0;j<=berry;j++)
        {
            if(j>=no_berr){arr[1][j]=no_berr;}
        }
        for(int i=2;i<=bush;i++)
        {
            scanf("%d",&no_berr);
            int val = no_berr;
            for(int j=0;j<=berry;j++)
            {
                if(j < no_berr) {arr[i][j]=arr[i-2][j];}
                else{
                    arr[i][j] = max(arr[i-2][j],arr[i-2][j-no_berr]+no_berr);
                }
            }

        }

       printf("Scenario #%d: %d\n",scene,arr[bush][berry]);
    }
}
