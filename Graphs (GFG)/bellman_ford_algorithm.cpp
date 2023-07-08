// Advantage over dijkstra is that it can handle negative edges
// Time Complexity is O(VE)
// IT IS DP BASED
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
void bellman(vector<vector<pair<int, int>>> &v, int src)
{
    int dis[v.size()];
    for (int i = 0; i < v.size(); i++)
    {
        dis[i] = INT_MAX;
    }
    dis[src] = 0;
    for (int cn = 0; cn < v.size() - 1; cn++)
    {
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j < v[i].size(); j++)
            {
                if (dis[i] != INT_MAX)
                    dis[v[i][j].first] = min(dis[v[i][j].first], dis[i] + v[i][j].second);
            }
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << i << " -> " << dis[i] << endl;
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<vector<pair<int, int>>> v(n);
    fori(0, e)
    {
        int t1, t2, ww;
        cin >> t1 >> t2 >> ww;
        v[t1].pb(mp(t2, ww));
    }
    bellman(v, 1);
    return 0;
}