#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,m;
   cin>>n>>m;
   int array[n][m];
   for (int i=0;i<n;i++)
   {
      for (int j=0;j<m;j++)
      {
         cin>>array[i][j];
      }
   }
   int rs=0,cs=0,ce=m-1,re=n-1;
   while (rs<=re and cs<=ce)
   {  
      for(int j=cs;j<=ce;j++)
      {
         cout<<array[rs][j]<<" ";
      }
      for(int j=rs+1;j<=re;j++)
      {
         cout<<array[j][ce]<<" ";
      }
      for(int j=ce-1;j>=cs;j--)
      {
         cout<<array[re][j]<<" ";
      }
      for(int j=re-1;j>rs;j--)
      {
         cout<<array[j][cs]<<" ";
      }
      rs++;
      cs++;
      ce--;
      re--;
   }
   return 0;
}