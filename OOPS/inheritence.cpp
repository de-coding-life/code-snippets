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
//  To check existence use lower_bound
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;
#define ld long double
#define md 1000000007
const int dx[16] = {1, 0, 0, -1, 1, 1, -1, -1, 2, 2, 1, 1, -1, -1, -2, -2};
const int dy[16] = {0, -1, 1, 0, -1, 1, -1, 1, -1, 1, -2, 2, -2, 2, -1, 1};
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
#define yn(i)            \
    if (i)               \
        cout << "YES\n"; \
    else                 \
        cout << "NO\n";
#define debug(i) cout << #i << " = " << i << endl
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define hsb(i) (63 - __builtin_clzll(i))
class a
{
public:
    int cc;
    a(int aa, int bb)
    {
        cc = aa + bb;
        cout << "A constructor called\n";
    }
    ~a()
    {
        cout << "A destructor called\n";
    }
};
class b
{
public:
    int dd;
    b(int aa, int bb)
    {
        dd = aa + bb;
        cout << "B constructor called\n";
    }
    ~b()
    {
        cout << "B destructor called\n";
    }
};
class c : public a, public b
{
public:
    c(int aa, int bb) : b(aa, bb), a(aa, bb)
    {
        cout << "C constructor called\n";
    }
    ~c()
    {
        cout << "C destructor called\n";
    }
};
class d : c
{
public:
    d(int aa, int bb) : c(aa, bb)
    {
        cout << "D constructor called\n";
    }
    int getcc()
    {
        return cc;
    }
    ~d()
    {
        cout << "D destructor called\n";
    }
};
int main()
{
    d yash(2, 3);
    cout << yash.getcc() << endl;
    // cout << yash.cc << endl;
    return 0;
}
/*
|| ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृ त्योर्मुक्षीय मामृतात् ||
*/