#include<bits/stdc++.h>
using namespace std;
void sb(string n,string ans="",int s=0)
{
   if (n[s]=='\0')
   {
   cout<<ans<<"\n";
   return;
   }
   sb(n,ans+n[s],s+1);
   sb(n,ans,s+1);
}
int main()
{
   string n;
   cin>>n;
   sb(n);
   return 0;
}