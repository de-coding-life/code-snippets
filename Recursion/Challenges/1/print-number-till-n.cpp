#include<bits/stdc++.h>
using namespace std;
void iprint(int n)
{  
   if (n==0)
   return;
   iprint(n-1);
   cout<<n<<" ";
}
void dprint(int n)
{  
   if (n==0)
   return;
   cout<<n<<" ";
   dprint(n-1);
}
int main()
{
   int n;
   cin>>n;
   iprint(n);
   cout<<endl;
   dprint(n);
}