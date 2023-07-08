#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,k;
   cin>>n>>k;
   int a[n];
   for (int i=0;i<n;i++)
   cin>>a[i];
   queue<int> q;
   int kc=0;
   int ans=-1;
   for (int i=0;i<n;i++)
   {
      if (kc<k or a[i]==1)
      {
         q.push(i);
         kc+=abs(a[i]-1);
      }
      else
      {
         while (a[q.front()]==1)
         q.pop();
         q.pop();
         q.push(i);
      }
      ans=max(ans,int(q.size()));
   }
   cout<<ans;
   return 0;
}