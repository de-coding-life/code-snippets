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

multiset<int> seive(int n) // doesn't include 1
{
    vector<int> ata(n + 1, 0);
    multiset<int> mtm;
    for (ll i = 2; i <= n; i++)
    {
        if (ata[i] == 0)
            mtm.insert(i);
        for (int j = i; j <= n; j += i)
            ata[j] = 1;
    }
    return mtm;
}
int main()
{
    multiset<int> ml = seive(100000);
    // iter(ml)
    // {
    //     cout << *it << " ";
    // }
    cout << ml.size();
    return 0;
}