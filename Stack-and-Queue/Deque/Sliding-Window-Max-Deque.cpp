// Using Deque --------- Time Complexity = O(n) ----------- Space complexity = O(k)

#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,k;
   cin>>n>>k;
   int arr[n];
   for(auto &i : arr)
   cin>>i;
   deque<int> d;
   for (int i=0;i<k;i++)
   {
      while (!d.empty() and arr[d.back()]<=arr[i])
      d.pop_back();
      d.push_back(i);
   }
   cout<<arr[d.front()]<<" ";
   for(int i=k;i<n;i++)
   {
      if (d.front()==i-k)
      d.pop_front();
      while (!d.empty() and arr[d.back()]<=arr[i])
      d.pop_back();
      d.push_back(i);
      cout<<arr[d.front()]<<" ";
   }
   return 0;
}