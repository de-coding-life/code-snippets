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

// int lcs(vll &a, int ea, int mx) //My recursion
// {
//     if (ea == 0)
//         return 0;
//     int ans = -1;
//     if (mx >= a[ea - 1])
//         ans = lcs(a, ea - 1, a[ea - 1]) + 1;
//     return max(ans, lcs(a, ea - 1, mx));
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vll v = {1, 2, 3, 4, 3, 2, 1, 5};
    int dp[v.size()];
    int ans = 1;
    fori(0, v.size())
    {
        dp[i] = 1;
        forj(0, i)
        {
            if (v[i] >= v[j])
                dp[i] = max(dp[i], dp[j] + 1);
        }
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}