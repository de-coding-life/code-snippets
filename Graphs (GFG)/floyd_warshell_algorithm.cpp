// Finds shortest distance bw every pair of vertices
// Time Complexity is O(V^3)
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
void floyd(vector<vector<int>> &v)
{
    int n = v.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v[i][k] != 1e9 and v[k][j] != 1e9)
                    v[i][j] = min(v[i][j], v[i][k] + v[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j] == 1e9)
            {
                cout << "X ";
                continue;
            }
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    ll n, e;
    cin >> n >> e;
    vector<vector<int>> v(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                v[i].pb(0);
            else
                v[i].pb(1e9);
        }
    }
    fori(0, e)
    {
        int t1, t2, ww;
        cin >> t1 >> t2 >> ww;
        v[t1][t2] = ww;
    }
    floyd(v);
    return 0;
}