#include<bits/stdc++.h>
using namespace std;
int chck(int a[],int n,int k)
{  if (n<=k)
   return 1;
   else if (a[k]>=a[k-1])
   return chck(a,n,++k);
   else
   return 0;
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for (int i=0;i<n;i++)
   cin>>a[i];
   cout<<chck(a,n,1);
}