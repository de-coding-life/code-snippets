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
// int lcs(string a, int ea, string b, int eb) // My recursion
// {
//     if (0 > ea or 0 > eb)
//         return 0;
//     for (int i = eb; i >= 0; i--)
//     {
//         if (a[ea] == b[i])
//             return max(lcs(a, ea - 1, b, i - 1) + 1, lcs(a, ea - 1, b, eb));
//     }
//     return lcs(a, ea - 1, b, eb);
// }
int lcs(string a, int ea, string b, int eb) // My recursion
{
    if (0 > ea or 0 > eb)
        return 0;
    if (a[ea] == b[eb])
        return (1 + lcs(a, ea - 1, b, eb - 1));
    else
        return max(lcs(a, ea, b, eb - 1), lcs(a, ea - 1, b, eb));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout << lcs("axzyz", 4, "bzazz", 4);
    return 0;
}