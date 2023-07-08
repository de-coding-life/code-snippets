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
    int ans = 0;
    set<ll> s1;
    map<int, int> mp;
    for (int i = n - 1; i >= 0; i--)
    {
        if (mp.find(pre[i]) == mp.end())
            mp[pre[i]] = i;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (pre[i] == sm)
            ans = max(ans, i + 1);
        if (s1.find(pre[i] + sm) != s1.end())
            ans = max(ans, mp[pre[i] + sm] - i);
        s1.insert(pre[i]);
    }
    cout << ans;
    return 0;
}