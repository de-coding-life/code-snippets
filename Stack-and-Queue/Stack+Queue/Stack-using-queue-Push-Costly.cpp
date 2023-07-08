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
      q2.push(data);
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
   q1.pop();
   }
   int peek()
   {
      return q1.front();
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