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
vector<int> z(string s) // compares the length of string starting at index i with string starting at index 0
{
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            z[i]++;
        if (r < i + z[i])
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    for (int ii = 1; ii <= t; ii++)
    {
        string s;
        cin >> s;
        vector<int> v = z(s);
        for (int i = 0; i < s.size(); i++)
        {
            cout << v[i] << " ";
        }
    }
    return 0;
}
/*
|| ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृ त्योर्मुक्षीय मामृतात् ||
*/