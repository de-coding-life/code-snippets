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
bool bfs(vector<vll> &v)
{
    int indeg[v.size()] = {0};
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            indeg[v[i][j]]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < v.size(); i++)
    {
        if (indeg[i] == 0)
            q.push(i);
    }
    int count = 0;
    while (!q.empty())
    {
        for (int i = 0; i < v[q.front()].size(); i++)
        {
            indeg[v[q.front()][i]]--;
            if (indeg[v[q.front()][i]] == 0)
                q.push(v[q.front()][i]);
        }
        q.pop();
        count++;
    }
    return (!(count == v.size()));
}
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<vll> v(n);
    fori(0, e)
    {
        int t1, t2;
        cin >> t1 >> t2;
        v[t1].pb(t2);
    }
    cout << bfs(v);
    return 0;
}