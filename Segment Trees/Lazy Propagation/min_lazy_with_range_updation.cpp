#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
// less_than <-> greater than
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
// Find Min Segment tree with Range Update using Lazy
class seg_tree
{
public:
	int n;
	vector<ll> tr, lazy;
	seg_tree(vector<ll> v)
	{
		n = v.size();
		tr.resize(4 * n, 0);
		lazy.resize(4 * n, 0);
		for (int i = 0; i < n; i++)
			update(i, i, v[i]);
	}
	//** Danger - Change propagate, if change in type of updates **
	void propagate(int s, int e, int ci)
	{
		if (lazy[ci] == 0)
			return;
		if (s != e)
		{
			lazy[2 * ci + 1] = lazy[ci];
			lazy[2 * ci + 2] = lazy[ci];
		}
		tr[ci] = lazy[ci];
		lazy[ci] = 0;
	}
	ll getmin(int qs, int qe, int s = 0, int e = -1, int ci = 0)
	{
		if (e == -1)
			e = n - 1;
		//** Danger - Change return, if change in type of updates **
		if (qs > e or qe < s)
			return LLONG_MAX;
		else if (qs <= s and e <= qe)
		{
			propagate(s, e, ci);
			return tr[ci];
		}
		propagate(s, e, ci);
		int mid = (s + e) / 2;
		//** Danger - Change this, if change in type of updates **
		return min(getmin(qs, qe, s, mid, 2 * ci + 1), getmin(qs, qe, mid + 1, e, 2 * ci + 2));
	}
	ll update(int qs, int qe, ll dat, int s = 0, int e = -1, int ci = 0)
	{
		if (e == -1)
			e = n - 1;
		propagate(s, e, ci);
		if (qs > e or qe < s)
			return tr[ci];
		else if (qs <= s and e <= qe)
		{
			//** Danger - Change this, if change in type of updates **
			lazy[ci] = dat;
			propagate(s, e, ci);
			return tr[ci];
		}
		int mid = (s + e) / 2;
		//** Danger - Change this, if change in type of updates **
		tr[ci] = min(update(qs, qe, dat, s, mid, 2 * ci + 1), update(qs, qe, dat, mid + 1, e, 2 * ci + 2));
		return tr[ci];
	}
};
int main()
{
	seg_tree sg({5, 1, 2, 3, 4});
	cout << sg.getmin(2, 4) << endl;
	sg.update(0, 4, 1);
	sg.update(0, 3, 2);
	sg.update(0, 2, 3);
	sg.update(0, 1, 4);
	sg.update(0, 0, 5);
	cout << sg.getmin(0, 0) << endl;
	cout << sg.getmin(1, 1) << endl;
	cout << sg.getmin(2, 2) << endl;
	cout << sg.getmin(3, 3) << endl;
	cout << sg.getmin(4, 4) << endl;
	return 0;
}