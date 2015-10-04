#include<stdio.h>
#include<string.h>
int arr[100][100];
int kadane[100];
int n,i,j,l,r,maxsum,currentsum,max_so_far,max_ending_here=0;

int main()
{
    int n,i,j;
    scanf("%d",&n);
    //while(n!=0)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        maxsum=-9999;currentsum=0;
        for(l=0;l<n;l++)
        {
            memset(kadane,0,n*sizeof(int));
            for(r=l;r<n;r++)
            {
                max_so_far=0,max_ending_here=0;
                for(i=0;i<n;i++)
                {
                    kadane[i]+= arr[i][r];
                    max_ending_here += kadane[i];
                    if(max_so_far<max_ending_here ){
                        max_so_far = max_ending_here;
                    }
                    if(max_ending_here < 0) {max_ending_here=0;}
                }
                currentsum=max_so_far ;
                if(maxsum < currentsum)
                {
                    maxsum= currentsum;
                }
            }
        }
        printf("%d\n",maxsum);
        scanf("%d",&n);
    }
}
