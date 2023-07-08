// push_back(),  pop_back(),  ::iterator,  element:,  swap()


#include<bits/stdc++.h>
using namespace std;
int main()
{
   vector<int> a;
   a.push_back(5);
   a.push_back(4);
   a.push_back(3);
   a.push_back(2);
   a.push_back(1);
   for (int i=0;i<5;i++)
   {
      cout<<a[i]<<" ";
   }
   cout<<endl;

   vector<int>::iterator i;
   for (i=a.begin();i!=a.end();i++)
   {
      cout<<*i<<" ";
   }
   cout<<endl;

   for (auto element:a)
   {
      cout<<element<<" ";
   }
   cout<<endl;
   a.pop_back();

   vector<int> v (10,100) ;
   for (auto element:v)
   {
      cout<<element<<" ";
   }
   cout<<endl;

   swap(a,v);
   for (auto element:v)
   {
      cout<<element<<" ";
   }
   cout<<endl;
   sort(v.begin(),v.end());
   for (auto element:v)
   {
      cout<<element<<" ";
   }
   cout<<endl;
   return 0;
}