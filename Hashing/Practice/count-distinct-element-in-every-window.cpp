#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int main()
{
    int n, k;
    cin >> n >> k;
    ll a[n];
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i < k)
            mp[a[i]]++;
    }
    cout << mp.size() << " ";
    for (int i = k; i < n; i++)
    {
        mp[a[i]]++;
        mp[a[i - k]]--;
        if (mp[a[i - k]] == 0)
            mp.erase(a[i - k]);
        cout << mp.size() << " ";
    }
    return 0;
}