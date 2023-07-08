#include <bits/stdc++.h>
using namespace std;
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
ll sub(ll a[], ll n, ll sm) // my soln would work on both neg and positive
{
    if (n == 0)
        return 0;
    int ans = 0;
    if ((sm - a[n - 1]) == 0)
        ans++;
    ans += sub(a, n - 1, sm - a[n - 1]) + sub(a, n - 1, sm);
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, sm;
    cin >> n >> sm;
    ll a[n];
    fori(0, n)
    {
        cin >> a[i];
    }
    cout << sub(a, n, sm);
    return 0;
}