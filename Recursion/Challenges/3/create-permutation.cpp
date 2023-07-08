#include<bits/stdc++.h>
using namespace std;
void sb(string m,string n)
{
   if (n.length()==0)
   cout<<m<<endl;
   for (int i=0;i<n.length();i++)
   {  
      string temp=n;
      sb(m+n[i],temp.erase(i,1));
   }
}
int main()
{
   string n;
   cin>>n;
   sb("\n",n);
   return 0;
}