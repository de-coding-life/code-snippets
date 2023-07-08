#include<bits/stdc++.h>
using namespace std;
void inssort(int array[],int n)
{
   for (int i=1;i<n;i++)
   {  
      for (int j=-1;j<i;j++)
      {
         if ((j==-1 && array[i]<=array[j+1]) || (array[j]<array[i] && array[i]<=array[j+1] && j!=-1))
         {
            int temp=array[i];
            for (int k=i-1;k>=j+1;k--)
            {
               array[k+1]=array[k];
            }
            array[j+1]=temp;
            break;
         }
      }
   }
   for (int l=0;l<n;l++)
   {
      cout<<array[l]<<" ";
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
   inssort(array,n);
   return 0;
}