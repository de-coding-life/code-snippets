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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tt = 1;
    cin >> tt;
    for (int ii = 1; ii <= tt; ii++)
    {

        ll n, m;
        cin >> n >> m;
        vll a(n), t(m);
        map<ll, ll> mpp;
        multiset<ll, greater<ll>> my;
        fori(0, n)
        {
            cin >> a[i];
            mpp[a[i]]++;
        }
        for (auto i : mpp)
        {
            my.insert(i.second);
        }
        fori(0, m)
        {
            cin >> t[i];
        }
        ll ans = 0;
        sort(t.begin(), t.end());
        for (int i = m - 1; i >= 0; i--)
        {
            if (my.size() == 0)
                break;
            ll temp = *my.begin();
            if (temp <= t[i])
            {
                ans += temp;
                my.erase(my.begin());
            }
            else
            {
                ans += t[i];
                my.erase(my.begin());
                my.insert(temp - t[i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}