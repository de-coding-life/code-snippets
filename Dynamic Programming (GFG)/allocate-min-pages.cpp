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
ll amp(vector<ll> &v, int n, int k)
{
    if (n == 0)
    {
        return 0;
    }
    else if (k == 1)
    {
        ll sm = 0;
        fori(0, n)
            sm += v[i];
        return sm;
    }
    ll sm = 0;
    ll ans = LLONG_MAX;
    forir(n - 1, 0)
    {
        sm += v[i];
        ans = min(ans, max(amp(v, i, k - 1), sm));
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vll a(n);
    fori(0, n)
    {
        cin >> a[i];
    }
    ll dp[n + 1][k + 1];
    fori(0, k + 1)
    {
        dp[0][i] = 0;
    }
    fori(0, n + 1)
    {
        dp[i][1] = 0;
        forj(0, i)
            dp[i][1] += a[j];
    }
    forj(2, k + 1)
    {
        fori(1, n + 1)
        {
            ll sm = 0;
            dp[i][j] = LLONG_MAX;
            for (int l = i - 1; l >= 0; l--)
            {
                sm += a[l];
                dp[i][j] = min(dp[i][j], max(dp[l][j - 1], sm));
            }
        }
    }
    cout << dp[n][k];
    return 0;
}