#include<bits/stdc++.h>
using namespace std;
int main()
{
   int t;
   cin>>t;
   for (int x=0;x<t;x++)
   {
      int n;
      cin>>n;
      int l1[n];
      for (int i=0;i<n;i++)
      {
         cin>>l1[i];
      }
      int rb=0,mx=INT_MIN;
      for (int i=0;i<n;i++)
      {
         if (mx<l1[i] and (i==n-1 or l1[i]>l1[i+1]))
         {
            rb+=1;
            mx=l1[i];
         }
      }
      cout<<"Case#"<<(x+1)<<": "<<rb;
   }
   return 0;
}