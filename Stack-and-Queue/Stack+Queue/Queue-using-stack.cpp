#include<bits/stdc++.h>
using namespace std;
#define per 1000
class que
{
   private:
   int a[per];
   stack<int> s1;
   stack<int> s2;
   public:
   void enqueue(int data)
   {
      while (!(s2.empty()))
      {
         s1.push(s2.top());
         s2.pop();
      }
         s1.push(data);
   }
   void dequeue()
   {
      if (s1.empty() and s2.empty())
      return;
      while (!(s1.empty()))
      {
         s2.push(s1.top());
         s1.pop();
      }
         s2.pop();
   }
   int peek()
   {
      while (!(s2.empty()))
      {
         s1.push(s2.top());
         s2.pop();
      }
      if (s1.empty())
      return 404;
      return s1.top();
   }
};
int main()
{
   que x;
   x.enqueue(5);
   x.enqueue(10);
   x.enqueue(15);
   cout<<x.peek()<<endl;
   x.dequeue();
   cout<<x.peek()<<endl;
   x.dequeue();
   cout<<x.peek()<<endl;
   x.dequeue();
   cout<<x.peek()<<endl;
   x.enqueue(10);
   x.enqueue(15);
   cout<<x.peek()<<endl;
   return 0;
}