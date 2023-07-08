#include<bits/stdc++.h>
using namespace std;
int p(int n)
{  if (n==0 or n==-1)
   return n+1;
   return p(n-1) + (n-1)*p(n-2);
}
int main()
{
   int n;
   cin>>n;
   cout<<p(n);
   return 0;
}