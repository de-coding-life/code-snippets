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
bool gamee(int o, int e, bool win)
{
    if (o + e == 1)
        return (win);
    else if (o + e == 2)
    {
        if (o == 1 && e == 1)
            return 1;
        else if (o == 0)
            return (win);
        else
            return (!win);
    }
    bool a1 = gamee(o - 1, e - 1, !win) && gamee(o - 2, e, !win);
    bool a2 = gamee(o - 1, e - 1, win) && gamee(o, e - 2, win);
    return a1 || a2;
}
bool gameo(int o, int e, bool win)
{
    if (o + e == 1)
    {
        if (o == 1)
            return (!win);
        else
            return (win);
    }
    else if (o + e == 2)
    {
        if (o == 1 && e == 1)
            return 0;
        else if (o == 0)
            return (win);
        else
            return (!win);
    }
    bool a1 = gameo(o - 1, e - 1, !win) && gameo(o - 2, e, !win);
    bool a2 = gameo(o - 1, e - 1, win) && gameo(o, e - 2, win);
    return a1 || a2;
}
int main()
{
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        ll n;
        cin >> n;
        ll o = 0, e = 0;
        ll temp;
        fori(0, n)
        {
            cin >> temp;
            if (abs(temp) % 2 == 0)
                e++;
            else
                o++;
        }
        bool ans;
        if (n % 2 == 0)
            ans = gamee(o, e, 1);
        else
            ans = gameo(o, e, 1);
        if (ans)
            cout << "Alice\n";
        else
            cout << "Bob\n";
    }
    return 0;
}