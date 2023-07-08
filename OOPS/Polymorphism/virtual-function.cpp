#include<bits/stdc++.h>
using namespace std;
class base
{
   public:
   virtual void print()
   {
      cout<<"base print"<<endl;
   }
   void check()
   {
      cout<<"base check"<<endl;
   }
};
class derived : public base
{
   public:
   void print()
   {
      cout<<"derived print"<<endl;
   }
   void check()
   {
      cout<<"derived check"<<endl;
   }
};
int main()
{
   base *b;
   derived d;
   b=&d;
   b->check();
   b->print();
   return 0;
}