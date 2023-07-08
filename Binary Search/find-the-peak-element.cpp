#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n;
   cin >> n;
   int a[n];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   int l = 0, r = n - 1;
   while (l <= r)
   {
      int mid = (l + r) / 2;
      if ((mid == 0 or a[mid - 1] < a[mid]) and (mid == n - 1 or a[mid] > a[mid + 1]))
      {
         cout << "Peak Element is at Index " << mid;
         return 0;
      }
      if (mid > 0 and a[mid - 1] > a[mid])
         r = mid - 1;
      else
         l = mid + 1;
   }
   return 0;
}