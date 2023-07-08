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
int fib(ll n)
{
    int a[n + 1];
    a[0] = 0;
    a[1] = 1;
    fori(2, n + 1)
        a[i] = a[i - 1] + a[i - 2];
    return a[n];
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}