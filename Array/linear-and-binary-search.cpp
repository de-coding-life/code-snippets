#include<bits/stdc++.h>
using namespace std;
void linearsearch(int array[],int n,int key)
{
   for (int i=0;i<n;i++)
   {
      if (array[i]==key)
      {
         cout<<i;
         return;
      }
   }
   cout<<-1;
   return;
}
void binarysearch(int array[],int n,int key)
{
   int s=0,e=n-1;
   while (s<=e)
   {  
      if ((array[(s+e)/2])>key)
      {
         e=((s+e)/2)-1;
      }
      else if ((array[(s+e)/2])<key)
      {
         s=((s+e)/2)+1;
      }
      else
      {
         cout<<(s+e)/2;
         return;
      }
   }
   cout<<-1;
   return;
}
int main()
{
   int n,k,chc;
   cin>>n>>chc;
   int array[n];
   for (int i=0;i<n;i++)
   {
      cin>>array[i];
   }
   cin>>k;
   if (chc==1)
   {
      linearsearch(array,n,k);
   }
   else
   {
      binarysearch(array,n,k);
   }
   return 0;
}