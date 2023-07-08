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
map<ll, ll> primefactorization(ll aa) // O(sqrt(n))
{
   ll temp = aa;
   map<ll, ll> pf;
   for (ll i = 2; i <= sqrt(temp); i++)
   {
      while (temp % i == 0)
      {
         temp /= i;
         pf[i]++;
      }
   }
   if (temp > 1)
      pf[temp]++;
   return pf;
}
int main()
{
   map<ll, ll> mpp = primefactorization(100);
   for (auto i : mpp)
   {
      cout << i.first << " ^ " << i.second << endl;
   }
   return 0;
}