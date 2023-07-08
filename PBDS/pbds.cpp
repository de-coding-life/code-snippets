#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T>
// Note:Upper Bound would work as lower bound and vice versa
//  Find won't work in less_equal, so use find_by_order(order_of_key(a[i]))
//  OR store pairs in less
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
    pbds<ll> a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.insert(5);
    a.insert(3);
    a.insert(2);
    // All Default Multiset functions would work except find
    // never directly use x.erase(val)

    // Roles of UB and LB switch
    cout << *a.lower_bound(2) << endl;
    cout << *a.upper_bound(2) << endl;

    // Find by order in log(n) time
    cout << *a.find_by_order(6) << endl;
    cout << *a.find_by_order(0) << endl;

    // Order of key in log(n) time
    cout << a.order_of_key(1) << endl;
    cout << a.order_of_key(3) << endl; // Giving First Occurence

    return 0;
}