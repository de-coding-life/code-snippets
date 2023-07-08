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
#define fori(xx, yy) for (auto i = xx; i < yy; i++)
#define forj(xx, yy) for (auto j = xx; j < yy; j++)
#define fork(xx, yy) for (auto k = xx; k < yy; k++)
#define forir(xx, yy) for (auto i = xx; i >= yy; i--)
#define forjr(xx, yy) for (auto j = xx; j >= yy; j--)
#define forkr(xx, yy) for (auto k = xx; k >= yy; k--)
#define iter(zz) for (auto it = zz.begin(); it != zz.end(); it++)
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int ii = 1; ii <= t; ii++)
    {
        // cout << "Case #" << ii << ": ";
        ll n;
        cin >> n;
        vll a(n);
        fori(0, n)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        ll ans = 0;
        fori(0, n)
            ans += min((n - i), n - 1) * a[i];
        cout << ans << endl;
    }
    return 0;
}