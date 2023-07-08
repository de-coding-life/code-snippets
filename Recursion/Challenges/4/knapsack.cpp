#include<bits/stdc++.h>
using namespace std;
int k(int wt[],int v[],int n,int w)
{  if (n==0 or w==0)
   return 0;
   if (w<0)
   return v[n];
   return max(k(wt,v,n-1,w),k(wt,v,n-1,w-wt[n-1])+v[n-1]);
}
int main()
{
   int n,w;
   cout<<"\nEnter Number of Items\n";
   cin>>n;
   cout<<"\nEnter Weight of Bag\n";
   cin>>w;
   int wt[n],v[n];
   for (int i=0 ; i<n ; i++)
   {  cout<<"\nEnter Weight of Item "<<i+1<<"\nKG ";
      cin>>wt[i];
      cout<<"\nEnter Amount of Item "<<i+1<<"\nRs. ";
      cin>>v[i];
   }
   cout<<"\nRs. "<<k(wt,v,n,w);
   return 0;
}