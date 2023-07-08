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
// int coin(vector<ll> &arr, int i, int j, int sm)
// {
//     if (i == j)
//         return arr[i];
//     else if (j - i == 1)
//         return max(arr[i], arr[j]);
//     return max(sm - coin(arr, i + 1, j, sm - arr[i]), sm - coin(arr, i, j - 1, sm - arr[j]));
// }
int coin(vector<ll> &arr, int i, int j)
{
    if (i == j)
        return arr[i];
    else if (j - i == 1)
        return max(arr[i], arr[j]);
    return max(arr[i] + min(coin(arr, i + 2, j), coin(arr, i + 1, j - 1)), arr[j] + min(coin(arr, i + 1, j - 1), coin(arr, i, j - 2)));
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
    // cout << coin(a, 0, n - 1, 27);
    ll dp[n][n];
    fori(0, n)
        dp[i][i] = a[i];
    fori(0, n - 1)
        dp[i][i + 1] = max(a[i], a[i + 1]);
    fori(2, n)
    {
        forj(0, n - i)
        {
            dp[j][j + i] = max(a[j] + min(dp[j + 2][j + i], dp[j + 1][i + j - 1]), a[j + i] + min(dp[j + 1][i + j - 1], dp[j][i + j - 2]));
        }
    }
    cout << dp[0][n - 1];

    return 0;
}