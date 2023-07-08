#include<bits/stdc++.h>
using namespace std;
void sumofsubarray(int array[],int n)
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
         cout<<sum<<endl;
      }
   }
   return;
}
int main()
{
   int n;
   cin>>n;
   int array[n];
   for (int i=0;i<n;i++)
   {
      cin>>array[i];
   }
   sumofsubarray(array,n);
   return 0;
}