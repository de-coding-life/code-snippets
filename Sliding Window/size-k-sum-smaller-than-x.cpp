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
      int n, k, x;
      cin >> n >> k >> x;
      ll a[n];
      for (int i = 0; i < n; i++)
         cin >> a[i];
      ll sm = 0;
      ll ans = LLONG_MIN;
      bool ck = 0;
      for (int i = 0; i < k; i++)
         sm += a[i];
      if (sm < x)
      {
         ans = sm;
         ck = 1;
      }
      for (int i = k; i < n; i++)
      {
         sm += a[i];
         sm -= a[i - k];
         if (sm < x)
         {
            ans = max(ans, sm);
            ck = 1;
         }
      }
      if (ck)
         cout << ans << endl;
      else
         cout << "NO Subarray\n";
   }
   return 0;
}
/*

1
6 3 20
7 5 4 6 8 9
Ans: 18

*/