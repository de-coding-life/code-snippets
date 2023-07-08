#include<bits/stdc++.h>
using namespace std;
int prefixeval(string p)
{
   stack<int> st;
   for(int i=p.size()-1;i>=0;i--)
   {

      if (p[i]>='0' and p[i]<='9')
      st.push(p[i]-'0');
      else
      {
         int oa=st.top();
         st.pop();
         int ob=st.top();
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
   cout<<prefixeval("+1/4*2^-31^22");
   return 0;
}