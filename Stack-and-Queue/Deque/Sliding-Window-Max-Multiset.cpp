// Using multiset --------- Time Complexity = O(nlogn) ----------- Space complexity = O(k)

#include<bits/stdc++.h>
using namespace std;
int main()
{
   int n,k;
   cin>>n>>k;
   int arr[n];
   for(auto &i : arr)
   cin>>i;
   multiset<int,greater<int>> ml;
   for(int i=0;i<=n-k;i++){
      if (i==0){
         for (int j=i;j<i+k;j++)
         ml.insert(arr[j]);
      }
      else{
         ml.erase(ml.lower_bound(arr[i-1]));
         ml.insert(arr[i+k-1]);
      }
      cout<<*ml.begin()<<" ";
   }
   return 0;
}