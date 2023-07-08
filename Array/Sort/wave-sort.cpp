#include <bits/stdc++.h>
using namespace std;
void wave(int arr[], int n)
{
   for (int i=1;i<n;i+=2)
   {
      if (arr[i]>arr[i-1])
      swap(arr[i],arr[i-1]);
      if ((arr[i]>arr[i+1]) and (i!=n-1))
      swap(arr[i],arr[i+1]);
   }
}
int main()
{
   int n;
   cin >> n;
   int arr[n];
   for (int i = 0; i < n; i++)
   cin >> arr[i];
   wave(arr, n);
   for (int i = 0; i < n; i++)
   cout << arr[i] << " ";
   return 0;
}