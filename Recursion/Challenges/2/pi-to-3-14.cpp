#include<bits/stdc++.h>
using namespace std;
void pi(string a,int k=0)
{
   if (a[k]=='p' && a[k+1]=='i')
   {
   cout<<3.14;
   pi(a,k+2);
   }
   else if (a[k]!='\0')
   {
   cout<<a[k];
   pi(a,k+1);
   }
}
int main()
{
   string a;
   getline(cin,a);
   pi(a);
   return 0;
}