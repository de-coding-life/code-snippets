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
void topo(vector<vector<pair<int, int>>> &v, vector<int> &ans)
{
    queue<int> q;
    vector<int> indeg(v.size());
    for (int i = 0; i < v.size(); i++)
    {
        indeg[i] = 0;
    }
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            indeg[v[i][j].first]++;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    while (!q.empty())
    {
        for (int i = 0; i < v[q.front()].size(); i++)
        {
            indeg[v[q.front()][i].first]--;
            if (indeg[v[q.front()][i].first] == 0)
            {
                q.push(v[q.front()][i].first);
            }
        }
        ans.push_back(q.front());
        q.pop();
    }
}
void short_path(vector<vector<pair<int, int>>> &v, int s)
{
    int dis[v.size()];
    for (int i = 0; i < v.size(); i++)
    {
        dis[i] = INT_MAX;
    }
    dis[s] = 0;
    vector<int> top;
    topo(v, top);
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[top[i]].size(); j++)
        {
            if (dis[v[top[i]][j].first] > dis[top[i]] + v[top[i]][j].second && dis[top[i]] != INT_MAX)
                dis[v[top[i]][j].first] = dis[top[i]] + v[top[i]][j].second;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << top[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < v.size(); i++)
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
        vector<vector<pair<int, int>>> v(n);

        fori(0, e)
        {
            int t1, t2, ww;
            cin >> t1 >> t2 >> ww;
            v[t1].push_back(make_pair(t2, ww));
        }
        short_path(v, 1);
    }
    return 0;
}