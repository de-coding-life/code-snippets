#include<bits/stdc++.h>
using namespace std;
int kadanes(int array[],int n)
{
   int bs=0,cs=0;
   for (int i=0;i<n;i++)
   {
      if (cs>=0)
      {
      cs+=array[i];
      bs=max(bs,cs);
      }
      else
      {
         cs=0;
         cs+=array[i];
         bs=max(bs,cs);
      }
   }
   bs=max(bs,cs);
   return bs;
}
int sm(int array[],int n)
{
   int s=0;
   for (int i=0;i<n;i++)
   {
      s+=array[i];
   }
   return s;
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for (int i=0;i<n;i++)
   {
      cin>>a[i];
   }
   int k1=kadanes(a,n);
   //now we will find minimum subarray and - it from sum of subarray to find max circular subarray
   int sum=sm(a,n);
   for (int i=0;i<n;i++)
   {
      a[i]=-a[i];
   }
   int k2=kadanes(a,n);
   cout<<max(k1,sum-(-k2));
   return 0;
}
//7 4 -4 6 -6 10 -11 12