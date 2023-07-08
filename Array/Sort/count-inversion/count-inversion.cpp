#include<bits/stdc++.h>
using namespace std;
int countinv(int a[],int n)
{  int c=0;
   for (int i=0;i<n;i++)
   {
      for (int j=i+1;j<n;j++)
      {
         if (a[j]<a[i])
         c++;
      }
   }
   return c;
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for (int i=0;i<n;i++)
   cin>>a[i];
   cout<<countinv(a,n);
   return 0;
}