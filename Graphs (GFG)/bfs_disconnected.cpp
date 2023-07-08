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
void bfs(vector<vll> &v, int source, int vis[])
{
    queue<ll> q;
    q.push(source);
    vis[source] = 1;
    while (q.size() != 0)
    {
        fori(0, v[q.front()].size())
        {
            if (vis[v[q.front()][i]] == 0)
            {
                vis[v[q.front()][i]] = 1;
                q.push(v[q.front()][i]);
            }
        }
        cout << q.front() << " ";
        q.pop();
    }
}
void bfs_dis(vector<vll> &v)
{
    int vis[v.size()] = {0};
    int ans = 0;
    fori(0, v.size())
    {
        if (vis[i] == 0)
        {
            ans++;
            bfs(v, i, vis);
        }
    }
    cout << endl
         << "No of connected components/islands is " << ans;
}
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<vll> adj(n);
    fori(0, e)
    {
        int t1, t2;
        cin >> t1 >> t2;
        adj[t1].pb(t2);
        adj[t2].pb(t1);
    }
    bfs_dis(adj);
    return 0;
}