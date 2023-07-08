#include<bits/stdc++.h>
using namespace std;
int postfixeval(string p)
{
   stack<int> st;
   for(int i=0;i<p.size();i++)
   {
      if (p[i]>='0' and p[i]<='9')
      st.push(p[i]-'0');
      else
      {
         int ob=st.top();
         st.pop();
         int oa=st.top();
         st.pop();
         switch(p[i])
         {
            case '+':
            st.push(oa+ob);
            break;
            case '-':
            st.push(oa-ob);
            break;
            case '*':
            st.push(oa*ob);
            break;
            case '/':
            st.push(oa/ob);
            break;
            case '^':
            st.push(int(pow(oa,ob)));
            break;
         }
      }
   }
   return st.top();
}
int main()
{
   cout<<postfixeval("+1*/42^-31^22");
   return 0;
}