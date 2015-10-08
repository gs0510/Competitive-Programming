#include <stdio.h>
#include <string.h>

int p[1001],vis[1001];

int lca(int a,int b,int n)
{
	for(int i=0;i<=n;i++)
	{
        vis[i]=0;
	}
	vis[a]=1;
	while(p[a]!=a)
	{
			vis[a]=1;
			a = p[a];
	}
	vis[a]=1;
	while(vis[b]!=1)
	{
		b =p[b];
	}
	return b;
}

int main()
{
	int t,a,n,n1,b;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{

		scanf("%d",&n);
		for(int j=1;j<=n;j++)
		{
			p[j]=j;
		}
		for(int k=1;k<=n;k++)
		{
			scanf("%d",&n1);
			while(n1--)
			{
				scanf("%d",&a);
				p[a]=k;
			}
		}
		scanf("%d",&n1);
		printf("Case %d:\n",i );
		while(n1--)
		{
			scanf("%d %d",&a,&b);
			printf("%d\n",lca(a,b,n));
		}

	}

}
