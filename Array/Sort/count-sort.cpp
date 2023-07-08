#include<bits/stdc++.h>
using namespace std;
void count_sort(int a[],int n)
{  
   int mx=a[0];
   for (int i=0;i<n;i++)
   {
      if (a[i]>mx)
      mx=a[i];
   }
   int cn[mx+1]={0};
   for (int i=0;i<n;i++)
   cn[a[i]]+=1;
   for (int i=1;i<=mx;i++)
   cn[i]+=cn[i-1];
   int ans[n]={0};
   for (int i=0;i<n;i++)
   ans[--cn[a[i]]]=a[i];
   for (int i=0;i<n;i++)
   a[i]=ans[i];
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for (int i=0;i<n;i++)
   cin>>a[i];
   count_sort(a,n);
   for (int i=0;i<n;i++)
   cout<<a[i]<<" ";
   return 0;
}