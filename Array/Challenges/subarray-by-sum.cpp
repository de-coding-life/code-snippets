#include<bits/stdc++.h>
using namespace std;
void ss(int array[],int n,int x)
{ 
   for (int i=0;i<n;i++)
   {
      for (int j=i;j<n;j++)
      {
         int sum=0;
         for (int k=i;k<=j;k++)
         {
            sum+=array[k];
         }
         if (x==sum)
         {
            cout<<i<<" "<<j<<endl;
         }
      }
   }
   return;
}
int main()
{
   int n,x;
   cin>>n>>x;
   int array[n];
   for (int i=0;i<n;i++)
   {
      cin>>array[i];
   }
   ss(array,n,x);
   return 0;
}