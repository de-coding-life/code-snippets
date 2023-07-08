// disadvantage is, it will give answer even if cycle is present
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
void dfs(vector<vll> &v, int s, int vis[], stack<int> &st)
{
    if (vis[s] == 0)
    {
        vis[s] = 1;
        fori(0, v[s].size())
        {
            dfs(v, v[s][i], vis, st);
        }
        // Finish Time of DFS
        st.push(s);
    }
    return;
}
void topo(vector<vll> &v)
{
    int vis[v.size()] = {0};
    stack<int> st;
    fori(0, v.size())
    {
        if (vis[i] == 0)
        {
            dfs(v, i, vis, st);
        }
    }
    while (st.size() != 0)
    {
        cout << st.top() << " ";
        st.pop();
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n, e;
    cin >> n >> e;
    vector<vll> v(n);
    fori(0, e)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].pb(t2);
    }
    topo(v);
    return 0;
}