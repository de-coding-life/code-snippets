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
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2};
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1};
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
#define yn(i)          \
   if (i)              \
      cout << "YES\n"; \
   else                \
      cout << "NO\n";
#define debug(i) cout << #i << " = " << i << endl
vector<vll> rotc(vector<vll> &a) // Clockwise
{
   ll n = a.size();
   ll m = a[0].size();
   vector<vll> x(m, vll(n, 0));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         x[j][n - 1 - i] = a[i][j];
      }
   }
   return x;
}
vector<vll> rota(vector<vll> &a) // Anti - Clockwise
{
   ll n = a.size();
   ll m = a[0].size();
   vector<vll> x(m, vll(n, 0));
   for (int i = 0; i < n; i++)
   {
      for (int j = 0; j < m; j++)
      {
         x[m - 1 - j][i] = a[i][j];
      }
   }
   return x;
}

int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   int t = 1;
   cin >> t;
   for (int ii = 1; ii <= t; ii++)
   {
      ll n, m;
      cin >> n >> m;
      vector<vll> a(n, vll(m));
      fori(i, 0, n)
      {
         fori(j, 0, m)
         {
            cin >>
                a[i][j];
         }
      }
      a = rota(a);
      swap(n, m);
      fori(i, 0, n)
      {
         fori(j, 0, m)
         {
            cout << a[i][j] << " ";
         }
         cout << endl;
      }
   }
   return 0;
}
/*
|| ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृ त्योर्मुक्षीय मामृतात् ||
*/