#include<bits/stdc++.h>
using namespace std;
int pth(int n,int** mz,int c1,int c2,int** an)
   {
   if (c1>=n or c2>=n)
   return 0;
   else if (c1==n-1 and c2==n-1)
   return 1;
   if (mz[c1][c2+1]==1 and pth(n,mz,c1,c2+1,an)==1)
      {c2+=1;
      an[c1][c2]=1;
      return 1;}
   else if (mz[c1+1][c2]==1 and pth(n,mz,c1+1,c2,an)==1)
      {c1+=1;
      an[c1][c2]=1;
      return 1;}
   return 0;
   }

int main()
{
   int n;
   cin>>n;
   int** q=new int * [n];
   for (int i=0;i<n;i++)
   {
   q[i]=new int[n];
   for (int j=0;j<n;j++)
   cin>>q[i][j];
   }
   int** p=new int * [n];
   for (int i=0;i<n;i++)
   {
   p[i]=new int[n];
   for (int j=0;j<n;j++)
   p[i][j]=0;
   }
   pth(n,q,0,0,p);
   p[0][0]=1;
   cout<<endl;
   for (int i=0;i<n;i++)
   {
   for (int j=0;j<n;j++)
   cout<<p[i][j]<<" ";
   cout<<endl;
   }
   return 0;
}
// 1 1 1 1 1
// 1 1 1 1 1
// 0 1 0 1 0
// 1 1 0 1 1
// 1 1 1 0 1
