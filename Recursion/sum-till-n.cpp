#include<bits/stdc++.h>
using namespace std;
int summ(int a)
{
   if (a==1)
   return 1;
   return summ(a-1) + a;
}
int main()
{
   int n;
   cin>>n;
   cout<<summ(n);
}