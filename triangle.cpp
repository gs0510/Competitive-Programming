#include<stdio.h>
#include<algorithm>
using namespace std;
int a[100][100],f[2][100];
int main()
{
    int n,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<=i;j++)
            {
                scanf("%d",&a[i][j]);
            }
        }
        f[0][0] =a[0][0];
        for(i=1;i<n;i++)
        {
            f[i%2][0]=a[i][0] + f[(i-1)%2][0];
            f[i%2][i]=a[i][i] + f[(i-1)%2][i-1];
            for(j=1;j<=i-1;j++)
            {
                f[i%2][j]=a[i][j]+ max(f[(i-1)%2][j-1],f[(i-1)%2][j]);
            }
        }
        int maxi=0;
        for(i=0;i<n;i++)
        {
            if(f[(n-1)%2][i] > maxi)
            {
                maxi = f[(n-1)%2][i];
            }
        }
        printf("%d\n",maxi);
    }
    return 0;
}
