#include<bits/stdc++.h>
using namespace std;
void wd(string n,string ans="",int s=0)
{
   if (n[s]=='\0')
   {
   cout<<ans<<"\n";
   return;
   }
   if (n[s]=='1')
   {
   wd(n,ans+'.',s+1);
   wd(n,ans+'/',s+1);
   }
   else if (n[s]=='2')
   {
   wd(n,ans+'a',s+1);
   wd(n,ans+'b',s+1);
   wd(n,ans+'c',s+1);
   }
   else if (n[s]=='3')
   {
   wd(n,ans+'d',s+1);
   wd(n,ans+'e',s+1);
   wd(n,ans+'f',s+1);
   }
   else if (n[s]=='4')
   {
   wd(n,ans+'g',s+1);
   wd(n,ans+'h',s+1);
   wd(n,ans+'i',s+1);
   }
   else if (n[s]=='5')
   {
   wd(n,ans+'j',s+1);
   wd(n,ans+'k',s+1);
   wd(n,ans+'l',s+1);
   }
   else if (n[s]=='6')
   {
   wd(n,ans+'m',s+1);
   wd(n,ans+'n',s+1);
   wd(n,ans+'o',s+1);
   }
   else if (n[s]=='7')
   {
   wd(n,ans+'p',s+1);
   wd(n,ans+'q',s+1);
   wd(n,ans+'r',s+1);
   wd(n,ans+'s',s+1);
   }
   else if (n[s]=='8')
   {
   wd(n,ans+'t',s+1);
   wd(n,ans+'u',s+1);
   wd(n,ans+'v',s+1);
   }
   else if (n[s]=='9')
   {
   wd(n,ans+'w',s+1);
   wd(n,ans+'x',s+1);
   wd(n,ans+'y',s+1);
   wd(n,ans+'z',s+1);
   }
}
int main()
{
   string n;
   cin>>n;
   wd(n);
   return 0;
}