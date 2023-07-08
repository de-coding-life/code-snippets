#include<bits/stdc++.h>
using namespace std;
int power(int n,int p)
{
   if (p==1)
   return n;
   return n*power(n,--p);
}
int main()
{
   int n,p;
   cin>>n>>p;
   cout<<power(n,p);
}