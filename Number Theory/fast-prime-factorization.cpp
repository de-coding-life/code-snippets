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
int main()
{
   vll spf = preprocessing(1e6);
   map<ll, ll> mpp = primefactorization(29, spf);
   for (auto i : mpp)
   {
      cout << i.first << " ^ " << i.second << endl;
   }
   return 0;
}