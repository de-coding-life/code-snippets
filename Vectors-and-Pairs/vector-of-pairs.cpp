// Replace elements with their (index in sorted array)
// 8 10 16 7 14 5 3 12 9  --- Input
//    4  7 2  6 1 0  5 3  --- Output
#include<bits/stdc++.h>
using namespace std;
bool mycomp(pair<int,int> a,pair <int,int> b)
{
   return (b.second>=a.second);
}
int main()
{
   vector<pair<int,int>> p;
   int n,x;
   cin>>n;
   for (int i=0;i<n;i++)
   { 
      cin>>x;
      p.push_back(make_pair(i,x));
   }
   sort(p.begin(),p.end(),mycomp);
   int arr[n]={0};
   for (int i=0;i<n;i++)
   { 
      arr[p[i].first]=i;
   }
   for (int i=0;i<n;i++)
   { 
      cout<<arr[i]<<" ";
   }
   return 0;
}