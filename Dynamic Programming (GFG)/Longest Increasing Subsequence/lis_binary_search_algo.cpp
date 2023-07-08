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
int jg(vector<ll> &v, ll we) // O(logn) //give sorted vector
{
    int st = 0;
    int en = v.size() - 1;
    int ans = -1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (v[mid] > we)
        {
            en = mid - 1;
            ans = mid;
        }
        else
            st = mid + 1;
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    vll q = {1, 2, 5, 5, 3, 4, 3, 5, 2, 6, 1};
    vll ans;
    ans.pb(q[0]);
    fori(1, q.size())
    {
        if (q[i] >= ans[ans.size() - 1])
            ans.pb(q[i]);
        else
        {
            ans[jg(ans, q[i])] = q[i];
        }
    }
    cout << ans.size();
    return 0;
}