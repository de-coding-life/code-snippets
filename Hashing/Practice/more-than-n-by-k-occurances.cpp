#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    unordered_map<int, int> mp;
    int n, k;
    cin >> n >> k;
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        mp[temp]++;
    }
    for (auto i : mp)
    {
        if (i.second > n / k)
            cout << i.first << " ";
    }
    return 0;
}