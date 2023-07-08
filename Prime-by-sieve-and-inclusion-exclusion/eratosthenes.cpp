#include<iostream>
#include<cmath>
using namespace std;
int main()
{
   int i;
   cin>>i;
   bool c[i-1];
   for (int j=0;j<i-1;j++)
   c[j]=true;
   for (int j=2;j<=i;j++)
   {
      if (c[j-2]==true)
      {
         cout<<j<<endl;
         for(int k=j*j;k<=i;k+=j)
         c[k-2]=false;
      }
   }
   return 0;
}