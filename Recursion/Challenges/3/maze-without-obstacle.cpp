#include<bits/stdc++.h>
using namespace std;
int maze(int n,int x=1,int y=1)
{  if (x==n || y==n)
   return 1;
   return maze(n,x+1,y)+maze(n,x,y+1);
}
int main()
{
   int n;
   cin>>n;
   cout<<maze(n);
   return 0;
}