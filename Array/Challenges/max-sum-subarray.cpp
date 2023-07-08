#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,mx=INT_MIN;
   cin>>n;
   int a[n];
   for (int i=0;i<n;i++)
   {
      cin>>a[i];
   }
   for (int i=0;i<n;i++)
   {
      for (int j=i;j<n;j++)
      {  
         int s=0;
         for (int k=i;k<=j;k++)
         {
            s+=a[k];
         }
         mx=max(mx,s);
      }
      
   }
   cout<<mx;
   return 0;
}