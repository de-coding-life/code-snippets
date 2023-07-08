#include<bits/stdc++.h>
using namespace std;
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
      else if (val==prec(st.top()) and val==3)
      {
         st.push(p[i]);
      }
      else
      {
         while (st.size()!=0 and val<=prec(st.top()))
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
   return ans;
}
int main()
{
   cout<<itopo("K+L-M*N+(O^P)*W/U/V*T+Q^J^A");
   return 0;
}

// A+B+C+D
// A^B^C
// A+B^C-D
// A+B^C^D-E