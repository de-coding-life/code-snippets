#include<bits/stdc++.h>
using namespace std;
void dup(string n,int k=0)
{
   if (n[k]=='\0')
   {
      return;
   }
   else if ((n[k]!=n[k+1]) or (n[k+1]=='\0'))
   {
      cout<<n[k];
   }
   dup(n,k+1);
}
int main()
{
   string n;
   cin>>n;
   dup(n);
   return 0;
}