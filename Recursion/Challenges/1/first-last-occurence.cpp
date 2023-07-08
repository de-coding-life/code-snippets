#include<bits/stdc++.h>
using namespace std;
void chck(int a[],int n,int k,int s,int t)
{
   if (a[s]==k)
   {
      cout<<s<<" first "<<endl;
      s=n;
   }
   if (a[t]==k)
   {
      cout<<t<<" last "<<endl;
      t=n;
   }
   if (s==n && t==n)
   return;
   else if (s==n)
   chck(a,n,k,n,--t);
   else if (t==n)
   chck(a,n,k,++s,n);
   else
   chck(a,n,k,++s,--t);
}
int main()
{
   int n,k;
   cin>>n>>k;
   int arr[n+1];
   for (int i=0;i<n;i++)
   {
      cin>>arr[i];
   }
   arr[n]=k+1;
   chck(arr,n,k,0,n-1);
   return 0;
}