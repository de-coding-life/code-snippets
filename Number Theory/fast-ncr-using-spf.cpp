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
vector<ll> preprocessing(int mxn) // O(n)
{
   vector<ll> pre(mxn + 1);
   for (int i = 0; i <= mxn; i++)
   {
      pre[i] = i;
   }
   for (int i = 2; i <= mxn; i++)
   {
      for (int j = i; j <= mxn; j += i)
      {
         if (pre[j] > i)
            pre[j] = i;
      }
   }
   return pre;
}
map<ll, ll> primefactorization(int nn, vll &spf) // O(log{n})
{
   map<ll, ll> myp;
   while (nn > 1)
   {
      myp[spf[nn]]++;
      nn /= spf[nn];
   }
   return myp;
}
ll ncr(ll n, ll r, ll mdd = -1) // O(nlogn)
{
   vector<ll> spf = preprocessing(n);
   vector<ll> ans(n + 1, 0);
   for (int i = n; i > r; i--)
   {
      map<ll, ll> prime = primefactorization(i, spf);
      for (auto i : prime)
         ans[i.first] += i.second;
   }
   for (int i = n - r; i > 1; i--)
   {
      map<ll, ll> prime = primefactorization(i, spf);
      for (auto i : prime)
         ans[i.first] -= i.second;
   }
   ll ret = 1;
   for (int i = 0; i <= n; i++)
   {
      for (int j = 0; j < ans[i]; j++)
      {
         if (mdd == -1)
            ret *= i;
         else
            ret = (ret * i) % mdd;
      }
   }
   return ret;
}
int main()
{
   cout << ncr(10, 7, md);
   return 0;
}