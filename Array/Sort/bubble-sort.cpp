#include<bits/stdc++.h>
using namespace std;
void bubblesort(int array[],int n)
{
   for (int i=0;i<n-1;i++)
   {
      for (int j=0;j<n-i-1;j++)
      {
         if (array[j]>array[j+1])
         {
            int temp=array[j];
            array[j]=array[j+1];
            array[j+1]=temp;
         }
      }
   }
   for (int k=0;k<n;k++)
   {
      cout<<array[k]<<" ";
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
   bubblesort(array,n);
   return 0;
}