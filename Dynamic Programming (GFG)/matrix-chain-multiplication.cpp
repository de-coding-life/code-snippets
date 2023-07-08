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
ll mcm(vector<ll> &v, int s, int e)
{
    if (e - s == 1)
        return 0;
    ll ans = LLONG_MAX;
    for (int i = s + 1; i <= e - 1; i++)
    {
        ans = min(ans, mcm(v, s, i) + mcm(v, i, e) + (v[s - 1] * v[i - 1] * v[e - 1]));
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vll a(n);
    fori(0, n)
    {
        cin >> a[i];
    }
    // cout << mcm(a, 1, n);
    ll dp[n + 1][n + 1];
    fori(0, n)
    {
        dp[i][i + 1] = 0;
    }
    fori(2, n)
    {
        forj(1, n - i + 1)
        {
            dp[j][j + i] = INT_MAX;
            fork(j + 1, j + i)
            {
                dp[j][j + i] = min(dp[j][j + i], dp[j][k] + dp[k][i + j] + (a[j - 1] * a[k - 1] * a[j + i - 1]));
            }
        }
    }
    cout << dp[1][n];
    return 0;
}