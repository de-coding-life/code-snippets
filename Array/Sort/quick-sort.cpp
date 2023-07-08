#include<bits/stdc++.h>
using namespace std;
int parti(int a[], int s,int e)
{
   int p=s;
   for (int i=s+1;i<=e;i++)
   {
      if (a[i]<a[s])
      {
         p++;
         if (a[p]>a[s])
         swap(a[p],a[i]);
      }
   }
   swap(a[s],a[p]);
   return p;
}
void QuickSort(int a[],int s,int e)
{
   if (s>=e)
   return;
   int p=parti(a,s,e);
   QuickSort(a,s,p-1);
   QuickSort(a,p+1,e);
}
int main()
{
   int n;
   cin>>n;
   int a[n];
   for (int i=0;i<n;i++)
   cin>>a[i];
   QuickSort(a,0,n-1);
   for (int i=0;i<n;i++)
   cout<<a[i]<<" ";
   return 0;
}