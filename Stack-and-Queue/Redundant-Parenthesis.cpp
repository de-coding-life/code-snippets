#include<bits/stdc++.h>
using namespace std;
int main()
{
   stack<char> st;
   string inp;
   cin>>inp;
   for (int i=0;i<inp.size();i++)
   {
      if (st.empty())
      st.push(inp[i]);
      else
      {
         if (inp[i]==')')
         {  
            if (st.top()=='(')
            {cout<<1;
            return 0;}
            while (st.top()!='(')
            st.pop();
         }
         else if (inp[i]=='(' or inp[i]=='+' or inp[i]=='-' or inp[i]=='*' or inp[i]=='/' or inp[i]==')')
         st.push(inp[i]);
      }
   }
   cout<<0;
   return 0;
}