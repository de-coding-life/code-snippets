#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll kadane(ll n, ll a[])
{
   ll bs = LLONG_MIN, cs = 0;
   for (int i = 0; i < n; i++)
   {
      if (cs >= 0)
      {
         cs += a[i];
         bs = max(bs, cs);
      }
      else
      {
         cs = a[i];
         bs = max(bs, cs);
      }
   }
   return bs;
}
int main()
{
   ll n;
   cin >> n;
   ll a[n];
   for (int i = 0; i < n; i++)
   {
      cin >> a[i];
   }
   cout << kadane(n, a);
   return 0;
}