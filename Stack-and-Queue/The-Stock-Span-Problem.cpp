#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int a[n];
   int ans[n]={0};
   ans[0]=1;
   for (int i=0;i<n;i++)
   cin>>a[i];
   for (int i=1;i<n;i++)
   {
   if (a[i-1]<=a[i])
   {
      ans[i]+=(ans[i-1]+1);
      int j=i-ans[i-1]-1;
      while (j>=0 and a[j]<=a[i])
      {
         ans[i]+=ans[j];
         j-=ans[j];
      }
   }
   else
   ans[i]=1;
   }
   for (int i=0;i<n;i++)
   cout<<ans[i]<<" ";
   return 0;
}