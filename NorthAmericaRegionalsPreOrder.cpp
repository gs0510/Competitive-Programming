#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int data;
    node* left;
    node* right;
};
typedef node *node_ptr;

void insert(node_ptr &root,int num)
{
    if(root==NULL)
    {
        root = new (node);
        root->data =num;
        root->left = NULL;
        root ->right=NULL;
        return;
    }
    if(num < root->data) insert(root->left,num);
    else if(num > root->data) insert(root->right,num);
    else return;
}

node_ptr build(int a[],int n)
{
    node_ptr root=NULL;
    for(int i=0;i<n;i++)
    {
        insert(root,a[i]);  
    }
    return root;
}

void preorder(int p[],node_ptr root,int &i)
{
    if(root != NULL)
    {
        p[i]=root->data;
        i++;
        preorder(p,root->left,i);
        preorder(p,root->right,i);  
    }
}

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int arr[1001];
    int p[1001];
    int ncase=0;
    int n;
    while(1)
    {
        ncase++;
        int flag=0,flag1=0;
        int n=0;
        while(cin>>arr[n])
        {
            if(arr[n]<0){flag=1;break;}
            n++;        
        }
        if(flag==0)break;
        node_ptr root = build(arr,n);
        int k=0;
        preorder(p,root,k);
        for(int j=0;j<n;j++)
        {
           if(arr[j]!=p[j]){flag1=1;break;}    
        }
        if(flag1) cout<<"Case "<<ncase <<": no"<<endl;
        else cout<<"Case "<<ncase <<": yes"<<endl;
    }
    return 0;
}