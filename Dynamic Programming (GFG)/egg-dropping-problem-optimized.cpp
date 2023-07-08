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
int egg(int k, int n) // O(kn^2) //Optimization available (see google)
{
    if (n == 0)
        return 0;
    if (k == 1)
        return n;
    if (n == 1)
        return 1;
    int ans = INT_MAX;
    int l = 1, r = n;
    while (l <= r) // as one is increasing , another is decreasing
    {
        int mid = (l + r) / 2;
        ans = min(ans, max(egg(k, mid - 1), egg(k - 1, n - mid)) + 1);
        if (egg(k, mid - 1) > egg(k - 1, n - mid))
            r = mid - 1;
        else
            l = mid + 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll k, n;
    cin >> k >> n;
    cout << egg(k, n);
    int dp[k + 1][n + 1]; // O(kn^2) //Optimization available (see google)
    fori(0, k + 1)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    fori(1, n + 1)
    {
        dp[1][i] = i;
    }
    fori(2, k + 1)
    {
        forj(2, n + 1)
        {
            dp[i][j] = INT_MAX;
            int l = 1, r = j;
            while (l <= r) // as one is increasing , another is decreasing
            {
                int mid = (l + r) / 2;
                dp[i][j] = min(dp[i][j], max(dp[i][mid - 1], dp[i - 1][j - mid]) + 1);
                if (dp[i][mid - 1] > dp[i - 1][j - mid])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
    }
    cout << dp[k][n];
    return 0;
}