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
// ll msnc(ll a[], ll n)
// {
//     if (n <= 0)
//         return 0;
//     return max(msnc(a, n - 1), msnc(a, n - 2) + a[n - 1]);
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    for (int ii = 1; ii <= t; ii++)
    {
        // cout << "Case #" << ii << ": ";
        ll n;
        cin >> n;
        ll a[n];
        fori(0, n)
        {
            cin >> a[i];
        }
        // cout << msnc(a, n);
        ll dp[n + 1];
        dp[0] = 0;
        fori(1, n + 1)
            dp[i] = max(dp[max(i - 1, 0LL)], dp[max(i - 2, 0LL)] + a[i - 1]);
        cout << dp[n];
    }
    return 0;
}