// Number of All coprimes less than n and relative to n
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
ll euler(int n) // Formula Based O(sqrt(n)*log(n))
{
   ll ans = n;
   for (int i = 2; i <= sqrt(n); i++)
   {
      bool ck = 0;
      while (n % i == 0)
      {
         n /= i;
         ck = 1;
      }
      if (ck)
      {
         ans /= i;
         ans *= (i - 1);
      }
   }
   if (n > 1)
   {
      ans /= n;
      ans *= (n - 1);
   }
   return ans;
}
// Another Approach you can try
int main()
{
   int n;
   cin >> n;
   cout << euler(n) << endl;
   return 0;
}
