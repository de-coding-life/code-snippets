#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   const int N = 1000001;
   bool chck[N];
   cin>>n;
   int array[n];
   for (int i=0;i<n;i++)
   {
      cin>>array[i];
   }
   for (int i=0;i<N;i++)
   {
      chck[i]=false;
   }
   for (int i=0;i<n;i++)
   {
      if (array[i]>0)
      {
         chck[array[i]]=true;
      }
   }
   for(int i=1;i<N;i++)
   {
      if (!chck[i])
      {
         cout<<i;
         return 0;
      }
   }
}