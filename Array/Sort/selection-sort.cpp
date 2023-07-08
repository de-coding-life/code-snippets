#include<bits/stdc++.h>
using namespace std;
void selectionsort(int array[],int n)
{
   for (int i=0;i<n;i++)
   {
      for (int j=i+1;j<n;j++)
      {
         if (array[i]>array[j])
         {
            int temp=array[i];
            array[i]=array[j];
            array[j]=temp;
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
   selectionsort(array,n);
   return 0;
}