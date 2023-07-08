#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,k;
   cin>>n>>k;
   int st=0,en=n-1;
   int a[n];
   for (int i=0;i<n;i++)
   {
      cin>>a[i];
   }
   for (int i=0;i<n;i++)
   {
      int sm=a[st]+a[en];
      if (k>sm)
      {
         st+=1;
      }
      else if (k<sm)
      {
         en-=1;
      }
      else
      {
         cout<<1;
         return 0;
      }
   }
   cout<<0;
   return 0;
}