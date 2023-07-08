#include<bits/stdc++.h>
using namespace std;
int main()
{  while (true)
   {
      cout<<"\n1 for lower \n2 for upper \n3 for toggle\n";
      int n;
      cin>>n;
      cout<<"\nEnter String\n";
      string s;
      cin>>s;
      switch(n)
      {
         case 1:
            for(int i=0;i<s.size();i++)
            {  
               if (s[i]<'a')
               {
                  s[i]=s[i]+32;
               }
            }
            break;
         case 2:
            for(int i=0;i<s.length();i++)
            {
               if (s[i]>='a')
               {
                  s[i]=s[i]-32;
               }
            }
            break;
         case 3:
            for(int i=0;i<s.length();i++)
            {
               if (s[i]>='a')
               {
                  s[i]=s[i]-32;
               }
               else
               {
                  s[i]=s[i]+32;
               }
            }
      }
      cout<<endl<<s<<endl;
   }
   return 0;
}