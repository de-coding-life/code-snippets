#include<bits/stdc++.h>
using namespace std;
void maxtilli(int array[],int n)
{ 
   int temp=array[0];
   for (int j=0;j<n;j++)
   {
      if (array[j]>temp)
      {
         temp=array[j];
      }
      cout<<temp<<" ";
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
   maxtilli(array,n);
   return 0;
}