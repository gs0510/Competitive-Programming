#include <bits/stdc++.h>
using namespace std;

struct node{
	long left;
	long right;
	long best;
	long sum;
};

int arr[50004];
node tree[200004];

node makeNode(long sum,long best,long left,long right)
{
	node temp;
	temp.sum = sum;
	temp.best = best;
	temp.left = left;
	temp.right = right;
	return temp;

}

node combine(node l,node r)
{
	long left = l.left;
	if(l.sum + r.left > left) left = l.sum +r.left;
	long right = r.right;
	if(r.sum + l.right > right) right = r.sum + l.right;
	long best = max(r.left + l.right , max(l.best,r.best));
	return makeNode(r.sum+l.sum,best,left,right);
}

node build(int from,int to,int index)
{
	if(from==to){
		return tree[index]=makeNode(arr[from],arr[from],arr[from],arr[from]);
	}
	int mid = (from+to)/2;
	node l = build(from,mid,index<<1);
	node r = build(mid+1,to,(index<<1 )+1);
	tree[index] = combine(l,r);
	return tree[index];
}

node answer(int index,int from,int to,int a,int b)
{
	if(from==a && to==b)
	{
		return tree[index];
	}
	int mid = (from+to)/2;
	if(b <=mid)
	{
		return answer(index<<1,from,mid,a,b);
	}
	if(a>mid)
	{
		return answer((index<<1) +1,mid+1,to,a,b);
	}
	node l = answer(index<<1, from,mid,a,mid);
	node r = answer((index<<1)+1,mid+1,to,mid+1,b);
	return combine(l,r);
}

int main(int argc, char const *argv[])
{
	/* code */
	int n,a,b;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	build(1,n,1);
	int t;
	cin >>t;
	while(t--)
	{
		scanf("%d %d",&a,&b);
		printf("%ld\n",answer(1,1,n,a,b).best);
	}
	return 0;
}