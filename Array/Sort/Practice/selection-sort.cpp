#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int l1[n];
   for (int i=0;i<n;i++)
   {
      cin>>l1[i];
   }
   for (int i=0;i<n;i++)
   {
      int temp=INT_MAX;
      for(int j=i;j<n;j++)
      {
         if (l1[j]<temp)
         {
            temp=l1[j];
            l1[j]=l1[i];
            l1[i]=temp;
         }
      }
   }
   for (int i=0;i<n;i++)
   {
      cout<<l1[i]<<" ";
   }
   return 0;
}