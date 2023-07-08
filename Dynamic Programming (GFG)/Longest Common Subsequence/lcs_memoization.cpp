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
int memo[1001][1001];
int lcs(string a, int ea, string b, int eb)
{
    if (0 > ea or 0 > eb)
        return 0;
    if (memo[ea][eb] == -1)
    {
        if (a[ea] == b[eb])
            memo[ea][eb] = (1 + lcs(a, ea - 1, b, eb - 1));
        else
            memo[ea][eb] = max(lcs(a, ea, b, eb - 1), lcs(a, ea - 1, b, eb));
    }
    return memo[ea][eb];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    fori(0, a.size())
    {
        forj(0, b.size())
            memo[i][j] = -1;
    }
    cout << lcs(a, a.size() - 1, b, b.size() - 1);
    return 0;
}