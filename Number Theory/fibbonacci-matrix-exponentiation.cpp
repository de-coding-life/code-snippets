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
vector<vector<ll>> matmul(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
   vector<vector<ll>> x(2, vector<ll>(2));
   x[0][0] = ((a[0][0] * b[0][0]) % md + (a[0][1] * b[1][0]) % md) % md;
   x[0][1] = ((a[0][0] * b[0][1]) % md + (a[0][1] * b[1][1]) % md) % md;
   x[1][0] = ((a[1][0] * b[0][0]) % md + (a[1][1] * b[1][0]) % md) % md;
   x[1][1] = ((a[1][0] * b[0][1]) % md + (a[1][1] * b[1][1]) % md) % md;
   return x;
}
vector<vector<ll>> matpow(vector<vector<ll>> &a, ll pow)
{
   if (pow < 1) // Jugaad for base case of f(0) & f(1)
      return {{pow + 1, 0}, {0, 0}};
   else if (pow == 1)
      return a;
   vector<vector<ll>> mid = matpow(a, pow / 2);
   mid = matmul(mid, mid);
   if (pow % 2 == 1)
      mid = matmul(mid, a);
   return mid;
}
int main()
{

   vector<vector<ll>> a = {{1, 1}, {1, 0}};
   ll n;
   cin >> n;
   cout << matpow(a, n - 1)[0][0] << endl;
   return 0;
}