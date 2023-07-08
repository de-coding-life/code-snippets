#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin>>n;
   int array[n];
   for (int i=0;i<n;i++)
   {
      cin>>array[i];
   }
   int maxx=INT_MIN,minn=INT_MAX;
   for (int i=0;i<n;i++)
   {
      if (array[i]>maxx)
      {
         maxx=array[i];
      }
      else if (array[i]<minn)
      {
         minn=array[i];
      }
   }
   cout<<"Maximum is "<<maxx<<endl<<"Minimum is "<<minn;
   return 0;
}