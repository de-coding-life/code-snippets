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
   for (int i=0;i<n;i++)
   {
      for (int j=0;j<i;j++)
      {
         if (array[j]==array[i])
         {
            cout<<j;
            return 0;
         }
      }
   }
   cout<<-1;
   return 0;
}