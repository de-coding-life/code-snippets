#include<bits/stdc++.h>
using namespace std;
class s
{
   // can be accessed outside the class and also in derived class
   public:
   int pub;
   void f1()
   {
      cout<<"f1";
   }
   // cannot be accessed outside the class and in derived class
   private:
   int pri;
   void f2()
   {
      cout<<"f2";
   }
   // can be accessed in derived class , but not outside the class
   protected:
   int pro;
   void f3()
   {
      cout<<"f3";
   }
};
int main()
{
   s obj;
   obj.pub=1;
   obj.f1();
   return 0;
}