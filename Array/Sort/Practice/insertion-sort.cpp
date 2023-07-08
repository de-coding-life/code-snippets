#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int arra[n];
   for (int i=0;i<n;i++)
   {
      cin>>arra[i];
   }
   for (int i=0;i<n;i++)
   {
      for(int j=i;j>0;j--)
      {
         if (arra[j-1]>arra[j])
         {
            int temp=arra[j];
            arra[j]=arra[j-1];
            arra[j-1]=temp;
         }
      }
   }
   for (int i=0;i<n;i++)
   {
      cout<<arra[i]<<" ";
   }
   return 0;
}