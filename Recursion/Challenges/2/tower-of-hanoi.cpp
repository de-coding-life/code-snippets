#include<bits/stdc++.h>
using namespace std;
void toh(int n,int s=1,int e=3,int o=2)
{
   if (n!=0)
   {
   toh(n-1,s,o,e);
   cout<<n<<" Block - "<<char(s+64)<<" to "<<char(e+64)<<endl;
   toh(n-1,o,e,s);
   }
}
int main()
{
   int n;
   cin>>n;
   toh(n);
   return 0;
}