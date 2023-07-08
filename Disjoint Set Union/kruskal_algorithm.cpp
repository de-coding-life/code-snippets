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
class dsu
{
public:
    int n;
    vector<int> par, rank;
    dsu(int nn)
    {
        n = nn;
        for (int i = 0; i < nn; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }
    int find(int x)
    {
        if (par[x] == x)
            return x;
        par[x] = find(par[x]);
        return par[x];
    }
    void unio(int a, int b)
    {
        int ra = find(a);
        int rb = find(b);
        if (ra == rb)
            return;
        if (rank[ra] > rank[rb])
            par[rb] = ra;
        else if (rank[ra] < rank[rb])
            par[ra] = rb;
        else
        {
            par[rb] = ra;
            rank[ra]++;
        }
    }
};
int kruskal(vector<vector<pair<int, int>>> &v)
{
    int ans = 0;
    vector<pair<int, pair<int, int>>> edg;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            edg.pb({v[i][j].second, {i, v[i][j].first}});
        }
    }
    sort(edg.begin(), edg.end());
    bool mst[v.size()] = {0};

    dsu my(v.size());
    for (int i = 0; i < edg.size(); i++)
    {
        if (my.find(edg[i].second.first) != my.find(edg[i].second.second))
        {
            ans += edg[i].first;
            my.unio(edg[i].second.first, edg[i].second.second);
        }
    }
    return ans;
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
        v[t1].pb({t2, ww});
        v[t2].pb({t1, ww});
    }
    cout << kruskal(v);
    return 0;
}