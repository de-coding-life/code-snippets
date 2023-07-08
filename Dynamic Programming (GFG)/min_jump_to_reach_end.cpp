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
// int mj(int n, int a[], int k) //My approach
// {
//     if (n - 1 == k)
//         return 0;
//     int ans = INT_MAX;
//     fori(k + 1, min(n, k + a[k] + 1))
//         ans = min(ans, mj(n, a, i));
//     return ans + 1;
// }
int main()
{
    ll n;
    cin >> n;
    int a[n];
    fori(0, n)
    {
        cin >> a[i];
    }
    int dp[n];
    dp[n - 1] = 0;
    forir(n - 2, 0)
    {
        dp[i] = INT_MAX;
        forj(i + 1, min(n, i + a[i] + 1))
            dp[i] = min(dp[i], dp[j]);
        dp[i]++;
    }
    cout << dp[0];
    return 0;
}