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
class seg_tree
{
public:
    int n;
    vector<ll> tr;
    seg_tree(int n, vector<ll> v)
    {
        for (int i = 0; i < 4 * n; i++)
        {
            tr.push_back(-1);
        }
        this->n = n;
        init(0, n - 1, 0, v);
    }
    ll init(int s, int e, int ci, vector<ll> &v)
    {
        if (s == e)
        {
            tr[ci] = v[s];
            return tr[ci];
        }
        int mid = (s + e) / 2;
        tr[ci] = init(s, mid, (2 * ci) + 1, v) + init(mid + 1, e, (2 * ci) + 2, v);
        return tr[ci];
    }
    ll getsum(int qs, int qe, int s = 0, int e = -1, int ci = 0)
    {
        if (e == -1)
            e = n - 1;
        if (qs > e or qe < s)
            return 0;
        else if (qs <= s and e <= qe)
            return tr[ci];
        int mid = (s + e) / 2;
        return getsum(qs, qe, s, mid, 2 * ci + 1) + getsum(qs, qe, mid + 1, e, 2 * ci + 2);
    }
    ll update(int ind, ll dat, int s = 0, int e = -1, int ci = 0)
    {
        if (e == -1)
            e = n - 1;
        if (s == e)
        {
            tr[ci] = dat;
            return dat;
        }
        int mid = (s + e) / 2;
        if (ind <= mid)
            tr[ci] = tr[ci] - tr[2 * ci + 1] + update(ind, dat, s, mid, 2 * ci + 1);
        else
            tr[ci] = tr[ci] - tr[2 * ci + 2] + update(ind, dat, mid + 1, e, 2 * ci + 2);
        return tr[ci];
    }
};
int main()
{
    seg_tree sg(5, {1, 2, 3, 4, 5});
    cout << sg.getsum(2, 3) << endl;
    sg.update(0, 100);
    cout << sg.getsum(0, 1) << endl;
    sg.update(2, 100);
    cout << sg.getsum(2, 3) << endl;
    return 0;
}