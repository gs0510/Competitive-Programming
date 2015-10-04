#include<bits/stdc++.h>
using namespace std;
//vector<vector<int> >
void generateMatrix(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
       vector<vector <int> >V(A, vector<int> (A,0));
       //printf("bdjkbakjcn %d",V.size());
        int i,k=0,l=0,a=1,n=A,m=A,j;
        while(k<m && l<n )
        {
            for(i=l;i<n;i++)
            {
                V[k][i]= a;
                a++;
             //   printf("%d %d here\t",i,V[k][i]);
            }
            k++;
            //printf("\n\n");

            for(i=k;i<m;i++)
            {
                V[i][n-1] =a;
                a++;
              //  printf("%d %d here\t",i,V[i][n-1]);
            }
            n--;

            if(k<m)
            {
                for(i = n-1;i>=l;i--)
                {
                    V[m-1][i] =a;
                    a++;
                //    printf("%d %d here\t",i,V[m-1][i]);
                }
                m--;
            }
            //printf("\n\n");
            if(l<n)
            {
                for(i=m-1;i>=k;i--)
                {
                    V[i][l] = a++;
                    a;
                  //  printf("%d %d here\t",i,V[i][l]);
                }
                l++;
              //  printf("\n\n");
            }
        }
    printf("afterwards \n");
    for(i=0;i<A;i++)
    {
        for(j=0;j<A;j++)
        {
            printf("%d\t",V[i][j]);

        }

        printf("\n");
    }
   // return V;
}

int main()
{
    int A;
    scanf("%d",&A);
    vector< vector<int> >v (A,vector<int>(A,0));
    generateMatrix(A);
}
