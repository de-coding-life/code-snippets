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
void sp(vector<vll> &v, int n, int s)
{
    int vis[n] = {0};
    int dis[n];
    fori(1, n)
    {
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (!q.empty())
    {
        forj(0, v[q.front()].size())
        {
            if (vis[v[q.front()][j]] == 0)
            {
                vis[v[q.front()][j]] = 1;
                dis[v[q.front()][j]] = dis[q.front()] + 1;
                q.push(v[q.front()][j]);
            }
        }
        q.pop();
    }
    fori(0, n)
    {
        cout << dis[i] << " ";
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    for (int ii = 1; ii <= t; ii++)
    {
        // cout << "Case #" << ii << ": ";
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
        sp(v, n, 0);
    }
    return 0;
}