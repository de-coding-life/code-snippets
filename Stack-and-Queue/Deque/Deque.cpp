#include<bits/stdc++.h>
using namespace std;
int main()
{
   deque<int> d;
   d.push_back(2);
   d.push_back(3);
   d.push_front(1);
   for (auto i:d)
   {
      cout<<i<<endl;
   }
   cout<<d.front();
   cout<<d.back();
   d.pop_back();
   d.pop_front();
   cout<<d.back();
   cout<<d.front();
   return 0;
}