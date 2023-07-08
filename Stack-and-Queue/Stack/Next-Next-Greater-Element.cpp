#include<bits/stdc++.h>
using namespace std;
int main(){
   int n;
   cin>>n;
   int a[n];
   int ans[n];
   for (int i=0;i<n;i++)
   {cin>>a[i];
   ans[i]=-1;}
   stack<int> st;
   stack<int> st2;
   for (int i=0;i<n;i++)
   {if (st.empty() or a[abs(st.top())-1]>=a[i])
   {st.push(i+1);
   continue;}
   else{
      while (!st.empty() and a[abs(st.top())-1]<a[i])
      {
         if (st.top()<0)
         {ans[abs(st.top())-1]=i+1;
            st.pop();}
         else{ 
            st2.push(-st.top());
            st.pop();}
      }
      st.push(i+1);
      while (!st2.empty())
      {
         st.push(st2.top());
         st2.pop();
      }
   }}
   for (int i=0;i<n;i++)
   cout<<ans[i]<<" ";
   return 0;
}