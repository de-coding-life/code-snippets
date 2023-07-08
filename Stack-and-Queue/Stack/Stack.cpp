#include<bits/stdc++.h>
using namespace std;
#define per 1000
class stackk
{
   private:
   int a[per];
   int sk=-1;
   public:
   bool empty()
   {return sk==-1;}
   void push(int data)
   {
      a[++sk]=data;
   }
   void pop()
   {
      if (!empty())
      sk--;
   }
   int top()
   {
      if (!empty())
      return a[sk];
   }
   int display() // Custom function not present in STL
   {  
      cout<<"-------------";
      for (int i=sk;i>=0;i--)
      {
         cout<<endl<<"| "<<a[i]<<" |";
         if (i==sk)
         cout<<" <------ ";
         cout<<endl<<"-------------";
      }
      cout<<endl;
   }
};
int main()
{
   stackk x;
   x.push(5);
   x.push(10);
   x.display();
   x.pop();
   cout<<x.top()<<endl;
   x.pop();
   cout<<x.empty();
   return 0;
}