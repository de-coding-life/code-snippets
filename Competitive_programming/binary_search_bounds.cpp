#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define md 1000000007
int jse(vector<ll> &v, ll we) // O(logn) //give sorted vector
{
    int st = 0;
    int en = v.size() - 1;
    int ans = -1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (v[mid] <= we)
        {
            st = mid + 1;
            ans = mid;
        }
        else
            en = mid - 1;
    }
    return ans;
}
int js(vector<ll> &v, ll we) // O(logn) //give sorted vector
{
    int st = 0;
    int en = v.size() - 1;
    int ans = -1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (v[mid] < we)
        {
            st = mid + 1;
            ans = mid;
        }
        else
            en = mid - 1;
    }
    return ans;
}
int jge(vector<ll> &v, ll we) // O(logn) //give sorted vector
{
    int st = 0;
    int en = v.size() - 1;
    int ans = -1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (v[mid] >= we)
        {
            en = mid - 1;
            ans = mid;
        }
        else
            st = mid + 1;
    }
    return ans;
}
int jg(vector<ll> &v, ll we) // O(logn) //give sorted vector
{
    int st = 0;
    int en = v.size() - 1;
    int ans = -1;
    while (st <= en)
    {
        int mid = (st + en) / 2;
        if (v[mid] > we)
        {
            en = mid - 1;
            ans = mid;
        }
        else
            st = mid + 1;
    }
    return ans;
}
int main()
{
    vector<ll> v = {1, 2, 4, 5};
    cout << v[js(v, 3)];
    return 0;
}