#include<iostream>
using namespace std;
int fact(int x)
{
   int f=1;
   for (int a=x;a>=1;a--)
   {
      f=f*a;
   }
   return f;
}
int ncr(int l,int m)
{
   return (fact(l)/(fact(m)*fact(l-m)));
}
int main()
{
   int inp;
   cin>>inp;
   for (int nu=0;nu<=inp;nu++)
   {
      for (int r=0;r<=nu;r++)
      {
         cout<<ncr(nu,r)<<"  ";
      }
      cout<<endl;
   }
   return 0;
}