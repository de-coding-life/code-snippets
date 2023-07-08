#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int main()
{
    int n, sm;
    cin >> n >> sm;
    ll a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<ll> s1;
    for (int i = 0; i < n; i++)
    {
        if (s1.find(sm - a[i]) != s1.end())
        {
            cout << "YES " << a[i] << " " << sm - a[i] << endl;
            return 0;
        }
        else
            s1.insert(a[i]);
    }
    cout << "NO" << endl;
    return 0;
}