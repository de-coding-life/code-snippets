#include<bits/stdc++.h>
using namespace std;
class cmplx
{
   public:
   int r,i;
   cmplx (int x,int y)
   {
      r=x;
      i=y;
   }
   cmplx operator + (cmplx &c)
   {
      cmplx temp(r+c.r,i+c.i);
      return temp;
   }
   void get()
   {
      cout<<endl<<r<<" + "<<i<<'i';
   }
};
int main()
{
   cmplx n(5,6);
   n.get();
   cmplx m(1,3);
   m.get();
   cmplx u=n+m;
   u.get();
   cmplx y=u+n;
   y.get();
   return 0;
}