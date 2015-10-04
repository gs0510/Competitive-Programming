#include<stdio.h>
#include<string.h>
int arr[10001];
int main()
{
    int t,i,x,flag,y,n1,n2,a,n,b;
    scanf("%d",&t);
    while(t--)
    {
        flag=0;
        scanf("%d",&n);
        memset(arr,0,n*sizeof(int));
        for(i=0;i<n-1;i++)
        {
            scanf("%d %d",&a,&b);
            arr[b]=a;
        }
        scanf("%d %d",&n1,&n2);
        if(arr[n1]==n2){
            printf("%d\n",n2);
        }
        else if(arr[n2]==n1)
        {
            printf("%d\n",n1);
        }
        else{
            x=n1; y=n2;
            while(1)
            {
                y=n2;
                while(arr[y]!=y && arr[y]!=x)
                {
                    y=arr[y];
                }
                if(arr[y]==x)
                {
                    printf("%d\n",x);
                    break;
                }
                x=arr[x];

            }
        }
    }
}
