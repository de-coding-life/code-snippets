#include<bits/stdc++.h>
using namespace std;
int main()
{
   int s=0,e=0,mx=0,st=-1,et=0,n=0,nu;
   cin>>nu;
   cin.ignore();
   char a[nu+1];
   cin.getline(a,nu+1);
   cin.ignore();
   while (n<nu)
   {
      if (a[n] == ' ')
      {
         et=n;
         if ((et-st)>mx)
         {
            s=st;
            e=et;
            mx=et-st;
         }
         st=et;
      }
      n++;
   }
   et=n;
   if (et-st>mx)
   {
      s=st;
      e=et;
      mx=et-st;
      st=et;
   }
   for (int i=s+1;i<e;i++)
   {
      cout<<a[i];
   }
   return 0;
}