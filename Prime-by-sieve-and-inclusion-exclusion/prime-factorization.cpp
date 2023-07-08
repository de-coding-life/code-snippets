#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int spf;
   cin>>spf;
   int c[spf-1];
   for (int j=0;j<spf-1;j++)
   c[j]=j+2;
   for (int j=2;j<=spf;j++)
   {
      if (c[j-2]==j)
      {
         for(int k=j*j;k<=spf;k+=j)
         {
         if (c[k-2]==k)
         c[k-2]=j;
         }
      }
   }
   while (spf!=1)
   {
      cout<<c[spf-2];
      spf/=c[spf-2];
      if (spf!=1)
      cout<<" * ";
   }
   return 0;
}