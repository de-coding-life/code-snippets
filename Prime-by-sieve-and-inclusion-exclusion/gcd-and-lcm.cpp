#include<bits/stdc++.h>
using namespace std;
int main()
{
   int a,b,c;
   cin>>a>>b;
   int at=a,bt=b;
   if(b>a)
   swap(a,b);
   while (b!=0)
   {
      c=a%b;
      a=b;
      b=c;
   }
   cout<<"HCF or GCD is "<<a<<endl;
   cout<<"LCM is "<<at*bt/a;

   return 0;
}