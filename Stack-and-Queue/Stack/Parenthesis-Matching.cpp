#include<bits/stdc++.h>
using namespace std;
bool bp(string s)
{
   stack<char> st;
   for(int i=0;i<s.size();i++)
   {
      if (s[i]==')' or s[i]=='}' or s[i]==']')
      {
         if (st.size()==0)
         return 0;
         else if ((st.top()=='(' and s[i]==')') or (st.top()=='{' and s[i]=='}') or (st.top()=='[' and s[i]==']'))
         st.pop();
         else
         return 0;
      }
      else if (s[i]=='(' or s[i]=='{' or s[i]=='[')
      {
         st.push(s[i]);
      }
   }
   return 1;
}
int main()
{
   cout<<bp("[()()]");
   cout<<bp("[()()}{}{})(()]");
   cout<<bp("[({3})3()(3((3)3))3]3");
   return 0;
}