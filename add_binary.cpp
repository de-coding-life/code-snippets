#include<bits/stdc++.h>
using namespace std;
int main(){
   int a,b,ans=0,iter=1,carry=0;
   cin>>a>>b;
   while (a>0 || b>0 || carry==1){
      if ((a%10) + (b%10) + (carry) == 3){
         ans+=(1*iter);
         carry=1;
      }
      else if ((a%10) + (b%10) + (carry) == 2){
         carry=1;
      }
      else if ((a%10) + (b%10) + (carry) == 1){
         ans+=(1*iter);
         carry=0;
      }
      else{
         carry=0;
      }
      iter*=10;
      a/=10;
      b/=10;
   }
   cout<<ans;
   cout<<-3%-10;
   return 0;
}