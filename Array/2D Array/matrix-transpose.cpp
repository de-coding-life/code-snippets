#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,m;
   cin>>n>>m;
   int m1[n][m];
   for (int i=0;i<n;i++)
   {
      for (int j=0;j<m;j++)
      {
         cin>>m1[i][j];
      }
   }
   for(int i=0;i<n;i++)
   {
      for(int j=0;j<i;j++)
      {
         swap(m1[i][j],m1[j][i]);
      }
   }
   for (int i=0;i<n;i++)
   {
      for (int j=0;j<n;j++)
      {
         cout<<m1[i][j]<<" ";
      }
      cout<<"\n";
   }
   return 0;
}