#include<bits/stdc++.h>
using namespace std;
void mx(string n,int k=0,int x=0)
{
   if (n[k]=='\0')
   {
      for (int i=0;i<x;i++)
      cout<<'x';
   }
   else if (n[k]!='x')
   {
      cout<<n[k];
      mx(n,k+1,x);
   }
   else
   {
      mx(n,k+1,x+1);
   }
}
int main()
{
   string n;
   cin>>n;
   mx(n);
   return 0;
}