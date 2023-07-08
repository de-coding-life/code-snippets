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
   for (int i=0;i<n;i++)
   {if (st.empty() or a[st.top()]>=a[i])
   {st.push(i);
   continue;}
   else{
      while (!st.empty() and a[st.top()]<a[i])
      {ans[st.top()]=i+1;
      st.pop();}
      st.push(i);
   }
   }
   for (int i=0;i<n;i++)
   cout<<ans[i]<<" ";
   return 0;
}