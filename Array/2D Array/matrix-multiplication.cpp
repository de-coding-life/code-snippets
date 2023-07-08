#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,m,x,y;
   cin>>n>>m;
   int m1[n][m];
   for (int i=0;i<n;i++)
   {
      for (int j=0;j<m;j++)
      {
         cin>>m1[i][j];
      }
   }
   cin>>x>>y;
   int m2[x][y];
   for (int i=0;i<x;i++)
   {
      for (int j=0;j<y;j++)
      {
         cin>>m2[i][j];
      }
   }
   if (m!=x)
   {
      cout<<-1;
      return 0;
   }
   int ans[n][y];
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<y;j++)
      {
         int sm=0;
         for (int k=0;k<m;k++)
         {
            sm+=(m1[i][k]*m2[k][j]);
         }
         ans[i][j]=sm;
      }
   }
   for (int i=0;i<n;i++)
   {
      for (int j=0;j<y;j++)
      {
         cout<<ans[i][j]<<" ";
      }
      cout<<"\n";
   }
   return 0;
}