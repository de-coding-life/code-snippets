#include<bits/stdc++.h>
using namespace std;
class stk
{
   private:
   queue<int> q1;
   queue<int> q2;
   public:
   void pu(int data)
   {
      q1.push(data);
      while (!(q1.empty()))
      {
         q2.push(q1.front());
         q1.pop();
      }
      while (!(q2.empty()))
      {
         q1.push(q2.front());
         q2.pop();
      }
   }
   void po()
   {
      if (q1.empty())
      return;
      while (!(q1.size()==1))
      {
         q2.push(q1.front());
         q1.pop();
      }
      q1.pop();
      while (!(q2.empty()))
      {
         q1.push(q2.front());
         q2.pop();
      }
   }
   int peek()
   {
      if (q1.empty())
      return 404;
      return q1.back();
   }
};
int main()
{
   stk x;
   x.pu(5);
   cout<<x.peek()<<endl;
   x.pu(10);
   cout<<x.peek()<<endl;
   x.pu(15);
   cout<<x.peek()<<endl;
   x.po();
   cout<<x.peek()<<endl;
   x.po();
   cout<<x.peek()<<endl;
   x.po();
   cout<<x.peek()<<endl;
   x.pu(10);
   x.pu(15);
   cout<<x.peek()<<endl;
   return 0;
}