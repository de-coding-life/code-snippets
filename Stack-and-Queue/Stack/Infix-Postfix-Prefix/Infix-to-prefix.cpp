#include<bits/stdc++.h>
using namespace std;
void rev(string &as)
{
   for(int i=0;i<as.size()/2;i++)
   {
      swap(as[i],as[as.size()-1-i]);
   }
}
void bc(string &as)
{
      for(int i=0;i<as.size();i++)
      {
         if (as[i]=='(')
         as[i]=')';
         else if (as[i]==')')
         as[i]='(';
      }
}
int prec(char c)
{
   if (c=='^')
   return 3;
   else if ((c=='/') or (c=='*'))
   return 2;
   else if ((c=='+') or (c=='-'))
   return 1;
   else if ((c=='(' or c==')'))
   return -1;
   else
   return 0;
}
string itopo(string p)
{
   stack<char> st;
   string ans="";
   for(int i=0;i<p.size();i++)
   {
      int val=prec(p[i]);
      if (val==0)
      ans+=p[i];
      else if (p[i]=='(')
      st.push(p[i]);
      else if (p[i]==')')
      {
         while (st.top()!='(')
         {
            ans+=st.top();
            st.pop();
         }
         st.pop();
      }
      else if (st.size()==0 or val>prec(st.top()))
      {
         st.push(p[i]);
      }
      else if (val==prec(st.top()) and val!=3)
      {
         if (val!=3)
         st.push(p[i]); // any other same - push as associativity left to right
         else // if ^ after ^ then dont push
         ans+=p[i];
      }
      else
      {
         while (st.size()!=0 and val<prec(st.top()))
         {
            ans+=st.top();
            st.pop();
         }
         st.push(p[i]);
      }
   }
   while (st.size()>0)
   {
      ans+=st.top();
      st.pop();
   }
   rev(ans);
   return ans;
}
int main()
{  string ss="2+2^2-2";
   rev(ss);
   bc(ss);
   cout<<itopo(ss);
   return 0;
}