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
#define md 998244353
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
#define yn(i)            \
	if (i)               \
		cout << "YES\n"; \
	else                 \
		cout << "NO\n";
#define debug(i) cout << #i << " = " << i << endl
// It returns the count of numbers which are relatively prime with x in the range of 1 to m.
// Time Complexity : O(sqrt(x))
ll cn(ll x, ll m)
{
	vll primes;
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
			primes.pb(i);
		while (x % i == 0)
			x /= i;
	}
	if (x > 1)
		primes.pb(x);
	ll y = primes.size();
	ll ans = 0;
	for (int i = 1; i < powl(2, y); i++)
	{
		ll pol = 0;
		ll val = 1;
		for (int j = 0; j < y; j++)
		{
			if ((i & (1 << j)))
			{
				pol = !pol;
				val *= primes[j];
			}
		}
		if (pol == 0)
			pol = -1;
		ans += pol * (m / val);
	}
	return m - ans;
}

int main()
{
	cout << cn(3, 100) << endl;
	return 0;
}
/*
|| ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृ त्योर्मुक्षीय मामृतात् ||
*/