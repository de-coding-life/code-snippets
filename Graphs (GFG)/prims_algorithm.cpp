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
int prims(vector<vector<int>> &v)
{
    int ans = 0;
    int key[v.size()];
    fill(key, key + v.size(), INT_MAX);
    key[0] = 0;
    bool mst[v.size()] = {0};
    for (int cn = 0; cn < v.size(); cn++)
    {
        int cav = -1;
        for (int i = 0; i < v.size(); i++)
        {
            if ((cav == -1 or key[i] < key[cav]) && !mst[i])
                cav = i;
        }
        ans += key[cav];
        mst[cav] = 1;

        for (int i = 0; i < v.size(); i++)
        {
            if ((v[cav][i] != 0) && key[i] > v[cav][i] && !mst[i])
                key[i] = v[cav][i];
        }
    }
    return ans;
}
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            v[i].pb(0);
    }
    fori(0, e)
    {
        int t1, t2, ww;
        cin >> t1 >> t2 >> ww;
        v[t1][t2] = ww;
        v[t2][t1] = ww;
    }
    cout << prims(v);
    return 0;
}