#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    for (int ii = 0; ii < t; ii++)
    {
        int n;
        cin >> n;
        ll temp;
        map<ll, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            mp[temp]++;
        }
        int ans = 0;
        for (auto i = mp.begin(); i != mp.end(); i++)
        {
            if (i->second == 1)
                ans++;
        }
        cout << ans << endl;
    }
    return 0;
}