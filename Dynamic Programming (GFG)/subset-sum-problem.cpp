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
int ssm(vector<ll> &v, int n, int sm)
{
    if (n == 0)
    {
        if (sm == 0)
            return 1;
        else
            return 0;
    }

    return ssm(v, n - 1, sm - v[n - 1]) + ssm(v, n - 1, sm);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, sm;
    cin >> n >> sm;
    vll a(n);
    fori(0, n)
    {
        cin >> a[i];
    }
    // cout << ssm(a, n, sm);
    ll dp[2][sm + 1];
    dp[0][0] = 1;
    fori(1, sm + 1)
    {
        dp[0][i] = 0;
    }
    // cout << dp[0][3];
    fori(1, n + 1)
    {
        forj(0, sm + 1)
        {
            dp[i % 2][j] = dp[(i - 1) % 2][j];
            if (j - a[i - 1] >= 0)
                dp[i % 2][j] += dp[(i - 1) % 2][j - a[i - 1]];
        }
        cout << endl;
    }
    cout << dp[n % 2][sm];
    return 0;
}