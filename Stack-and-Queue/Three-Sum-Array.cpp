#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,sm;
   cin>>n>>sm;
   int a[n];
   for (int i=0;i<n;i++)
   cin>>a[i];
   cout<<"The Pairs with Sum = "<<sm<<" are shown Below (If Any) VVVVVVVV"<<endl;
   sort(a,a+n);
   for (int i=0;i<n;i++)
   {
      int p1=i+1,p2=n-1;
      for (int j=i+1;j<n-1;j++)
      {
         if (a[p1]+a[p2]==sm-a[i])
         {
            cout<<endl<<"( "<<a[i]<<" , "<<a[p1]<<" , "<<a[p2]<<" )";
            break;
         }
         else if (a[p1]+a[p2]<sm-a[i])
         p1++;
         else
         p2--;
      }
   }
   return 0;
}