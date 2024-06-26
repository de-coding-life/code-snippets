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
//  OR store pairs in less
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;
#define ld long double
#define md 1000000007
#define vll vector<ll>
#define v2(dt, name, n, m, ini) vector<vector<dt>> name(n, vector<dt>(m, ini))
#define pll pair<ll, ll>
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define endl "\n"
#define fori(i, xx, yy) for (int i = xx; i < yy; i++)
#define forl(i, xx, yy) for (ll i = xx; i < yy; i++)
#define forir(i, xx, yy) for (int i = xx; i >= yy; i--)
#define forlr(i, xx, yy) for (ll j = xx; j >= yy; j--)
#define all(i) i.begin(), i.end()
#define iter(zz) for (auto it = zz.begin(); it != zz.end(); it++)
vector<ll> preprocessing(int mxn)
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
ll gcd(ll aa, ll bb)
{
   return (bb == 0) ? aa : gcd(bb, aa % bb);
}
int main()
{
   int t = 1;
   cin >> t;
   vll isprime = preprocessing(1000001);
   for (int ii = 1; ii <= t; ii++)
   {
      int n;
      cin >> n;
      vll a(n);
      fori(i, 0, n)
      {
         cin >> a[i];
      }
      ll pgcd[n], sgcd[n];
      pgcd[0] = a[0];
      sgcd[n - 1] = a[n - 1];
      for (int i = 0; i < n; i++)
      {
         pgcd[i] = gcd(pgcd[i - 1], a[i]);
      }
      for (int i = n - 2; i >= 0; i--)
      {
         sgcd[i] = gcd(sgcd[i + 1], a[i]);
      }
      vll poss;
      for (int i = 0; i < n; i++)
      {
         if (i == 0)
         {
            poss.pb(sgcd[i + 1]);
         }
         else if (i == n - 1)
         {
            poss.pb(pgcd[i - 1]);
         }
         else
         {
            poss.pb(gcd(sgcd[i + 1], pgcd[i - 1]));
         }
      }
      ll ans = 0;
      for (int i = 0; i < n; i++)
      {
         cout << poss[i];
         if ((poss[i] == 1) or (isprime[poss[i]] == poss[i]))
         {
            ans = 1;
            break;
         }
      }
      if (ans == 0)
         cout << "BOB\n";
      else
         cout << "DRAW\n";
   }
   return 0;
}
/*
|| ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृ त्योर्मुक्षीय मामृतात् ||
*/