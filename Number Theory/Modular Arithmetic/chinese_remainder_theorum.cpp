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
ll extended_gcd(ll a, ll b, ll &x, ll &y)
{
   if (b == 0)
   {
      x = 1;
      y = 0;
      return a;
   }
   ll x1, y1;
   ll ans = extended_gcd(b, a % b, x1, y1);
   x = y1;
   y = x1 - ((a / b) * y1);
   return ans;
}
ll mulinv(ll a, ll mdd)
{
   ll x, y;
   extended_gcd(a, mdd, x, y);
   return ((x % mdd) + mdd) % mdd;
}
ll findminX(int num[], int rem[], int n)
{
   ll prod = 1;
   for (int i = 0; i < n; i++)
      prod *= num[i];
   ll x = 0;
   for (int i = 0; i < n; i++)
   {
      ll pr = prod / num[i];
      x = (x + (rem[i] * pr * mulinv(pr, num[i]))) % prod;
   }
   return x;
}
int main()
{
   int n;
   cin >> n;
   int rem[n], num[n];
   for (int i = 0; i < n; i++)
   {
      cin >> num[i];
   }
   for (int i = 0; i < n; i++)
   {
      cin >> rem[i];
   }
   cout << findminX(num, rem, n);
   return 0;
}