#include<bits/stdc++.h>
using namespace std;
void sb(string n,int s=0,int e=0)
{
   if (n[e]=='\0')
   {
   return;
   }
   for (int i=s;i<=e;i++)
   cout<<n[i];
   cout<<endl;
   sb(n,s,e+1);
   if (e==s)
   sb(n,s+1,s+1);
}
int main()
{
   string n;
   cin>>n;
   sb(n);
   return 0;
}