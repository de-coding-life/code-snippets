#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t;
   cin >> t;
   for (int ii = 0; ii < t; ii++)
   {
      int n, m;
      cin >> n >> m;
      ll a[n];
      ll l = 0, r = 0;
      for (int i = 0; i < n; i++)
      {
         cin >> a[i];
         r += a[i];
         l = max(a[i], l);
      }
      l = a[0];
      int ans;
      while (l <= r)
      {
         ll mid = (l + r) / 2;
         ll temp = 0;
         ll count = 1;
         for (int i = 0; i < n; i++)
         {
            if (temp + a[i] <= mid)
               temp += a[i];
            else
            {
               temp = a[i];
               count++;
            }
         }
         if (count <= m)
         {
            ans = mid;
            r = mid - 1;
         }
         else
            l = mid + 1;
      }
      cout << ans << endl;
   }
   return 0;
}