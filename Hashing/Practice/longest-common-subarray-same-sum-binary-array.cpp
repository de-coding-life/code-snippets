#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int prea[n], preb[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i == 0)
            prea[0] = a[0];
        else
            prea[i] = prea[i - 1] + a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        if (i == 0)
            preb[0] = b[0];
        else
            preb[i] = preb[i - 1] + b[i];
    }
    int pre[n];
    for (int i = 0; i < n; i++)
        pre[i] = prea[i] - preb[i];
    map<int, int> mp;
    int ans = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (pre[i] == 0)
            ans = max(ans, i + 1);
        if (mp.find(pre[i]) != mp.end())
            ans = max(ans, mp[pre[i]] - i);
        else
            mp[pre[i]] = i;
    }
    cout << ans << endl;
    return 0;
}