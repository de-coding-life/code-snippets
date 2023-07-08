#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,m,k;
   cin>>n>>m>>k;
   int m1[n][m];
   for (int i=0;i<n;i++)
   {
      for (int j=0;j<m;j++)
      {
         cin>>m1[i][j];
      }
   }
   int x=0,y=m-1;
   while (x<n && y<m)
   {
      if (m1[x][y]>k)
      {
         y--;
      }
      else if (m1[x][y]<k)
      {
         x++;
      }
      else
      {
         cout<<"true "<<x<<" "<<y;
         return 0;
      }
   }
   cout<<"false";
   return 0;
}