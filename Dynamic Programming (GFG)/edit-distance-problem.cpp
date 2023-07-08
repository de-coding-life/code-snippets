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
ll lcs(string a, int ea, string b, int eb)
{
    if (0 == eb)
        return ea;
    else if (0 == ea)
        return eb;
    if (a[ea - 1] == b[eb - 1])
        return (lcs(a, ea - 1, b, eb - 1));
    return min(min(lcs(a, ea - 1, b, eb), lcs(a, ea, b, eb - 1)), lcs(a, ea - 1, b, eb - 1)) + 1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    ll dp[n + 1][m + 1];
    fori(0, m + 1)
        dp[0][i] = i;
    fori(0, n + 1)
        dp[i][0] = i;
    dp[0][0] = 0;
    fori(1, n + 1)
    {
        forj(1, m + 1)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = min(min(dp[i - 1][j - 1], dp[i][j - 1]), dp[i - 1][j]) + 1;
        }
    }
    cout << dp[n][m];
    return 0;
}