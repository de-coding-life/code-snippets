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
// ll kpsk(vll val, vll wt, ll n, ll w) //O(2^n) // nice if w >>>>>>>>>>> n
// {
//     if (w == 0 or n == 0)
//         return 0;
//     ll ans = kpsk(val, wt, n - 1, w);
//     if (w - wt[n - 1] >= 0)
//         ans = max(kpsk(val, wt, n - 1, w - wt[n - 1]) + val[n - 1], ans);
//     return ans;
// }
int main()
{
    ll n, w;
    cin >> n >> w;
    vll val(n), wt(n);
    fori(0, n)
    {
        cin >> val[i];
    }
    fori(0, n)
    {
        cin >> wt[i];
    }
    // cout << kpsk(val, wt, n, w);
    ll dp[2][w + 1]; // O(w*n) // nice if w not >>>>>>>>>>> n
    fori(0, 2)
    {
        dp[i][0] = 0;
    }
    fori(0, w + 1)
    {
        dp[0][i] = 0;
    }
    fori(1, n + 1)
    {
        forj(1, w + 1)
        {
            dp[i % 2][j] = dp[(i - 1) % 2][j];
            if ((j - wt[(i - 1)]) >= 0)
            {
                dp[i % 2][j] = max(dp[(i - 1) % 2][j - wt[(i - 1)]] + val[(i - 1)], dp[i % 2][j]);
            }
        }
    }
    cout << dp[n % 2][w];
    return 0;
}