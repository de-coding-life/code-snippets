// https://cp-algorithms.com/graph/bridge-searching.html
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

void dfs(vector<vector<int>> &adj, int timer, vector<int> &tin, vector<int> &low, vector<bool> &visited, int v, int p = -1)
{
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj[v])
    {
        if (to == p)
            continue;
        if (visited[to])
        {
            low[v] = min(low[v], tin[to]);
        }
        else
        {
            dfs(adj, timer, tin, low, visited, to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
            {
                cout << to << " " << v << endl;
            }
        }
    }
}

void find_bridges(vector<vector<int>> &v)
{
    vector<bool> visited;
    vector<int> tin, low;
    int timer;
    int n = v.size();
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(v, timer, tin, low, visited, i);
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
    find_bridges(v);
    return 0;
}