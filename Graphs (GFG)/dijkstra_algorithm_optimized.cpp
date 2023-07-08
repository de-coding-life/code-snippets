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
void dijkstra(vector<vector<pair<int, int>>> &v, int src)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    int dis[v.size()];
    for (int i = 1; i < v.size(); i++)
    {
        pq.push(mp(INT_MAX, i));
    }
    pq.push(mp(0, src));
    bool inmst[v.size()] = {0};
    for (int i = 0; i < v.size(); i++)
    {
        int cav = -1;
        while (!pq.empty())
        {
            if (!inmst[pq.top().second])
            {
                cav = pq.top().second;
                dis[cav] = pq.top().first;
                pq.pop();
                break;
            }
            else
            {
                pq.pop();
            }
        }
        inmst[cav] = 1;
        for (int j = 0; j < v[cav].size(); j++)
        {
            if (!inmst[v[cav][j].first])
                pq.push(mp(v[cav][j].second + dis[cav], v[cav][j].first));
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
        v[t2].pb(mp(t1, ww));
    }
    dijkstra(v, 5);
    return 0;
}