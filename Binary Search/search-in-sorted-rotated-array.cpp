#include <bits/stdc++.h>
using namespace std;
int main()
{
   int n, key;
   cin >> n >> key;
   int a[n];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   int l = 0, r = n - 1;
   while (l <= r)
   {
      int mid = (l + r) / 2;
      if (a[mid] == key)
      {
         cout << "Element Found at " << mid << endl;
         return 0;
      }
      if (a[mid] > a[r]) // Pivot found in right
      {
         if (key <= a[r] or key >= a[mid]) // Think
            l = mid + 1;
         else
            r = mid - 1;
      }
      else if (a[mid] < a[l]) // Pivot found in left
      {
         if (key <= a[mid] or key >= a[l]) // Think
            r = mid - 1;
         else
            l = mid + 1;
      }
      else // No Pivot Found (Simple Binary Search)
      {
         if (key > a[mid])
            l = mid + 1;
         else
            r = mid - 1;
      }
   }
   cout << "Element Not Found\n";
   return 0;
}