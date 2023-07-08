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
void dfs(vector<vector<int>> &v, int src, bool vis[], int low[], int dis[], int &cntr, stack<int> &stk, bool currstk[])
{
    dis[src] = cntr;
    low[src] = cntr;
    cntr++;
    vis[src] = 1;
    stk.push(src);
    currstk[src] = 1;
    for (int i = 0; i < v[src].size(); i++)
    {
        if (!vis[v[src][i]])
        {
            dfs(v, v[src][i], vis, low, dis, cntr, stk, currstk);
            low[src] = min(low[src], low[v[src][i]]);
        }
        else
        {
            if (currstk[v[src][i]]) // to ignore cross edges
                low[src] = min(low[src], low[v[src][i]]);
        }
    }
    if (low[src] == dis[src])
    {
        while (stk.top() != src)
        {
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << stk.top() << " ";
        stk.pop();
        cout << endl;
    }
    currstk[src] = 0;
}
void tarjan(vector<vector<int>> &v)
{
    bool vis[v.size()] = {0};
    bool currstk[v.size()] = {0};
    int low[v.size()], disc[v.size()];
    int cntr = 0;
    stack<int> stk;
    for (int i = 0; i < v.size(); i++)
    {
        if (!vis[i])
            dfs(v, i, vis, low, disc, cntr, stk, currstk);
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
    }
    tarjan(v);
    return 0;
}