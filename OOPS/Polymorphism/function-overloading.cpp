#include<bits/stdc++.h>
using namespace std;
class fo
{
   public:
   void f(int a)
   {cout<<"Int\n";}
   void f(int a,int b)
   {cout<<"Int-2\n";}
   void f(char a)
   {cout<<"Char\n";}
   void f(string a)
   {cout<<"String\n";}
};
int main()
{
   fo obj;
   obj.f(1);
   obj.f('c');
   obj.f("str");
   obj.f(1,2);
   return 0;
}