#include <iostream>
#include <algorithm>
#define ll long long int
using namespace std;
int main()
{
   int n, m;
   cin >> n >> m;
   int a[n];
   ll en = 0;
   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
      en += a[i];
   }
   if (m > n)
   {
      cout << -1 << endl;
      return 0;
   }
   sort(a, a + n);
   int st = a[n - 1];
   int mid = 1;
   int ans;
   while (st <= en)
   {
      mid = (st + en) / 2;
      int fs, no = 0;
      fs = a[0];
      for (int i = 1; i < n; i++)
      {
         if (fs + a[i] <= mid)
            fs += a[i];
         else
         {
            no++;
            fs = a[i];
         }
      }
      no++;
      if (no <= m)
      {
         ans = mid;
         en = mid - 1;
      }
      else
         st = mid + 1;
   }
   cout << ans << endl;
   return 0;
}