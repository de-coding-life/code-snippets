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
class fenwick
{
public:
    int n;
    vll a;
    vll v;
    fenwick(vll in)
    {
        n = in.size();
        a.resize(n + 1);
        fill(a.begin(), a.end(), 0);
        v = a;
        for (int i = 0; i < n; i++)
        {
            update(i, in[i]);
        }
    }
    void update(int i, ll x)
    {
        int ind = i;
        i++;
        while (i <= n)
        {
            a[i] = a[i] + (x - v[ind]);
            i += i & -i;
        }
        v[ind] = x;
    }
    ll presum(int i)
    {
        ll ans = 0;
        i++;
        while (i >= 1)
        {
            ans += a[i];
            i -= i & -i;
        }
        return ans;
    }
};
int main()
{
    fenwick ft({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
    cout << ft.presum(5) << endl;
    ft.update(2, 10);
    cout << ft.presum(5);
    return 0;
}