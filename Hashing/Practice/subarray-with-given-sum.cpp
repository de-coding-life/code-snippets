#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n, sm;
    cin >> n >> sm;
    int a[n];
    long long pre[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i > 0)
            pre[i] = a[i] + pre[i - 1];
        else
            pre[0] = a[0];
    }
    set<ll> s1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s1.find(pre[i] + sm) != s1.end() or pre[i] == sm)
        {
            cout << "YES";
            return 0;
        }
        s1.insert(pre[i]);
    }
    cout << "NO";
    return 0;
}