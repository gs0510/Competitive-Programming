#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,hackos,cou;
    scanf("%d %d",&n,&hackos);
    int z=hackos,y=n;
    int arr[n];
    if(hackos > ((n)*(n+1))/2)
    {
        printf("-1\n");
    }
    else{
        cou=1;
        y=n;
        if(z <=n){printf("1\n");}
        else if(z > n){
                z = z-n;
                y--;
                arr[n]=1;
                while(z>0 & arr[y]!=1 && y>0)
                {
                    arr[y]=1;

                    if( z-y >=0){z = z-y;cou++;}
                    y--;
                }
        }
        printf("%d\n",cou);
    }
}
