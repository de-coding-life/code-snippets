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
void dfs(vector<vector<int>> &v, int src, vector<bool> &vis, stack<int> &st)
{
    if (!vis[src])
    {
        vis[src] = 1;
        for (int i = 0; i < v[src].size(); i++)
        {
            dfs(v, v[src][i], vis, st);
        }
        st.push(src);
    }
}
vector<int> dfs_all(vector<vector<int>> &v)
{
    vector<bool> vis(v.size(), 0);
    stack<int> st;
    for (int j = 0; j < v.size(); j++)
    {
        if (!vis[j])
        {
            dfs(v, j, vis, st);
        }
    }
    vector<int> ret;
    while (!st.empty())
    {
        ret.pb(st.top());
        st.pop();
    }
    return ret;
}
void kosaraju(vector<vector<int>> v)
{
    // Finish time of dfs in decreasing order
    vector<int> ans = dfs_all(v);

    // Reversing the edges
    vector<vector<int>> vnew(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            vnew[v[i][j]].pb(i);
        }
    }

    // DFS Again !!
    vector<bool> vis2(v.size(), 0);
    for (int i = 0; i < v.size(); i++)
    {
        stack<int> st;
        dfs(vnew, ans[i], vis2, st);
        if (st.empty())
            continue;
        while (!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
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
    kosaraju(v);
    return 0;
}