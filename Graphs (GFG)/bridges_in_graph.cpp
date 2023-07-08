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
void dfs(vector<vector<int>> &v, int src, bool vis[], int low[], int dis[], int &cntr, int par)
{
    if (!vis[src])
    {
        dis[src] = cntr;
        low[src] = cntr;
        cntr++;
        vis[src] = 1;
        for (int i = 0; i < v[src].size(); i++)
        {
            dfs(v, v[src][i], vis, low, dis, cntr, src);
        }
        for (int i = 0; i < v[src].size(); i++)
        {
            if (v[src][i] != par)
            {
                low[src] = min(low[src], low[v[src][i]]);
            }
        }
        for (int i = 0; i < v[src].size(); i++)
        {
            if (dis[src] < low[v[src][i]])
            {
                cout << src << " " << v[src][i] << endl;
            }
        }
    }
}
void dfs_all(vector<vector<int>> &v)
{
    bool vis[v.size()] = {0};
    int low[v.size()], disc[v.size()];
    int cntr = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (!vis[i])
            dfs(v, i, vis, low, disc, cntr, 0);
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<vector<int>> v(n);
    fori(0, e)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].pb(t2);
        v[t2].pb(t1);
    }
    dfs_all(v);
    return 0;
}