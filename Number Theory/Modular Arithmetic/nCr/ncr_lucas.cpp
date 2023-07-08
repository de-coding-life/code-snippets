#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
// Policy Based Data Structure
// Note:Upper Bound would work as lower bound and vice versa
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;
#define ll long long int
#define ld long double
#define md 1000000007
#define vll vector<ll>
#define vld vector<ld>
#define vcc vector<char>
#define vss vector<string>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define endl "\n"
#define fori(xx, yy) for (ll i = xx; i < yy; i++)
#define forj(xx, yy) for (ll j = xx; j < yy; j++)
#define fork(xx, yy) for (ll k = xx; k < yy; k++)
#define forir(xx, yy) for (ll i = xx; i >= yy; i--)
#define forjr(xx, yy) for (ll j = xx; j >= yy; j--)
#define forkr(xx, yy) for (ll k = xx; k >= yy; k--)
#define iter(zz) for (auto it = zz.begin(); it != zz.end(); it++)
ll ncr_basic(ll n, ll r, ll p) // O(n*r)
{
   ll dp[r + 1] = {0};
   dp[0] = 1;
   for (ll i = 1; i <= n; i++)
   {
      for (ll j = min(r, i); j >= 1; j--)
      {
         dp[j] = (dp[j] + dp[j - 1]) % p;
      }
   }
   return dp[r];
}
ll ncr_lucas(ll n, ll r, ll p) // O(p^2 * logp(n))
{
   if (n == 0 or r == 0)
   {
      return 1;
   }
   return (ncr_lucas(n / p, r / p, p) * ncr_basic(n % p, r % p, p)) % p;
}
// According to lucas theorum, ncr%p is equal to product of ncr of individual respective digits of n and r in base p
int main()
{
   ll n, r;
   cin >> n >> r;
   cout << ncr_lucas(n, r, md);

   return 0;
}