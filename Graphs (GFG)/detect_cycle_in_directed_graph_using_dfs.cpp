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
bool dfs(vector<vll> &v, int s, int vis[], int stk[])
{ // itna for connected
    stk[s] = 1;
    bool ans = false;
    for (int i = 0; i < v[s].size(); i++)
    {
        if (vis[v[s][i]] == 0)
        {
            vis[v[s][i]] = 1;
            ans = ans or dfs(v, v[s][i], vis, stk);
        }
        else if (stk[v[s][i]] == 1)
            return true;
    }
    stk[s] = 0;
    return ans;
}
bool dfs_dis(vector<vll> &v) // for disconnected // generally this will be necessary
{
    int n = v.size();
    int vis[n] = {0};
    int stk[n] = {0};
    bool a2 = false;
    for (int ii = 0; ii < n; ii++)
    {
        if (vis[ii] == 0)
        {
            vis[ii] = 1;
            a2 = a2 or dfs(v, ii, vis, stk);
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
    }
    cout << dfs_dis(v);
    return 0;
}