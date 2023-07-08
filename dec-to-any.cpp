#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main()
{
   int a,temp=0,z=1,aa;
   cin>>a;
   aa=a;
   while (a>0)
   {
      temp+=(a%8)*z;
      a=a/8;
      z*=10;
   }
   cout<<endl<<temp<<" when base is 8"<<endl;
   a=aa;
   temp=0;
   z=1;
   while (a>0)
   {
      temp+=(a%2)*z;
      a=a/2;
      z*=10;
   }
   cout<<temp<<" when base is 2";
   string str;
   a=aa;
   while (a>0)
   {
      if ((a%16)<10)
      {
         str=to_string(a%16)+str;
      }
      else
      {
         str=char(55+a%16)+str;
      }
      a=a/16;
   }
   cout<<endl<<str<<" when base is 16";
   return 0;
}