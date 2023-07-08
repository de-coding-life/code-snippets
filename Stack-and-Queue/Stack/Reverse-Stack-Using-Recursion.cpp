#include<bits/stdc++.h>
using namespace std;
void insertatbottom(int t,stack<int> &stk)
{
   if (stk.size()==0)
   {stk.push(t);
   return;}
   int an=stk.top();
   stk.pop();
   insertatbottom(t,stk);
   stk.push(an);
}
void rev(stack<int> &stk)
{
   if (stk.size()==0)
   return;
   int t=stk.top();
   stk.pop();
   rev(stk);
   insertatbottom(t,stk);
}
int main()
{
   stack<int> s;
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   rev(s);
   while (s.size()>0)
   {
      cout<<s.top();
      s.pop();
   }
   return 0;
}