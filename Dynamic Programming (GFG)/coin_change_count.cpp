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
// int ccc(int sm, int a[], int n)
// {
//     if (sm < 0)
//         return INT_MAX;
//     else if (sm == 0)
//         return 0;
//     int ans = INT_MAX;
//     fori(0, n)
//         ans = min(ans, ccc(sm - a[i], a, n));
//     if (ans == INT_MAX)
//         return ans;
//     else
//         return ans + 1;
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, sm;
    cin >> n >> sm;
    int a[n];
    fori(0, n)
    {
        cin >> a[i];
    }
    int dp[sm + 1];
    dp[0] = 0;
    fori(1, sm + 1)
    {
        dp[i] = INT_MAX;
        forj(0, n)
        {
            if (i - a[j] >= 0)
                dp[i] = min(dp[i], dp[i - a[j]]);
        }
        if (dp[i] != INT_MAX)
            dp[i]++;
    }
    cout << dp[sm];
    return 0;
}