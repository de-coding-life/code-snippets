/*
|| ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृ त्योर्मुक्षीय मामृतात् ||
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#include <ext/pb_ds/assoc_container.hpp>
// Policy Based Data Structure
// Note:Upper Bound would work as lower bound and vice versa
//  Find won't work in less_equal, so use find_by_order(order_of_key(a[i]))
//  OR store pairs in less
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;
#define ld long double
#define md 1000000007
#define vll vector<ll>
#define v2(dt, name, n, m, ini) vector<vector<dt>> name(n, vector<dt>(m, ini))
#define pll pair<ll, ll>
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define endl "\n"
#define fori(i, xx, yy) for (int i = xx; i < yy; i++)
#define forl(i, xx, yy) for (ll i = xx; i < yy; i++)
#define forir(i, xx, yy) for (int i = xx; i >= yy; i--)
#define forlr(i, xx, yy) for (ll j = xx; j >= yy; j--)
#define all(i) i.begin(), i.end()
#define iter(zz) for (auto it = zz.begin(); it != zz.end(); it++)
vll div(ll n)
{
    if (n == 0)
        return {0};
    vll ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.pb(i);
            if ((n / i) != i)
                ans.pb(n / i);
        }
    }
    return ans;
}
vector<vll> div1ton(ll n)
{
    vector<vll> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
        {
            v[j].pb(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        reverse(all(v[i]));
    }
    return v;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int ii = 1; ii <= t; ii++)
    {
        int n;
        cin >> n;
        vll a = div(n);
        for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
        cout << endl;
    }
    return 0;
}
/*
|| ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृ त्योर्मुक्षीय मामृतात् ||
*/