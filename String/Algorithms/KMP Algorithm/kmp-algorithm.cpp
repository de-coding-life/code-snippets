#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
// Policy Based Data Structure
// Note:Upper Bound would work as lower bound and vice versa
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;
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
int main()
{
    string s, pat;
    cin >> s >> pat;
    int m = pat.size();
    int lps[m];
    lps[0] = 0;
    for (int i = 1; i < m; i++)
    {
        int len = lps[i - 1];
        while (pat[i] != pat[len] and len != 0)
        {
            len = lps[len - 1];
        }
        if (pat[i] == pat[len])
            len++;
        lps[i] = len;
        // cout << lps[i] << endl;
    }
    int n = s.size();
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == pat[j])
        {
            j++;
            if (j == m)
            {
                cout << i - m + 1 << " ";
                j = lps[m - 1];
            }
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
                i--;
            }
        }
    }
    return 0;
}