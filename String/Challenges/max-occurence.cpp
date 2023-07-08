#include<bits/stdc++.h>
using namespace std;
int main()
{ 
   string s;
   int arr[257];
   for (int i=0;i<257;i++)
   arr[i]=0;
   cin>>s;
   for (int i=0;i<s.length();i++)
   {
      arr[s[i]]++;
   }
   int temp=0;
   char ans;
   for (int i=0;i<257;i++)
   {
      if (arr[i]>temp)
      {  
         ans=i;
         temp=arr[i];
      }
   }
   cout<<ans<<" "<<temp;
   return 0;
}