#include<bits/stdc++.h>
using namespace std;
int sd(int s,int e,int c=0,int d=0)
{  
   c+=d;
   if (c==e)
   return 1;
   else if (c>e)
   return 0;
   return sd(s,e,c,1)+sd(s,e,c,2)+sd(s,e,c,3)+sd(s,e,c,4)+sd(s,e,c,5)+sd(s,e,c,6);
}
int main()
{
   // string n;
   // cin>>n;
   cout<<sd(0,3);
   return 0;
}