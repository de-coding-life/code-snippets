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
bool dfs(vector<vll> &v, int s, int vis[], int parent)
{ // itna for connected
    bool ans = false;
    for (int i = 0; i < v[s].size(); i++)
    {
        if (vis[v[s][i]] == 0)
        {
            vis[v[s][i]] = 1;
            ans = ans or dfs(v, v[s][i], vis, s);
        }
        else if (v[s][i] != parent)
            return true;
    }
    return ans;
}
bool dfs_dis(vector<vll> &v) // for disconnected
{
    int n = v.size();
    int vis[n] = {0};
    bool a2 = false;
    for (int ii = 0; ii < n; ii++)
    {
        if (vis[ii] == 0)
        {
            vis[ii] = 1;
            a2 = a2 or dfs(v, ii, vis, 0);
        }
    }
    return a2;
}
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<vll> v(n);
    fori(0, e)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].pb(t2);
        v[t2].pb(t1);
    }
    cout << dfs_dis(v);
    return 0;
}