#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
   int n, k;
   cin >> n >> k;
   int a[n];
   for (int i = 0; i < n; i++)
      cin >> a[i];
   sort(a, a + n);
   int st = 1, en = a[n - 1] - a[0];
   int mid = 1;
   int ans;
   while (st <= en)
   {
      mid = (st + en) / 2;
      int fs, no = 1;
      fs = a[0];
      for (int i = 1; i < n; i++)
      {
         if (fs + mid <= a[i])
         {
            fs = a[i];
            no++;
         }
      }
      if (no >= k)
      {
         ans = mid;
         st = mid + 1;
      }
      else
         en = mid - 1;
   }
   cout << a[0] << " ";
   int ff = a[0];
   for (int i = 1; i < n; i++)
   {
      if (ff + ans <= a[i])
      {
         cout << a[i] << " ";
         ff = a[i];
      }
   }
   return 0;
}