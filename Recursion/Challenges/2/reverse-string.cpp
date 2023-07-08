#include<bits/stdc++.h>
using namespace std;
void rev(string a,int k=0)
{
   if (a[k]=='\0')
   return;
   rev(a,k+1);
   cout<<a[k];
}
int main()
{
   string a;
   getline(cin,a);
   rev(a);
   return 0;
}