/*
|| ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृ त्योर्मुक्षीय मामृतात् ||
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
// Policy Based Data Structure
// Note:Upper Bound would work as lower bound and vice versa
//  Find won't work in less_equal, so use find_by_order(order_of_key(a[i]))
//  To check existence use lower_bound
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;
#define ld long double
#define md 1000000007
const ll dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2};
const ll dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1};
#define vll vector<ll>
#define v2(dt, name, n, m, ini) vector<vector<dt>> name(n, vector<dt>(m, ini))
#define pll pair<ll, ll>
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define endl "\n"
#define fori(i, xx, yy) for (ll i = xx; i < yy; i++)
#define forl(i, xx, yy) for (ll i = xx; i < yy; i++)
#define forir(i, xx, yy) for (ll i = xx; i >= yy; i--)
#define forlr(i, xx, yy) for (ll j = xx; j >= yy; j--)
#define all(i) i.begin(), i.end()
#define yn(i)          \
   if (i)              \
      cout << "YES\n"; \
   else                \
      cout << "NO\n";
#define debug(i) cout << #i << " = " << i << endl
ll norm(ll x)
{
   x %= md;
   if (x < 0)
      x += md;
   return x;
}
template <class T>
T power(T a, ll b)
{
   T res = 1;
   for (; b; b /= 2, a *= a)
   {
      if (b & 1)
         res *= a;
   }
   return res;
}
struct Z
{
   ll x;
   Z(ll x = 0) : x(norm(x)) {}
   ll val() const
   {
      return x;
   }
   Z operator-() const
   {
      return Z(norm(md - x));
   }
   Z inv() const
   {
      return power(*this, md - 2);
   }
   Z &operator*=(const Z &rhs)
   {
      x = x * rhs.x % md;
      return *this;
   }
   Z &operator+=(const Z &rhs)
   {
      x = norm(x + rhs.x);
      return *this;
   }
   Z &operator-=(const Z &rhs)
   {
      x = norm(x - rhs.x);
      return *this;
   }
   Z &operator/=(const Z &rhs)
   {
      return *this *= rhs.inv();
   }
   friend Z operator*(const Z &lhs, const Z &rhs)
   {
      Z res = lhs;
      res *= rhs;
      return res;
   }
   friend Z operator+(const Z &lhs, const Z &rhs)
   {
      Z res = lhs;
      res += rhs;
      return res;
   }
   friend Z operator-(const Z &lhs, const Z &rhs)
   {
      Z res = lhs;
      res -= rhs;
      return res;
   }
   friend Z operator/(const Z &lhs, const Z &rhs)
   {
      Z res = lhs;
      res /= rhs;
      return res;
   }
   friend std::istream &operator>>(std::istream &is, Z &a)
   {
      ll v;
      is >> v;
      a = Z(v);
      return is;
   }
   friend std::ostream &operator<<(std::ostream &os, const Z &a)
   {
      return os << a.val();
   }
};

int main()
{
   Z a;
   // a = 1;
   a = 101;
   a = Z(101) + Z(101);
   cout << a << endl;
   return 0;
}
/*
|| ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृ त्योर्मुक्षीय मामृतात् ||
*/