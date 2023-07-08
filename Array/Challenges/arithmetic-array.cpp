#include<bits/stdc++.h>
using namespace std;
void arithmaticarray(int array[],int n)
{  int len=2;
   int temp=2;
   for (int i=0;i<n-2;i++)
   {
      if ((array[i+1]-array[i])==(array[i+2]-array[i+1]))
      {
         temp+=1;
      }
      else
      {
         len=max(len,temp);
         temp=2;
      }
   }
   cout<<max(len,temp)<<endl;
   return;
}
int main()
{
   int n,t;
   cin>>t;
   for (int x=0;x<t;x++)
   {
      cin>>n;
      int array[n];
      for (int i=0;i<n;i++)
      {
         cin>>array[i];
      }
      cout<<"Case #"<<x+1<<": ";
      arithmaticarray(array,n);
   }
   return 0;
}