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
// bool pall(string sts, int i, int j)
// {
//     for (int qq = i; qq <= j; qq++)
//     {
//         if (sts[qq] != sts[j + i - qq])
//             return 0;
//     }
//     return 1;
// }
// int pp(string &v, int j)  // O(n^3) in dp //if i optimize pallindrome then n^2 , use seperate dp for pall
// {
//     if (pall(v, 1, j))
//         return 0;
//     int ans = INT_MAX;
//     for (int i = j; i > 1; i--)
//     {
//         if (pall(v, i, j))
//             ans = min(pp(v, i - 1), ans);
//     }
//     return ans + 1;
// }
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    // cout << pp(s, s.size() - 1);
    bool pall[n + 1][n + 1]; // checking every substring for pallindrome in just O(n^2) //Is'nt this just cool
    fori(0, n + 1)
    {
        pall[i][i] = 1;
    }
    fori(1, n)
    {
        forj(1, n - i + 1)
        {
            pall[j][j + i] = (s[j - 1] == s[j + i - 1]) && (i == 1 or pall[j + 1][i + j - 1]);
        }
    }
    int dp[n + 1];
    fori(0, n + 1)
    {
        if (pall[1][i])
            dp[i] = 0;
        else
        {
            dp[i] = INT_MAX;
            forjr(i, 2)
            {
                if (pall[j][i])
                    dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    cout << dp[n];
    /*

    Overall Time Complexity is O(n^2)
            Space Complexity is O(n^2)

    */
    return 0;
}